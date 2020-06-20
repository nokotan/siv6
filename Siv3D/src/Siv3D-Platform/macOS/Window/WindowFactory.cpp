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

# include <Siv3D/ApplicationOptions.hpp>
# include <Window/CWindow_Null.hpp>
# include <Window/CWindow.hpp>

namespace s3d
{
	ISiv3DWindow* ISiv3DWindow::Create()
	{
		if (g_applicationOptions.renderer == RendererType::Headless)
		{
			return new CWindow_Null;
		}
		else
		{
			return new CWindow;
		}
	}
}
