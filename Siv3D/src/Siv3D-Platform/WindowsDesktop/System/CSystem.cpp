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

# include <Siv3D/Common/Siv3DEngine.hpp>
# include <Siv3D/Window/IWindow.hpp>
# include <Siv3D/Renderer/IRenderer.hpp>
# include <Siv3D/UserAction/IUSerAction.hpp>
# include <Siv3D/Common.hpp>
# include <Siv3D/String.hpp>
# include "CSystem.hpp"

namespace s3d
{
	CSystem::CSystem()
	{

	}

	CSystem::~CSystem()
	{

	}

	void CSystem::init()
	{
		LOG_SCOPED_TRACE(U"CSystem::init()");

		SIV3D_ENGINE(Window)->init();

		SIV3D_ENGINE(Renderer)->init();
	}

	bool CSystem::update()
	{
		if (SIV3D_ENGINE(UserAction)->terminationTriggered())
		{
			return false;
		}

		SIV3D_ENGINE(Window)->update();
	
		return true;
	}
}
