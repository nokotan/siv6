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
# include "detail/Distribution.ipp"

namespace s3d
{
	template <class IntType = int32>
	using UniformIntDistribution = absl::uniform_int_distribution<IntType>;

	template <class RealType = double>
	using UniformRealDistribution = absl::uniform_real_distribution<RealType>;

	template <class RealType = double>
	using NormalDistribution = absl::gaussian_distribution<RealType>;
}
