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

# include <Siv3D/Common.hpp>
# include <Siv3D/EngineLog.hpp>
# include <Siv3D/Windows/Windows.hpp>
# include "CResource.hpp"

namespace s3d
{
	CResource::CResource() = default;

	CResource::~CResource()
	{
		LOG_SCOPED_TRACE(U"CResource::~CResource()");
	}

	void CResource::init()
	{
		LOG_SCOPED_TRACE(U"CResource::init()");
	}
}