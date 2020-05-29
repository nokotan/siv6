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

# include <Siv3D/Error.hpp>
# include <Siv3D/EngineLog.hpp>
# include <Siv3D/DLL.hpp>
# include "CWindow_Null.hpp"
# include "DPIAwareness.hpp"

namespace s3d
{
	CWindow_Null::CWindow_Null()
	{

	}

	CWindow_Null::~CWindow_Null()
	{
		LOG_SCOPED_TRACE(U"CWindow::~CWindow()");

		DLL::UnloadSystemLibrary(m_user32);
	}

	void CWindow_Null::init()
	{
		LOG_SCOPED_TRACE(U"CWindow::init()");

		// user32.dll
		{
			m_user32 = DLL::LoadSystemLibrary(L"user32.dll");
			m_pGetSystemMetricsForDpi = DLL::GetFunctionNoThrow(m_user32, "GetSystemMetricsForDpi");
			m_pAdjustWindowRectExForDpi = DLL::GetFunctionNoThrow(m_user32, "AdjustWindowRectExForDpi");
		}

		// DPI awareness を有効化
		detail::SetDPIAwareness(m_user32);

		// hInstance を取得
		m_hInstance = ::GetModuleHandleW(nullptr);

		LOG_VERBOSE(U"ShowWindow()");
	}

	void CWindow_Null::update()
	{

	}

	void CWindow_Null::setWindowTitle(const String& title)
	{
		m_title = title;
	}

	const String& CWindow_Null::getWindowTitle() const noexcept
	{
		return m_title;
	}

	void* CWindow_Null::getHandle() const noexcept
	{
		return nullptr;
	}

	const WindowState& CWindow_Null::getState() const noexcept
	{
		return m_state;
	}

	void CWindow_Null::setStyle(const WindowStyle style)
	{
		LOG_SCOPED_TRACE(U"CWindow::setStyle(style = {})"_fmt(FromEnum(style)));
	}

	void CWindow_Null::setPos(const Point& pos)
	{
		LOG_SCOPED_TRACE(U"CWindow::setPos(pos = {})"_fmt(pos));
	}

	void CWindow_Null::maximize()
	{
		LOG_TRACE(U"CWindow::maximize()");
	}

	void CWindow_Null::restore()
	{
		LOG_TRACE(U"CWindow::restore()");
	}

	void CWindow_Null::minimize()
	{
		LOG_TRACE(U"CWindow::minimize()");
	}

	bool CWindow_Null::setVirtualSize(const Size& size)
	{
		LOG_TRACE(U"CWindow::setVirtualSize(size = {})"_fmt(size));

		return true;
	}

	bool CWindow_Null::setFrameBufferSize(const Size& size)
	{
		LOG_TRACE(U"CWindow::setFrameBufferSize(size = {})"_fmt(size));

		return true;
	}

	void CWindow_Null::setMinimumFrameBufferSize(const Size& size)
	{
		m_state.minFrameBufferSize = size;
	}
}
