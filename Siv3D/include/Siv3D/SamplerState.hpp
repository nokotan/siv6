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
# include <cstring>
# include <functional>
# include "Common.hpp"
# include "Utility.hpp"
# include "PointVector.hpp"
# include "TextureFilter.hpp"

namespace s3d
{
	/// <summary>
	/// テクスチャアドレスモード
	/// </summary>
	enum class TextureAddressMode : uint8
	{
		/// <summary>
		/// 繰り返し
		/// </summary>
		Repeat,

		/// <summary>
		/// ミラーで繰り返し
		/// </summary>
		Mirror,

		/// <summary>
		/// 繰り返しなし
		/// </summary>
		Clamp,

		/// <summary>
		/// 繰り返しなしで範囲外は境界色
		/// </summary>
		Border,
	};

	/// <summary>
	/// サンプラーステート
	/// </summary>
	struct SamplerState
	{
	private:

		enum class Predefined
		{
			RepeatNearest,
			
			RepeatLinear,
			
			RepeatAniso,
			
			MirrorNearest,
			
			MirrorLinear,
			
			MirrorAniso,
			
			ClampNearest,
			
			ClampLinear,
			
			ClampAniso,

			BorderNearest,

			BorderLinear,

			BorderAniso,
			
			Default2D = ClampLinear,
			
			Default3D = ClampAniso,
		};

	public:

		static constexpr uint32 MaxSamplerCount = 8;

		using storage_type = std::array<uint32, 5>;

		TextureAddressMode addressU : 2 = TextureAddressMode::Clamp;

		TextureAddressMode addressV : 2 = TextureAddressMode::Clamp;

		TextureAddressMode addressW : 2 = TextureAddressMode::Clamp;

		TextureFilter min : 1 = TextureFilter::Linear;

		TextureFilter mag : 1 = TextureFilter::Linear;

		TextureFilter mip : 1 = TextureFilter::Linear;

		uint8 maxAnisotropy : 7 = 1;

		// [Siv3D ToDo] HalFloat に
		int16 lodBias = 0;

		Float4 borderColor = Float4(0, 0, 0, 0);

		explicit constexpr SamplerState(
			TextureAddressMode _addressU = TextureAddressMode::Clamp,
			TextureAddressMode _addressV = TextureAddressMode::Clamp,
			TextureAddressMode _addressW = TextureAddressMode::Clamp,
			TextureFilter _min = TextureFilter::Linear,
			TextureFilter _mag = TextureFilter::Linear,
			TextureFilter _mip = TextureFilter::Linear,
			uint8 _maxAnisotropy = 1,
			int16 _lodBias = 0,
			Float4 _borderColor = Float4(0, 0, 0, 0)) noexcept
			: addressU(_addressU)
			, addressV(_addressV)
			, addressW(_addressW)
			, min(_min)
			, mag(_mag)
			, mip(_mip)
			, maxAnisotropy(_maxAnisotropy)
			, lodBias(_lodBias)
			, borderColor{ _borderColor.x, _borderColor.y, _borderColor.z, _borderColor.w } {}

		constexpr SamplerState(Predefined predefined) noexcept;

		[[nodiscard]]
		storage_type asValue() const noexcept
		{
			storage_type t;
			std::memcpy(&t, this, sizeof(storage_type));
			return t;
		}

		[[nodiscard]]
		bool operator ==(const SamplerState& other) const noexcept
		{
			return (asValue() == other.asValue());
		}

		[[nodiscard]]
		bool operator !=(const SamplerState& other) const noexcept
		{
			return (asValue() != other.asValue());
		}

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined RepeatNearest = Predefined::RepeatNearest;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined RepeatLinear = Predefined::RepeatLinear;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined RepeatAniso = Predefined::RepeatAniso;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined MirrorNearest = Predefined::MirrorNearest;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined MirrorLinear = Predefined::MirrorLinear;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined MirrorAniso = Predefined::MirrorAniso;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined ClampNearest = Predefined::ClampNearest;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined ClampLinear = Predefined::ClampLinear;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined ClampAniso = Predefined::ClampAniso;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined BorderNearest = Predefined::BorderNearest;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined BorderLinear = Predefined::BorderLinear;

		/// <summary>
		/// 
		/// 
		/// </summary>
		static constexpr Predefined BorderAniso = Predefined::BorderAniso;

		/// <summary>
		/// 2D 描画時のデフォルト
		/// SamplerState::WrapLinear
		/// </summary>
		static constexpr Predefined Default2D = Predefined::Default2D;

		/// <summary>
		/// 3D 描画時のデフォルト
		/// SamplerState::WrapAniso
		/// </summary>
		static constexpr Predefined Default3D = Predefined::Default3D;
	};
	static_assert(sizeof(SamplerState) == sizeof(SamplerState::storage_type));

	inline constexpr SamplerState::SamplerState(const Predefined predefined) noexcept
	{
		constexpr SamplerState PredefinedStates[12] =
		{
			SamplerState{ TextureAddressMode::Repeat, TextureAddressMode::Repeat, TextureAddressMode::Repeat,
							TextureFilter::Nearest, TextureFilter::Nearest, TextureFilter::Nearest },

			SamplerState{ TextureAddressMode::Repeat, TextureAddressMode::Repeat, TextureAddressMode::Repeat,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear },

			SamplerState{ TextureAddressMode::Repeat, TextureAddressMode::Repeat, TextureAddressMode::Repeat,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear, 16 },


			SamplerState{ TextureAddressMode::Mirror, TextureAddressMode::Mirror, TextureAddressMode::Mirror,
							TextureFilter::Nearest, TextureFilter::Nearest, TextureFilter::Nearest },

			SamplerState{ TextureAddressMode::Mirror, TextureAddressMode::Mirror, TextureAddressMode::Mirror,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear },

			SamplerState{ TextureAddressMode::Mirror, TextureAddressMode::Mirror, TextureAddressMode::Mirror,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear, 16 },


			SamplerState{ TextureAddressMode::Clamp, TextureAddressMode::Clamp, TextureAddressMode::Clamp,
							TextureFilter::Nearest, TextureFilter::Nearest, TextureFilter::Nearest },

			SamplerState{ TextureAddressMode::Clamp, TextureAddressMode::Clamp, TextureAddressMode::Clamp,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear },

			SamplerState{ TextureAddressMode::Clamp, TextureAddressMode::Clamp, TextureAddressMode::Clamp,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear, 16 },


			SamplerState{ TextureAddressMode::Border, TextureAddressMode::Border, TextureAddressMode::Border,
							TextureFilter::Nearest, TextureFilter::Nearest, TextureFilter::Nearest },

			SamplerState{ TextureAddressMode::Border, TextureAddressMode::Border, TextureAddressMode::Border,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear },

			SamplerState{ TextureAddressMode::Border, TextureAddressMode::Border, TextureAddressMode::Border,
							TextureFilter::Linear, TextureFilter::Linear, TextureFilter::Linear, 16 },
		};

		*this = PredefinedStates[FromEnum(predefined)];
	}
}

//////////////////////////////////////////////////
//
//	Hash
//
//////////////////////////////////////////////////

template <>
struct std::hash<s3d::SamplerState>
{
	[[nodiscard]]
	size_t operator()(const s3d::SamplerState& value) const noexcept
	{
		return s3d::Hash::FNV1a(&value, sizeof(value));
	}
};