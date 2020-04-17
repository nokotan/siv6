﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files(the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions :
//	
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//
//----------------------------------------------------------------------------------------

# pragma once
# ifndef SIV3D_INCLUDED
#	define SIV3D_INCLUDED
# endif

//////////////////////////////////////////////////
//
//	ユーティリティ
//	Utilities
//
//////////////////////////////////////////////////

// プラットフォーム
// Platform
# include <Siv3D/Platform.hpp>

// ライブラリのバージョン
// Library version
# include <Siv3D/Version.hpp>

// 基本型
// Types
# include <Siv3D/Types.hpp>

// 前方宣言
// Forward declarations
# include <Siv3D/Fwd.hpp>

// プレースホルダー
// Place holder
# include <Siv3D/PlaceHolder.hpp>

// コピー禁止 Mixin
// Non-copyable mixin
# include <Siv3D/Uncopyable.hpp>

// 名前付き引数
// Named parameter
# include <Siv3D/NamedParameter.hpp>

// 定義済み名前付き引数
// Predefined named parameters
# include <Siv3D/PredefinedNamedParameter.hpp> // [Siv3D ToDo]

// 範囲をインデックス値とセットで列挙するユーティリティー
// Indexed iterator
# include <Siv3D/Indexed.hpp>

// メタ関数
// Meta
# include <Siv3D/Meta.hpp>

// 浮動小数点数型の共通型
// Common Float
# include <Siv3D/CommonFloat.hpp>

// ユーティリティー
// Utilities
# include <Siv3D/Utility.hpp>

// ファンクター
// Functor
//# include <Siv3D/Functor.hpp>

// エンディアン
// Endian
# include <Siv3D/Endian.hpp>

// バイト
// Byte
# include <Siv3D/Byte.hpp> // [Siv3D ToDo] istream

// スレッド
// Thread
//# include <Siv3D/Threading.hpp> // [Siv3D ToDo]

// 並列実行タスク
// Concurrent task
//# include <Siv3D/ConcurrentTask.hpp> // [Siv3D ToDo]

// メモリアライメント
// Memory alignment
//# include <Siv3D/AlignedMemory.hpp> // [Siv3D ToDo]

// メモリアライメント対応アロケーター
// Aligned allocator
//# include <Siv3D/AlignedAllocator.hpp> // [Siv3D ToDo]

// 動的配列（一次元）
// Array
# include <Siv3D/Array.hpp> // [Siv3D ToDo]

// 動的配列（二次元）
// 2D array
//# include <Siv3D/Grid.hpp> // [Siv3D ToDo]

// ハッシュ
// Hash
# include <Siv3D/Hash.hpp> // [Siv3D ToDo]

// ハッシュテーブル
// Hash table
//# include <Siv3D/HashTable.hpp> // [Siv3D ToDo]

// ハッシュセット
// Hash set
//# include <Siv3D/HashSet.hpp> // [Siv3D ToDo]

// kd 木
// kd-tree
//# include <Siv3D/KDTree.hpp> // [Siv3D ToDo]

// 範囲
// Range
//# include <Siv3D/Step.hpp> // [Siv3D ToDo]

// 2D 範囲
// 2D range
//# include <Siv3D/Step2D.hpp> // [Siv3D ToDo]

// 無限リスト
// Infinite list
//# include <Siv3D/InfiniteList.hpp> // [Siv3D ToDo]

// 無効値を持つ値
// Optional
# include <Siv3D/Optional.hpp> // [Siv3D ToDo]

// 特に指定しないことを表す無効値
// Representation of an unspecified value
//# include <Siv3D/Unspecified.hpp> // [Siv3D ToDo]

// イテレータによる範囲の表現
// Range iterator
//# include <Siv3D/RangeIterator.hpp> // [Siv3D ToDo]

// map と each の省略表記
// simple each and map
//# include <Siv3D/Evaluater.hpp> // [Siv3D ToDo]

// スコープ・ガード
// Scope guard
//# include <Siv3D/ScopeGuard.hpp>

// エラー
// Error
# include <Siv3D/Error.hpp>

//////////////////////////////////////////////////
//
//	文字列と数値
//	String and Number
//
//////////////////////////////////////////////////

// 文字
// Character
# include <Siv3D/Char.hpp>

// 文字列ビュー
// String view
# include <Siv3D/StringView.hpp> // [Siv3D ToDo]

// 文字列
// String
# include <Siv3D/String.hpp> // [Siv3D ToDo]

// Unicode
// Unicode
# include <Siv3D/Unicode.hpp> // [Siv3D ToDo]

// アルファベットの大文字・小文字
// Letter case
# include <Siv3D/LetterCase.hpp>




// [Siv3D ToDo]
# include <Siv3D/FormatLiteral.hpp>
# include <Siv3D/IntFormatter.hpp>
# include <Siv3D/FormatInt.hpp>
# include <Siv3D/FormatFloat.hpp>
# include <Siv3D/FormatData.hpp>
# include <Siv3D/Formatter.hpp>
# include <Siv3D/Format.hpp>

# include <Siv3D/ApplicationOptions.hpp>

# include <Siv3D/CPUInfo.hpp>

# include <Siv3D/Time.hpp>

# include <Siv3D/LogLevel.hpp>
# include <Siv3D/LogType.hpp>
# include <Siv3D/Logger.hpp>

# include <Siv3D/PointVector.hpp>

# include <Siv3D/Rectangle.hpp>

# include <Siv3D/Profiler.hpp>

# include <Siv3D/WindowStyle.hpp>
# include <Siv3D/WindowState.hpp>
# include <Siv3D/Window.hpp>

# include <Siv3D/Scene.hpp>

# include <Siv3D/Console.hpp>

# include <Siv3D/UserAction.hpp>

# include <Siv3D/System.hpp>


# if !defined(SIV3D_LIBRARY_BUILD) && SIV3D_PLATFORM(WINDOWS)

	# include <Siv3D/Windows/Libraries.hpp>

# endif


# if !defined(SIV3D_LIBRARY_BUILD) && !defined(NO_S3D_USING)

using namespace s3d;
using namespace std::literals;

# endif
