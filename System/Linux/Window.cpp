#include <System/Linux.h>
#include <System/Linux/Controls.h>

#include <Engine/Xlib.h>

namespace System
{
	namespace Linux
	{
		Window::Window() : Controls::ContentControl(), PaintThreadStart((Action) Paint), PaintThread(PaintThreadStart)
		{
			Width = Height = 350;
			Top = Left = 20;
		
			win = xlib.CreateWindow(Width, Height, Top, Left, 0xFFFFFF);
			xlib.SetWmProtocol(win, "WM_DELETE_WINDOW", true, 1);
		}
		
		Window::~Window()
		{
			Close();
		}
		
		void Window::Close()
		{
			Hide();
			xlib.DestroyWindow(win);
		}
		
		void Window::Hide()
		{
			if (!IsMapped)
				return;

			PaintThread.Abort();

			IsMapped = false;
			xlib.UnmapWindow(win);
			xlib.Flush();
		}
		
		void Window::Show()
		{
			xlib.MapWindow(win, true);
			xlib.Flush();
			IsMapped = true;
	
			PaintThread.Start(*this);
	
//			EventLoop();
		}
		
		void *Window::Paint(Window &win)
		{
			while (1)
			{
/*				if (!win.IsVisible())
					pthread_exit(NULL);
	
				Cairo::RefPtr<Cairo::ImageSurface> backBuffer = Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, window.GetWidth(), window.GetHeight());
				Cairo::RefPtr<Cairo::Context> cr = Cairo::Context::create(backBuffer);

				window.Background->SetupContext(cr, window.GetWidth(), window.GetHeight());
				cr->paint();

				for (std::list<Control *>::iterator it = window.controls.begin(); it != window.controls.end(); it++)
				{
					cr->save();
					(*it)->Paint(cr);
					cr->restore();
				}
		
				Cairo::RefPtr<Cairo::XlibSurface> xlibSurface = Cairo::XlibSurface::create(display->GetDisplay(), window.GetWinId(), DefaultVisual(display->GetDisplay(), 0), window.GetWidth(), window.GetHeight());
				Cairo::RefPtr<Cairo::Context> xlibCtx = Cairo::Context::create(xlibSurface);

				xlibCtx->set_source(backBuffer, 0, 0);
				xlibCtx->rectangle(0, 0, window.GetWidth(), window.GetHeight());
				xlibCtx->fill();
*/
			}
		}
	}
}

