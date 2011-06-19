#ifndef _LPF_SYSTEM_LINUX_WINDOW_H_
#define _LPF_SYSTEM_LINUX_WINDOW_H_

#include <System/Linux/Controls/ContentControl.h>
#include <System/Linux/Threading/ThreadStart.h>
#include <System/Linux/Threading/Thread.h>

#include <Engine/Xlib.h>

namespace System
{
	namespace Linux
	{
		class Window : public Controls::ContentControl
		{
			friend class ::Xlib;
		public:
			Window();
			virtual ~Window();
			
			void Show();
			void Hide();
			void Close();
			
			uint Left, Top;
			
		private:
			Xlib::WinId win;
			bool IsMapped;

			Threading::ThreadStart PaintThreadStart;
			Threading::Thread PaintThread;
			static void *Paint(Window &win);
			
			Xlib::WinId GetXId() const;
			void SetPassiveSize(int Width, int Height);
		};
	}
}

#endif

