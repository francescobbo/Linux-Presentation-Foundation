#ifndef _LPF_SYSTEM_LINUX_MEDIA_BRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_BRUSH_H_

#include <System/Linux/Media/Animation/Animatable.h>
#include <System/IFormattable.h>

#include <cairomm/cairomm.h>
#include <cairomm/xlib_surface.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class Brush : public Animation::Animatable, public IFormattable
			{
			public:
				//Brush();
				//Brush(const Brush &&copy);
				
				virtual void SetupContext(Cairo::RefPtr<Cairo::Context> cr, double w, double h) = 0;
			
				String ToString() const;
			
				double Opacity;
			};
		}
	}
}

#endif

