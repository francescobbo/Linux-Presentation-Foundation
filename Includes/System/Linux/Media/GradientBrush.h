#ifndef _LPF_SYSTEM_LINUX_MEDIA_GRADIENTBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_GRADIENTBRUSH_H_

#include <System/Linux/Media/Brush.h>
#include <System/Linux/Media/GradientStop.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class GradientBrush : public Brush
			{
			public:
				GradientBrush();
//				GradientBrush(std::list<GradientStop> list);
			
//				std::list<GradientStop> GradientStops;
			};
		}
	}
}

#endif

