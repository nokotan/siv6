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
# include "Types.hpp"
# include "Number.hpp"
# include "HardwareRNG.hpp"
# include "SplitMix64.hpp"

namespace s3d
{
	namespace PRNG
	{
		/// <summary>
		/// xoshiro256** / Pseudo random number generator
		/// Output: 64-bit value
		/// Period: 2^256-1
		/// Footprint: 32 bytes
		/// Original implementation: http://prng.di.unimi.it/xoshiro256starstar.c
		/// </summary>
		class Xoshiro256StarStar
		{
		public:

			using State_t = std::array<uint64, 4>;

		private:

			State_t s;

			[[nodiscard]]
			static constexpr uint64 rotl(const uint64 x, int32 k)
			{
				return (x << k) | (x >> (64 - k));
			}

		public:

			/// <summary>
			/// 生成される整数値の型
			/// The integral type generated by the engine
			/// </summary>
			using result_type = uint64;

			SIV3D_NODISCARD_CXX20
			explicit Xoshiro256StarStar()
				: s(SplitMix64{ HardwareRNG{}() }.generateSeeds<4>()) {}

			/// <summary>
			/// 乱数エンジンを作成し、内部状態を初期化します。
			/// Constructs the engine and initializes the state.
			/// </summary>
			/// <param name="seed">
			/// 内部状態の初期化に使われるシード値
			/// seed value to use in the initialization of the internal state
			/// </param>
			SIV3D_NODISCARD_CXX20
			explicit constexpr Xoshiro256StarStar(uint64 seed) noexcept
				: s(SplitMix64{ seed }.generateSeeds<4>()) {}

			/// <summary>
			/// 乱数エンジンを作成し、内部状態を初期化します。
			/// Constructs the engine and initializes the state.
			/// </summary>
			/// <param name="seeds">
			/// 内部状態の初期化に使われるシード値
			/// seed values to use in the initialization of the internal state
			/// </param>
			SIV3D_NODISCARD_CXX20
			explicit constexpr Xoshiro256StarStar(const State_t& seeds) noexcept
				: s(seeds) {}

			/// <summary>
			/// 新しいシード値で乱数エンジンの内部状態を再初期化します。
			/// Reinitializes the internal state of the random-number engine using a new seed value.
			/// </summary>
			/// <param name="seed">
			/// 内部状態の初期化に使われるシード値
			/// seed value to use in the initialization of the internal state
			/// </param>
			constexpr void seed(const uint64 seed) noexcept
			{
				s = SplitMix64{ seed }.generateSeeds<4>();
			}

			/// <summary>
			/// 生成される乱数の最小値を返します。
			/// Returns the minimum value potentially generated by the random-number engine
			/// </summary>
			/// <returns>
			/// 生成される乱数の最小値
			/// The minimum potentially generated value
			/// </returns>
			[[nodiscard]]
			static constexpr result_type min() noexcept
			{
				return Smallest<result_type>;
			}

			/// <summary>
			/// 生成される乱数の最大値を返します。
			/// Returns the maximum value potentially generated by the random-number engine.
			/// </summary>
			/// <returns>
			/// 生成される乱数の最大値
			/// The maximum potentially generated value
			/// </returns>
			[[nodiscard]]
			static constexpr result_type max() noexcept
			{
				return Largest<result_type>;
			}

			/// <summary>
			/// 乱数を生成します。
			/// Generates a pseudo-random value.
			/// </summary>
			/// <returns>
			/// 生成された乱数
			/// A generated pseudo-random value
			/// </returns>
			constexpr result_type operator()() noexcept
			{
				const uint64_t result_starstar = rotl(s[1] * 5, 7) * 9;
				const uint64_t t = s[1] << 17;
				s[2] ^= s[0];
				s[3] ^= s[1];
				s[1] ^= s[2];
				s[0] ^= s[3];
				s[2] ^= t;
				s[3] = rotl(s[3], 45);
				return result_starstar;
			}

			/// <summary>
			/// 乱数エンジンの内部状態を返します。
			/// Returns the internal state of the random-number engine.
			/// </summary>
			/// <returns>
			/// 乱数エンジンの内部状態
			/// The internal state of the random-number engine
			/// </returns>
			[[nodiscard]]
			constexpr const State_t& serialize() const noexcept
			{
				return s;
			}

			constexpr void deserialize(const State_t& state) noexcept
			{
				s = state;
			}
		};
	}
}