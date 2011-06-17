#ifndef _LPF_XLIB_H_
#define _LPF_XLIB_H_

#include <X11/Xlib.h>

class Xlib
{
public:
	Xlib(bool Threaded = false, const char *DisplayString = 0);
	
	void Init(bool Threaded, const char *DisplayString);

	typedef Window WinId;
	
	WinId CreateWindow(uint Width, uint Height, uint Top, uint Left, uint BgColor, WinId childOf = 0);
	void SetWmProtocol(WinId Win, const char *Atom, bool OnlyIfExists, uint value);
	
private:
	Display *disp;	
};

extern Xlib xlib;

#endif

