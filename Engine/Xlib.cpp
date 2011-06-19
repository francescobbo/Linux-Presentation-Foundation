#include <Engine/Xlib.h>
#include <System/Exception.h>
#include <System/Linux.h>

#include <X11/Xatom.h>
#include <X11/Xutil.h>

Xlib::Xlib(bool Threaded, const char *DisplayString)
{
	Init(Threaded, DisplayString);
}

Xlib::~Xlib()
{
	XCloseDisplay(disp);
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

void Xlib::DestroyWindow(WinId win)
{
	XDestroyWindow(disp, win);
}

void Xlib::MapWindow(WinId win, bool OnTop)
{
	if (OnTop)
		XMapRaised(disp, win);
	else
		XMapWindow(disp, win);
}

void Xlib::UnmapWindow(WinId win)
{
	XUnmapWindow(disp, win);
}

void Xlib::SetWmProtocol(WinId Win, const char *AtomName, uint value)
{
	Atom atom = GetAtom(AtomName);
	XSetWMProtocols(disp, Win, &atom, value);
}

void Xlib::Flush()
{
	XFlush(disp);
}

void Xlib::SetMwmHints(WinId win, MotifHints *NewHints)
{
	Atom hints_atom = None;
	MotifHints *hints;

	PropertyDetails details;
	byte *data = GetProperty(win, "_MOTIF_WM_HINTS", sizeof(MotifHints), &details);

	/* New Hint */
	if (details.Type == None)
		hints = NewHints;
	else
	{
		/* If that Hint already exists, save it's informations */
		hints = (MotifHints *) data;

		if (NewHints->flags & MotifFunctions)
		{
			hints->flags |= MotifFunctions;
			hints->functions = NewHints->functions;
		}

		if (NewHints->flags & MotifDecorations)
		{
			hints->flags |= MotifDecorations;
			hints->decorations = NewHints->decorations;
		}
	}

	SetProperty(win, "_MOTIF_WM_HINTS", 32, PropModeReplace, (byte *) hints, sizeof(MotifHints));

	if (hints != NewHints)
		XFree(hints);
}

void Xlib::SetDecorations(WinId win, bool visible)
{
	MotifHints hints;

	hints.flags = MotifDecorations;
	hints.decorations = visible;

	SetMwmHints(win, &hints);
}

void Xlib::EventPump(System::Object &win)
{
	System::Linux::Window &window = (System::Linux::Window &) win;
	
	XSelectInput(disp, window.GetXId(), ExposureMask | KeyPressMask | ButtonPressMask | PointerMotionMask);

	XEvent e;
	while (true)
	{
		XNextEvent(disp, &e);
		switch (e.type)
		{
			case Expose:
			{
				/* The Window might have been resized. Get the latest value. We can't trust the exposed paramter */
				XWindowAttributes wAtt;
				XGetWindowAttributes(disp, window.GetXId(), &wAtt);
				window.SetPassiveSize(wAtt.width, wAtt.height);

				break;
			}
			case ClientMessage:
				window.Close();
				return;
			case MotionNotify:
			{
				
				break;
			}
			default:
				break;
		}
	}
}

Atom Xlib::GetAtom(const char *atomName)
{
	/* XInternAtom is slow, specially if the server is remote. So we cache atoms */
	if (AtomCache.ContainsKey(atomName))
		return AtomCache[atomName];

	/* Not found? Use XInternAtom */
	Atom atom = XInternAtom(disp, atomName, False);
	AtomCache.Add(atomName, atom);
	
	return atom;
}

byte *Xlib::GetProperty(WinId win, const char *AtomName, size_t count, PropertyDetails *prop)
{
	byte *buff;
	if (prop)
		XGetWindowProperty(disp, win, GetAtom(AtomName), 0, count / 4, False, AnyPropertyType, &(prop->Type), &(prop->Format), &(prop->NItems), &(prop->Remaining), &buff);
	else
	{
		Atom type;
		int format;
		ulong nitems;
		ulong remaining;
		XGetWindowProperty(disp, win, GetAtom(AtomName), 0, count / 4, False, AnyPropertyType, &type, &format, &nitems, &remaining, &buff);
	}
	
	return buff;
}

void Xlib::SetProperty(WinId win, const char *AtomName, int bits, int mode, byte *data, size_t count)
{
	Atom propAtom = GetAtom(AtomName);
	XChangeProperty(disp, win, propAtom, propAtom, bits, mode, data, count / 4);
}

