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
# include <ThirdParty/fmt/format.h>
# include <ThirdParty/fmt/ostream.h>
# include "String.hpp"

namespace s3d
{
	namespace detail
	{
		struct FormatHelper;

		template <class ParseContext>
		inline auto GetFormatTag(std::u32string& representation, ParseContext& ctx)
		{
			auto it = ctx.begin();
			const auto itEnd = ctx.end();

			while (it != itEnd && (*it != '}'))
			{
				representation.push_back(*it++);
			}

			return it;
		}
	}

	[[nodiscard]]
	inline detail::FormatHelper Fmt(const String& s) noexcept;

	[[nodiscard]]
	inline constexpr detail::FormatHelper Fmt(StringView s) noexcept;

	[[nodiscard]]
	inline constexpr detail::FormatHelper Fmt(const char32* s) noexcept;

	inline namespace Literals
	{
		inline namespace FormatLiterals
		{
			[[nodiscard]]
			constexpr detail::FormatHelper operator ""_fmt(const char32 * s, size_t length) noexcept;
		}
	}
}

template <>
struct SIV3D_HIDDEN fmt::formatter<s3d::String, s3d::char32>
{
	std::u32string tag;

	auto parse(basic_format_parse_context<s3d::char32>& ctx)
	{
		return s3d::detail::GetFormatTag(tag, ctx);
	}

	template <class FormatContext>
	auto format(const s3d::String& value, FormatContext& ctx)
	{
		const basic_string_view<s3d::char32> sv(value.data(), value.size());

		if (tag.empty())
		{
			return format_to(ctx.out(), sv);
		}
		else
		{
			const std::u32string format = (U"{:" + tag + U'}');
			return format_to(ctx.out(), format, sv);
		}
	}
};

template <>
struct SIV3D_HIDDEN fmt::formatter<s3d::StringView, s3d::char32>
{
	std::u32string tag;

	auto parse(basic_format_parse_context<s3d::char32>& ctx)
	{
		return s3d::detail::GetFormatTag(tag, ctx);
	}

	template <class FormatContext>
	auto format(const s3d::StringView& value, FormatContext& ctx)
	{
		const basic_string_view<s3d::char32> sv(value.data(), value.size());

		if (tag.empty())
		{
			return format_to(ctx.out(), sv);
		}
		else
		{
			const std::u32string format = (U"{:" + tag + U'}');
			return format_to(ctx.out(), format, sv);
		}
	}
};

# include "FormatLiteral.ipp"
