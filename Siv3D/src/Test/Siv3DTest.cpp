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

# include <Siv3D.hpp>

# if SIV3D_PLATFORM(WINDOWS)
#	include <conio.h>
#	pragma warning(disable : 6237 6319 26439 26451 26495 26812)
# endif

# define CATCH_CONFIG_RUNNER
# define CATCH_CONFIG_FAST_COMPILE
# include <Catch2/catch.hpp>

using namespace s3d;
using namespace std::literals;

void PerformTest()
{
	Console.open();

	Catch::Session().run();

# if SIV3D_PLATFORM(WINDOWS)

	(void)_getch();

# endif
}

TEST_CASE("String")
{
	SECTION("Constructor")
	{
		REQUIRE(String(5, U'A') == U"AAAAA");
	}

	SECTION("operator bool")
	{
		REQUIRE(!String(U"") == true);
		REQUIRE(!String(U"ABC") == false);
		REQUIRE(static_cast<bool>(String(U"")) == false);
		REQUIRE(static_cast<bool>(String(U"ABC")) == true);
	}
}

TEST_CASE("Unicode")
{
	SECTION("Narrow")
	{
		REQUIRE(Unicode::Narrow(U"") == "");
		REQUIRE(Unicode::Narrow(U"OpenSiv3D") == "OpenSiv3D");
		REQUIRE(Unicode::Narrow(U"あいうえお") == "あいうえお");
	}

	SECTION("ToWstring")
	{
		REQUIRE(Unicode::ToWstring(U"") == L"");
		REQUIRE(Unicode::ToWstring(U"OpenSiv3D") == L"OpenSiv3D");
		REQUIRE(Unicode::ToWstring(U"あいうえお") == L"あいうえお");
	}

	SECTION("ToUTF8")
	{
		const std::u8string_view u0 = u8"OpenSiv3D";
		const std::u8string_view u1 = u8"あいうえお";
		const std::string s0(u0.begin(), u0.end());
		const std::string s1(u1.begin(), u1.end());
		REQUIRE(Unicode::ToUTF8(U"") == "");
		REQUIRE(Unicode::ToUTF8(U"OpenSiv3D") == s0);
		REQUIRE(Unicode::ToUTF8(U"あいうえお") == s1);
	}

	SECTION("ToUTF16")
	{
		REQUIRE(Unicode::ToUTF16(U"") == u"");
		REQUIRE(Unicode::ToUTF16(U"OpenSiv3D") == u"OpenSiv3D");
		REQUIRE(Unicode::ToUTF16(U"あいうえお") == u"あいうえお");
	}

	SECTION("ToUTF32")
	{
		REQUIRE(Unicode::ToUTF32(U"") == U"");
		REQUIRE(Unicode::ToUTF32(U"OpenSiv3D") == U"OpenSiv3D");
		REQUIRE(Unicode::ToUTF32(U"あいうえお") == U"あいうえお");
	}
}

TEST_CASE("FormatLiteral")
{
	SECTION("Fmt")
	{
		REQUIRE(Fmt(U"")() == U"");
		REQUIRE(Fmt(U"{}")(12345) == U"12345");

		REQUIRE(Fmt(U""sv)() == U"");
		REQUIRE(Fmt(U"{}"sv)(12345) == U"12345");

		REQUIRE(Fmt(String(U""))() == U"");
		REQUIRE(Fmt(String(U"{}"))(12345) == U"12345");
	}

	SECTION("_fmt")
	{
		REQUIRE(U""_fmt() == U"");
		REQUIRE(U"{}"_fmt(12345) == U"12345");
		REQUIRE(U"{}"_fmt(U"OpenSiv3D") == U"OpenSiv3D");
		REQUIRE(U"{}"_fmt(U"あいうえお") == U"あいうえお");
	}

	SECTION("formatter<String>")
	{
		const String s = U"ABCDE";
		REQUIRE(U"{}"_fmt(s) == U"ABCDE");
		REQUIRE(U"{0}"_fmt(s) == U"ABCDE");
		REQUIRE(U"{:<6}"_fmt(s) == U"ABCDE ");
		REQUIRE(U"{:*>10}"_fmt(s) == U"*****ABCDE");
	}
}
