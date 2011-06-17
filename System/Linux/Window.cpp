#include <System/Linux.h>
#include <System/Linux/Controls.h>

#include <Engine/Xlib.h>

namespace System
{
	namespace Linux
	{
		Window::Window() : Controls::ContentControl()
		{
			win = xlib.CreateWindow(Width, Height, 0, 0, 0xFFFFFFFF);
//			win = xlib.CreateWindow(Width, Height, Top, Left, Colors::White);
	
			xlib.SetWmProtocol(win, "WM_DELETE_WINDOW", true, 1);
		}
	}
}

