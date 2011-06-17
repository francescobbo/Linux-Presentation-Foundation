#include <Engine/Xlib.h>
#include <System/Exception.h>

#include <X11/Xatom.h>
#include <X11/Xutil.h>

Xlib::Xlib(bool Threaded, const char *DisplayString)
{
	Init(Threaded, DisplayString);
}

void Xlib::Init(bool Threaded, const char *DisplayString)
{
	if (Threaded)
		XInitThreads();
		
	disp = XOpenDisplay(DisplayString);
	if (!disp)
		throw System::Exception("Unable to open the X display!");
}

Xlib::WinId Xlib::CreateWindow(uint Width, uint Height, uint Top, uint Left, uint BgColor, WinId childOf)
{
	XCreateSimpleWindow(disp, childOf == 0 ? RootWindow(disp, 0) : childOf, Left, Top, Width, Height, 0, 0, BgColor);
}

void Xlib::SetWmProtocol(WinId Win, const char *AtomName, bool OnlyIfExists, uint value)
{
	Atom atom = XInternAtom(disp, AtomName, OnlyIfExists ? True : False);
	if (atom == None)
		throw System::Exception("Invalid X Atom!");
	XSetWMProtocols(disp, Win, &atom, value);
}

