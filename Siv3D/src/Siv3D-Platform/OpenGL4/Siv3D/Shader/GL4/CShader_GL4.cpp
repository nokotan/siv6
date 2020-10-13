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

# include "CShader_GL4.hpp"
# include <Siv3D/TextReader.hpp>
# include <Siv3D/Error.hpp>
# include <Siv3D/EngineLog.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>

namespace s3d
{
	CShader_GL4::CShader_GL4()
	{

	}

	CShader_GL4::~CShader_GL4()
	{
		LOG_SCOPED_TRACE(U"CShader_GL4::~CShader_GL4()");
		m_pixelShaders.destroy();
		m_vertexShaders.destroy();
	}

	void CShader_GL4::init()
	{
		LOG_SCOPED_TRACE(U"CShader_GL4::~init()");

		// null VS を管理に登録
		{
			// null VS を作成
			auto nullVertexShader = std::make_unique<GL4VertexShader>(GL4VertexShader::Null{});

			if (!nullVertexShader->isInitialized()) // もし作成に失敗していたら
			{
				throw EngineError(U"Null VertexShader initialization failed");
			}

			// 管理に登録
			m_vertexShaders.setNullData(std::move(nullVertexShader));
		}

		// null PS を管理に登録
		{
			// null PS を作成
			auto nullPixelShader = std::make_unique<GL4PixelShader>(GL4PixelShader::Null{});

			if (!nullPixelShader->isInitialized()) // もし作成に失敗していたら
			{
				throw EngineError(U"Null PixelShader initialization failed");
			}

			// 管理に登録
			m_pixelShaders.setNullData(std::move(nullPixelShader));
		}
	}

	VertexShader::IDType CShader_GL4::createVS(Blob&& binary, const Array<ConstantBufferBinding>& bindings)
	{
		// [Siv3D ToDo]
		return VertexShader::IDType::NullAsset();
	}

	VertexShader::IDType CShader_GL4::createVS(const FilePathView path, const Array<ConstantBufferBinding>& bindings)
	{
		TextReader reader(path);

		if (not reader)
		{
			return VertexShader::IDType::NullAsset();
		}

		return createVSFromSource(reader.readAll(), bindings);
	}

	VertexShader::IDType CShader_GL4::createVSFromSource(const String& source, const Array<ConstantBufferBinding>& bindings)
	{
		// VS を作成
		auto vertexShader = std::make_unique<GL4VertexShader>(source, bindings);

		if (!vertexShader->isInitialized()) // もし作成に失敗していたら
		{
			return VertexShader::IDType::NullAsset();
		}

		// VS を管理に登録
		return m_vertexShaders.add(std::move(vertexShader));
	}

	PixelShader::IDType CShader_GL4::createPS(Blob&& binary, const Array<ConstantBufferBinding>& bindings)
	{
		// [Siv3D ToDo]
		return PixelShader::IDType::NullAsset();
	}

	PixelShader::IDType CShader_GL4::createPS(const FilePathView path, const Array<ConstantBufferBinding>& bindings)
	{
		TextReader reader(path);

		if (not reader)
		{
			return PixelShader::IDType::NullAsset();
		}

		return createPSFromSource(reader.readAll(), bindings);
	}

	PixelShader::IDType CShader_GL4::createPSFromSource(const String& source, const Array<ConstantBufferBinding>& bindings)
	{
		// PS を作成
		auto pixelShader = std::make_unique<GL4PixelShader>(source, bindings);

		if (!pixelShader->isInitialized()) // もし作成に失敗していたら
		{
			return PixelShader::IDType::NullAsset();
		}

		// PS を管理に登録
		return m_pixelShaders.add(std::move(pixelShader));
	}

	void CShader_GL4::releaseVS(const VertexShader::IDType handleID)
	{
		// 指定した VS を管理から除外
		m_vertexShaders.erase(handleID);
	}

	void CShader_GL4::releasePS(const PixelShader::IDType handleID)
	{
		// 指定した PS を管理から除外
		m_pixelShaders.erase(handleID);
	}

	const Blob& CShader_GL4::getBinaryVS(const VertexShader::IDType handleID)
	{
		return m_vertexShaders[handleID]->getBinary();
	}

	const Blob& CShader_GL4::getBinaryPS(const PixelShader::IDType handleID)
	{
		return m_pixelShaders[handleID]->getBinary();
	}

	GLuint CShader_GL4::getVSProgram(const VertexShader::IDType handleID)
	{
		return m_vertexShaders[handleID]->getProgram();
	}

	GLuint CShader_GL4::getPSProgram(const PixelShader::IDType handleID)
	{
		return m_pixelShaders[handleID]->getProgram();
	}

	void CShader_GL4::setPSSamplerUniform(const PixelShader::IDType handleID)
	{
		m_pixelShaders[handleID]->setPSSamplerUniform();
	}
}
