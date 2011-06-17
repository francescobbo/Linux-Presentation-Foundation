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
	void DestroyWindow(WinId win);
	void MapWindow(WinId win, bool OnTop = false);
	void UnmapWindow(WinId win);

	void SetWmProtocol(WinId win, const char *Atom, bool OnlyIfExists, uint value);
	void Flush();
	
private:
	Display *disp;	
};

extern Xlib xlib;

#endif

