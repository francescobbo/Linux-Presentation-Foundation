#ifndef _LPF_XLIB_H_
#define _LPF_XLIB_H_

#include <X11/Xlib.h>
#include <System/Object.h>
#include <System/Collections/Generic/Dictionary.h>
#include <BasicTypes.h>

class Xlib
{
public:
	Xlib(bool Threaded = false, const char *DisplayString = 0);
	~Xlib();
	
	void Init(bool Threaded, const char *DisplayString);

	typedef Window WinId;
	
	WinId CreateWindow(uint Width, uint Height, uint Top, uint Left, uint BgColor, WinId childOf = 0);
	void DestroyWindow(WinId win);
	void MapWindow(WinId win, bool OnTop = false);
	void UnmapWindow(WinId win);
	void SetDecorations(WinId win, bool visible);

	void SetWmProtocol(WinId win, const char *Atom, uint value);
	void Flush();
	
	void EventPump(System::Object &win);
	
	Display *GetDisplay()
	{
		return disp;
	}
	
private:
	Display *disp;
	
	struct PropertyDetails
	{
		Atom Type;
		int Format;
		ulong NItems;
		ulong Remaining;
	};
	
	enum MotifHintsFlags
	{
		MotifFunctions = 1,
		MotifDecorations
	};
	
	struct MotifHints
	{
		unsigned long flags;
		unsigned long functions;
		unsigned long decorations;
		long inputMode;
		unsigned long status;
	};
	
	void SetMwmHints(WinId win, MotifHints *new_hints);
	byte *GetProperty(WinId win, const char *AtomName, size_t count, PropertyDetails *prop);
	void SetProperty(WinId win, const char *AtomName, int bits, int mode, byte *data, size_t count);
	
	Atom GetAtom(const char *atomName);
	
	System::Collections::Generic::Dictionary<const char *, Atom> AtomCache;
};

extern Xlib xlib;

#endif

