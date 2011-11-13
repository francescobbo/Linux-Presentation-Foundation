#ifndef _LPF_SYSTEM_LINUX_MEDIA_SOLIDCOLORBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_SOLIDCOLORBRUSH_H_

#include <System/Linux/Media/Brush.h>
#include <System/Linux/Media/Color.h>

#include <cairomm/cairomm.h>
#include <cairomm/xlib_surface.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class SolidColorBrush : public Brush
			{
			public:
				SolidColorBrush();
				SolidColorBrush(Color c);
				SolidColorBrush(const SolidColorBrush &copy);

				void SetupContext(Cairo::RefPtr<Cairo::Context> cr, double w, double h);

				Color color;
			};
		}
	}
}

#endif

