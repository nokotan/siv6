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
	/// @brief ミリ秒カウンター
	/// @remarks 経過時間をミリ秒で計測します。
	class MillisecClock
	{
	private:

		const uint64 m_start = Time::GetMillisec();

	public:

		/// @brief 経過時間（ミリ秒）を返します。
		/// @return 経過時間（ミリ秒）
		[[nodiscard]]
		uint64 ms() const noexcept
		{
			return (Time::GetMillisec() - m_start);
		}

		/// @brief ログに経過時間を出力します。
		void log() const { Logger(Milliseconds(ms())); }

		/// @brief 経過時間をデバッグ表示します。
		//void print() const { Print(Milliseconds(ms())); }
	};
}