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

namespace s3d
{
	class ISiv3DWindow
	{
	public:

		static ISiv3DWindow* Create();

		virtual ~ISiv3DWindow() = default;

		virtual void init() = 0;
	};
}