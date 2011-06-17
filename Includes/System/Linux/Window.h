#ifndef _LPF_SYSTEM_LINUX_WINDOW_H_
#define _LPF_SYSTEM_LINUX_WINDOW_H_

#include <System/Linux/Controls/ContentControl.h>

#include <Engine/Xlib.h>

namespace System
{
	namespace Linux
	{
		class Window : public Controls::ContentControl
		{
		public:
			Window();
			
			uint Left, Top;
			
		private:
			Xlib::WinId win;
		};
	}
}

#endif

