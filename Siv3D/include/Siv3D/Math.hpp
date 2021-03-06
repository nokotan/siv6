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

namespace s3d
{
	//////////////////////////////////////////////////
	//
	//	Fmod
	//
	//////////////////////////////////////////////////

	namespace Math
	{
		[[nodiscard]]
		inline float Fmod(float x, float y) noexcept;

		[[nodiscard]]
		inline double Fmod(double x, double y) noexcept;

		[[nodiscard]]
		inline Float2 Fmod(Float2 v1, Float2 v2) noexcept;

		[[nodiscard]]
		inline Float3 Fmod(Float3 v1, Float3 v2) noexcept;

		[[nodiscard]]
		inline Float4 Fmod(Float4 v1, Float4 v2) noexcept;

		[[nodiscard]]
		inline Vec2 Fmod(Vec2 v1, Vec2 v2) noexcept;

		[[nodiscard]]
		inline Vec3 Fmod(Vec3 v1, Vec3 v2) noexcept;

		[[nodiscard]]
		inline Vec4 Fmod(Vec4 v1, Vec4 v2) noexcept;

		template <class T, class U, class R = CommonVector_t<T, U>>
		[[nodiscard]]
		inline R Fmod(T x, U y) noexcept;
	}

	//////////////////////////////////////////////////
	//
	//	Fraction
	//
	//////////////////////////////////////////////////

	namespace Math
	{
		[[nodiscard]]
		inline float Fraction(float x) noexcept;

		[[nodiscard]]
		inline double Fraction(double x) noexcept;

		[[nodiscard]]
		inline Float2 Fraction(Float2 v) noexcept;

		[[nodiscard]]
		inline Float3 Fraction(Float3 v) noexcept;

		[[nodiscard]]
		inline Float4 Fraction(Float4 v) noexcept;

		[[nodiscard]]
		inline Vec2 Fraction(Vec2 v) noexcept;

		[[nodiscard]]
		inline Vec3 Fraction(Vec3 v) noexcept;

		[[nodiscard]]
		inline Vec4 Fraction(Vec4 v) noexcept;
	}

	//////////////////////////////////////////////////
	//
	//	Frexp
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Ldexp
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Log
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Log2
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Log10
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Modf
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Pow
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Sign
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	ToRadians
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	ToDegrees
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Abs
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	AbsDiff
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Square
	//
	//////////////////////////////////////////////////

	namespace Math
	{
		[[nodiscard]]
		inline constexpr float Square(float x) noexcept;

		[[nodiscard]]
		inline constexpr double Square(double x) noexcept;

		[[nodiscard]]
		inline constexpr Float2 Square(Float2 v) noexcept;

		[[nodiscard]]
		inline constexpr Float3 Square(Float3 v) noexcept;

		[[nodiscard]]
		inline constexpr Float4 Square(Float4 v) noexcept;

		[[nodiscard]]
		inline constexpr Vec2 Square(Vec2 v) noexcept;

		[[nodiscard]]
		inline constexpr Vec3 Square(Vec3 v) noexcept;

		[[nodiscard]]
		inline constexpr Vec4 Square(Vec4 v) noexcept;

		SIV3D_CONCEPT_ARITHMETIC
		[[nodiscard]]
		inline constexpr Arithmetic Square(Arithmetic x) noexcept;
	}

	//////////////////////////////////////////////////
	//
	//	Exp
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Exp2
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Rsqrt
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Sqrt
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Ceil
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Floor
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Round
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Clamp
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Saturate
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Acos
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Asin
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Atan
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Atan2
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Cos
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Cosh
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Sin
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Sinh
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Tan
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Tanh
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Normalize
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}

	//////////////////////////////////////////////////
	//
	//	Smoothstep
	//
	//////////////////////////////////////////////////

	namespace Math
	{

	}
}

# include "detail/Math.ipp"
