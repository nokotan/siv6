﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/DLL.hpp>
# include <Siv3D/Window.hpp>
# include <Siv3D/EngineLog.hpp>
# include "D3D11BackBuffer.hpp"

namespace s3d
{
	D3D11BackBuffer::D3D11BackBuffer(const D3D11Device& device, const D3D11SwapChain& swapChain)
		: m_device(device.getDevice())
		, m_context(device.getContext())
		, m_swapChain1(swapChain.getSwapChain1())
	{
		LOG_SCOPED_TRACE(U"D3D11BackBuffer::D3D11BackBuffer()");

		m_backBuffer	= D3D11InternalTexture2D::GetTextureFromSwapChain(m_device, m_swapChain1);

		m_sceneSize		= Window::GetState().virtualSize;

		m_sceneBuffers =
		{
			.scene = D3D11InternalTexture2D::CreateRenderTargetTexture2D(m_device, m_sceneSize, m_sampleCount)
		};

		clear(ClearTarget::All);
	}

	D3D11BackBuffer::~D3D11BackBuffer()
	{

	}

	void D3D11BackBuffer::clear(const ClearTarget clearTargets)
	{
		if (clearTargets & ClearTarget::BackBuffer)
		{
			m_backBuffer.clear(m_context, m_letterboxColor);
		}

		if ((clearTargets & ClearTarget::Scene))
		{
			m_sceneBuffers.scene.clear(m_context, m_backgroundColor);
		}
	}

	void D3D11BackBuffer::updateFromSceneBuffer()
	{
		unbindAllRenderTargets();

		if (m_sampleCount == 1)
		{
			if (m_backBuffer.getSize() == m_sceneBuffers.scene.getSize())
			{
				m_sceneBuffers.scene.copyTo(m_context, m_backBuffer);
			}
			else
			{
				setRenderTarget(m_backBuffer);
				m_context->PSSetShaderResources(0, 1, m_sceneBuffers.scene.getSRVPtr());

				if (m_sceneTextureFilter == TextureFilter::Nearest)
				{
					// [Siv3D ToDo] Draw Nearest
				}
				else // (m_sceneTextureFilter == TextureFilter::Linear)
				{
					// [Siv3D ToDo] Draw Linear
				}
			}

			D3D11::ResetPSShaderResources(m_context);
			return;
		}

		if (m_backBuffer.getSize() == m_sceneBuffers.scene.getSize())
		{
			m_sceneBuffers.scene.resolveTo(m_context, m_backBuffer);
		}
		else
		{
			if (m_sceneTextureFilter == TextureFilter::Nearest)
			{
				setRenderTarget(m_backBuffer);
				m_context->PSSetShaderResources(0, 1, m_sceneBuffers.scene.getSRVPtr());

				// [Siv3D ToDo] Draw MSAA
			}
			else // (m_sceneTextureFilter == TextureFilter::Linear)
			{
				if (m_sceneBuffers.resolved.getSize() != m_sceneBuffers.scene.getSize())
				{
					m_sceneBuffers.resolved = D3D11InternalTexture2D::CreateRenderTargetTexture2D(m_device, m_sceneSize);
				}
				m_sceneBuffers.scene.resolveTo(m_context, m_sceneBuffers.resolved);

				setRenderTarget(m_backBuffer);
				m_context->PSSetShaderResources(0, 1, m_sceneBuffers.resolved.getSRVPtr());
				// [Siv3D ToDo] Draw Linear
			}

			D3D11::ResetPSShaderResources(m_context);
		}
	}

	void D3D11BackBuffer::setLetterboxColor(const ColorF& color) noexcept
	{
		m_letterboxColor = color;
	}

	const ColorF& D3D11BackBuffer::getLetterBoxColor() const noexcept
	{
		return m_letterboxColor;
	}

	void D3D11BackBuffer::setBackgroundColor(const ColorF& color) noexcept
	{
		m_backgroundColor = color;
	}

	const ColorF& D3D11BackBuffer::getBackgroundColor() const noexcept
	{
		return m_backgroundColor;
	}

	void D3D11BackBuffer::setSceneTextureFilter(const TextureFilter textureFilter) noexcept
	{
		m_sceneTextureFilter = textureFilter;
	}

	TextureFilter D3D11BackBuffer::getSceneTextureFilter() const noexcept
	{
		return m_sceneTextureFilter;
	}

	void D3D11BackBuffer::setSceneResizeMode(const ResizeMode resizeMode)
	{
		m_sceneResizeMode = resizeMode;

		updateSceneSize();
	}

	ResizeMode D3D11BackBuffer::getSceneResizeMode() const noexcept
	{
		return m_sceneResizeMode;
	}

	void D3D11BackBuffer::setSceneBufferSize(const Size size)
	{
		assert((0 < size.x) && (0 < size.y));

		if (size == m_sceneSize)
		{
			return;
		}

		LOG_TRACE(U"D3D11BackBuffer::setSceneSize({})"_fmt(size));

		unbindAllRenderTargets();

		m_sceneSize = size;

		m_sceneBuffers = {};

		m_sceneBuffers =
		{
			.scene = D3D11InternalTexture2D::CreateRenderTargetTexture2D(m_device, m_sceneSize, m_sampleCount)
		};

		clear(ClearTarget::All);
	}

	const Size& D3D11BackBuffer::getSceneBufferSize() const
	{
		return m_sceneSize;
	}

	void D3D11BackBuffer::setBackBufferSize(const Size backBufferSize)
	{
		assert((0 < backBufferSize.x) && (0 < backBufferSize.y));

		LOG_TRACE(U"D3D11BackBuffer::setBackBufferSize({})"_fmt(backBufferSize));

		unbindAllRenderTargets();

		m_backBuffer.reset();
		{
			DXGI_SWAP_CHAIN_DESC1 desc = {};
			m_swapChain1->GetDesc1(&desc);
			if (FAILED(m_swapChain1->ResizeBuffers(desc.BufferCount, backBufferSize.x, backBufferSize.y, desc.Format, desc.Flags)))
			{
				throw EngineError(U"IDXGISwapChain1->ResizeBuffers() failed");
			}

			m_backBuffer = D3D11InternalTexture2D::GetTextureFromSwapChain(m_device, m_swapChain1);
		}

		updateSceneSize();
	}

	const Size& D3D11BackBuffer::getBackBufferSize() const
	{
		return m_backBuffer.getSize();
	}

	void D3D11BackBuffer::unbindAllRenderTargets()
	{
		m_context->OMSetRenderTargets(0, nullptr, nullptr);
	}

	void D3D11BackBuffer::updateSceneSize()
	{
		if (m_sceneResizeMode == ResizeMode::Actual)
		{
			setSceneBufferSize(Window::GetState().frameBufferSize);
		}
		else if (m_sceneResizeMode == ResizeMode::Virtual)
		{
			setSceneBufferSize(Window::GetState().virtualSize);
		}
	}

	void D3D11BackBuffer::setRenderTarget(const D3D11InternalTexture2D& texture)
	{
		assert(not texture.isEmpty());

		ID3D11RenderTargetView* pRTV[1] =
		{
			texture.getRTV()
		};

		m_context->OMSetRenderTargets(static_cast<UINT>(std::size(pRTV)), std::data(pRTV), nullptr);
	}
}
