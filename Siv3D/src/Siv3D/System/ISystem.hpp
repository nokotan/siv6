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
	class ISiv3DSystem
	{
	public:

		static ISiv3DSystem* Create();

		virtual ~ISiv3DSystem() = default;

		virtual void init() = 0;
	};
}
