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

# include <Siv3D/PixelShader.hpp>
# include <Siv3D/EngineLog.hpp>
# include <Siv3D/Shader/IShader.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>

namespace s3d
{
	template <>
	AssetIDWrapper<AssetHandle<PixelShader>>::AssetIDWrapper()
	{
		if (!Siv3DEngine::isActive())
		{
			//EngineMessageBox::Show(U"`VertexShader` must be initialized after engine setup.");
			std::exit(-1);
		}
	}

	template <>
	AssetIDWrapper<AssetHandle<PixelShader>>::~AssetIDWrapper()
	{
		if (!Siv3DEngine::isActive())
		{
			return;
		}

		if (auto p = SIV3D_ENGINE(Shader))
		{
			p->releasePS(m_id);
		}
	}

	PixelShader::PixelShader()
	{

	}

	PixelShader::PixelShader(const FilePathView path, const Array<ConstantBufferBinding>& bindings)
		: AssetHandle(std::make_shared<AssetIDWrapperType>(SIV3D_ENGINE(Shader)->createPS(path, bindings)))
	{

	}

	const Blob& PixelShader::getBinary() const noexcept
	{
		return SIV3D_ENGINE(Shader)->getBinaryPS(m_handle->id());
	}
}
