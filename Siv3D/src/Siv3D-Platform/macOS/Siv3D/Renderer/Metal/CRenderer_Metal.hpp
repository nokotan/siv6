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

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Scene.hpp>
# include <Siv3D/Graphics.hpp>
# include <Siv3D/Window.hpp>
# include <Siv3D/Common/OpenGL.hpp>
# include <Siv3D/Renderer/IRenderer.hpp>
# import <Metal/Metal.h>
# import <QuartzCore/CAMetalLayer.h>

namespace s3d
{
	class CRenderer_Metal final : public ISiv3DRenderer
	{
	private:
		
		GLFWwindow* m_window = nullptr;

		id<MTLDevice> m_device;
		
		id<MTLCommandQueue> m_commandQueue;
		
		CAMetalLayer* m_swapchain = nullptr;
		
		uint32 m_sampleCount			= Graphics::DefaultSampleCount;

		ResizeMode m_sceneResizeMode	= Scene::DefaultResizeMode;

		Size m_backBufferSize			= Window::DefaultClientSize;

		Size m_sceneSize				= Scene::DefaultSceneSize;

		ColorF m_letterboxColor				= Scene::DefaultLetterBoxColor;
		
		ColorF m_backgroundColor			= Scene::DefaultBackgroundColor;

		TextureFilter m_sceneTextureFilter	= Scene::DefaultTextureFilter;

	public:

		CRenderer_Metal();

		~CRenderer_Metal() override;

		void init() override;

		StringView getName() const override;

		void clear() override;

		void flush() override;

		bool present() override;
		
		void setSceneResizeMode(ResizeMode resizeMode) override;

		ResizeMode getSceneResizeMode() const noexcept override;

		void setSceneBufferSize(Size size) override;

		Size getSceneBufferSize() const noexcept override;

		void setSceneTextureFilter(TextureFilter textureFilter) override;

		TextureFilter getSceneTextureFilter() const noexcept override;

		void setBackgroundColor(const ColorF& color) override;

		const ColorF& getBackgroundColor() const noexcept override;

		void setLetterboxColor(const ColorF& color) override;

		const ColorF& getLetterboxColor() const noexcept override;
		
		std::pair<float, FloatRect> getLetterboxComposition() const noexcept override;

		
		
		id<MTLDevice> getDevice() const;
		
		id<MTLCommandQueue> getCommandQueue() const;
		
		CAMetalLayer* getSwapchain() const;
	};
}
