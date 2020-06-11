
# include <Siv3D.hpp>

SIV3D_OPTION_DEBUG_HEAP_MANAGER(true);
SIV3D_OPTION_HEADLESS_MODE(false);
SIV3D_OPTION_OUTPUT_STDERR(true);
SIV3D_OPTION_RUN_TEST(false);

void Main()
{
	while (System::Update())
	{
		const auto state = Window::GetState();
		const double uiScaling = double(state.frameBufferSize.x) / state.virtualSize.x;
		
		Window::SetTitle(U"S:{} R:{} PF:{:.1f} P:{} WS:{} UIS:{}"_fmt(
			Cursor::ScreenPos(), Cursor::PosRaw(), Cursor::PosF(), Cursor::Pos(),
			Window::GetState().scaling, uiScaling));
	}
}
