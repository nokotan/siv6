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
	struct HSV
	{
		/// @brief 色相 |Hue [0.0, 360.0)
		double h;

		/// @brief 彩度 | Saturation [0.0, 1.0]
		double s;

		/// @brief 明度 | Value [0.0, 1.0]
		double v;

		/// @brief アルファ | Alpha [0.0, 1.0]
		double a = 1.0;
	};
}
