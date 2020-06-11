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

# pragma once
# include <memory>
# include <mutex>
# include <Siv3D/Array.hpp>
# include <Siv3D/Cursor/ICursor.hpp>
# include <Siv3D/Windows/Windows.hpp>

namespace s3d
{
	class CCursor final : public ISiv3DCursor
	{
	private:

		HWND m_hWnd = nullptr;

		std::mutex m_clientPosBufferMutex;
		Array<std::pair<uint64, Point>> m_clientPosBuffer;

		CursorState m_state;

	public:

		CCursor();

		~CCursor() override;

		void init() override;

		bool update() override;
		
		const CursorState& getState() const noexcept override;

		void handleMessage(UINT message, WPARAM wParam, LPARAM lParam);
	};
}

