//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <mach/mach_time.h>
# include <sys/time.h>
# include <Siv3D/Time.hpp>

namespace s3d
{
	namespace detail
	{
		static uint64 SteadyFull() noexcept
		{
			::mach_timebase_info_data_t base;
			::mach_timebase_info(&base);
			return static_cast<uint64>(::mach_absolute_time() * static_cast<double>(base.numer) / base.denom);
		}
		
		inline decltype(::mach_absolute_time)* InitSteadyClock() noexcept
		{
			::mach_timebase_info_data_t base;
			::mach_timebase_info(&base);
			return (base.numer == base.denom) ? ::mach_absolute_time : SteadyFull;
		}
	}

	namespace Time
	{
		uint64 GetSec() noexcept
		{
			return GetNanosec() / 1'000'000'000;
		}
		
		uint64 GetMillisec() noexcept
		{
			return GetNanosec() / 1'000'000;
		}
		
		uint64 GetMicrosec() noexcept
		{
			return GetNanosec() / 1'000;
		}
		
		uint64 GetNanosec() noexcept
		{
			const static auto SteadyClock = detail::InitSteadyClock();
			return SteadyClock();
		}
	}
}