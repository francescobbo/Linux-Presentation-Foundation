#ifndef _LPF_SYSTEM_LINUX_MEDIA_RADIALGRADIENTBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_RADIALGRADIENTBRUSH_H_

#include <System/Linux/Media/GradientBrush.h>
#include <System/Linux/Point.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class RadialGradientBrush : public GradientBrush
			{
			public:
				RadialGradientBrush();
//				RadialGradientBrush(GradientStopCollection);
				RadialGradientBrush(Color, Color);

				Point Center;
				Point GradientOrigin;
				
				double RadiusX, RadiusY;
			};
		}
	}
}

#endif

