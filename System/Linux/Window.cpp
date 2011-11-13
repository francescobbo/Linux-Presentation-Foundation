#include <System/Linux.h>
#include <System/Linux/Controls.h>

#include <Engine/Xlib.h>

#include <cairommconfig.h>
#include <cairomm/cairomm.h>
#include <cairomm/xlib_surface.h>

#include <iostream>
using namespace std;
	
namespace System
{
	namespace Linux
	{
		Window::Window() : Controls::ContentControl(), PaintThreadStart((Action1) Paint), PaintThread(PaintThreadStart)
		{
			Width = Height = 350;
			Top = Left = 20;
		
			win = xlib.CreateWindow(Width, Height, Top, Left, 0xFFFFFF);
			xlib.SetWmProtocol(win, "WM_DELETE_WINDOW", 1);
			
			xlib.SetDecorations(win, false);
		}
		
		Window::~Window()
		{
			Close();
		}
		
		void Window::Close()
		{
			Hide();
			if (win)
				xlib.DestroyWindow(win);
			win = 0;
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
	
			cout << "Rwin: " << this << endl;
			PaintThread.Start(*this);
	
			xlib.EventPump(*this);
		}

		void *Window::Paint(Window &win)
		{
			while (1)
			{
				if (!win.IsMapped)
				{
					cout << "Win: " << &win << endl;
					cout << "Bye from Paint" << endl;
					pthread_exit(NULL);
				}
	
				Cairo::RefPtr<Cairo::ImageSurface> backBuffer = Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, win.Width, win.Height);
				Cairo::RefPtr<Cairo::Context> cr = Cairo::Context::create(backBuffer);

				win.Background->SetupContext(cr, win.Width, win.Height);
				cr->paint();
/*
				for (std::list<Control *>::iterator it = window.controls.begin(); it != window.controls.end(); it++)
				{
					cr->save();
					(*it)->Paint(cr);
					cr->restore();
				}
*/		
				Cairo::RefPtr<Cairo::XlibSurface> xlibSurface = Cairo::XlibSurface::create(xlib.GetDisplay(), win.GetXId(), DefaultVisual(xlib.GetDisplay(), 0), win.Width, win.Height);
				Cairo::RefPtr<Cairo::Context> xlibCtx = Cairo::Context::create(xlibSurface);

				xlibCtx->set_source(backBuffer, 0, 0);
				xlibCtx->rectangle(0, 0, win.Width, win.Height);
				xlibCtx->fill();

			}
		}
		
		Xlib::WinId Window::GetXId() const
		{
			return win;
		}
		
		void Window::SetPassiveSize(int Width, int Height)
		{
			this->Width = Width;
			this->Height = Height;
		}
	}
}

