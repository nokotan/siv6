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
# include "Common.hpp"
# include "Time.hpp"
# include "Logger.hpp"
# include "Duration.hpp"
//# include "Print.hpp"

namespace s3d
{
	/// @brief マイクロ秒カウンター
	/// @remarks 経過時間をマイクロ秒で計測します。
	class MicrosecClock
	{
	private:

		const uint64 m_start = Time::GetMicrosec();

	public:

		/// @brief 経過時間（マイクロ秒）を返します。
		/// @return 経過時間（マイクロ秒）
		[[nodiscard]]
		uint64 us() const noexcept
		{
			return (Time::GetMicrosec() - m_start);
		}

		/// @brief ログに経過時間を出力します。
		void log() const { Logger(Microseconds(us())); }

		/// @brief 経過時間をデバッグ表示します。
		//void print() const { Print(Microseconds(us())); }
	};
}