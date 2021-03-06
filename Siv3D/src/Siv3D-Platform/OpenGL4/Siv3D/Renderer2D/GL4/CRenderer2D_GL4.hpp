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
# include <Siv3D/Common.hpp>
# include <Siv3D/Renderer2D/IRenderer2D.hpp>
# include <Siv3D/Renderer/GL4/CRenderer_GL4.hpp>
# include <Siv3D/Common/OpenGL.hpp>
# include "GL4Vertex2DBatch.hpp"

namespace s3d
{
	class GL4Renderer2DCommand {};

	class CRenderer2D_GL4 final : public ISiv3DRenderer2D
	{
	private:

		CRenderer_GL4* pRenderer = nullptr;

		GLuint m_vsProgram		= 0;
		GLuint m_psProgram		= 0;
		GLuint m_pipeline		= 0;
		GLuint m_uniformBuffer	= 0;

		GL4Vertex2DBatch m_batches;
		GL4Renderer2DCommand m_command;
		uint32 m_draw_indexCount = 0;

		//////////////////////////////////////////////////
		//
		//	full screen triangle
		//
		//////////////////////////////////////////////////

		GLuint m_copyProgram		= 0;
		GLuint m_vertexArray		= 0;
		GLuint m_sampler			= 0;
		GLuint m_locationTexture	= 0;

	public:

		CRenderer2D_GL4();

		~CRenderer2D_GL4() override;

		void init() override;

		void flush() override;

		void test_renderRectangle(const RectF& rect, const ColorF& color) override;

		void drawFullScreenTriangle(TextureFilter textureFilter) override;
	};
}
