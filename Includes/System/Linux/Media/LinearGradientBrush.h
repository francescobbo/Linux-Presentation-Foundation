#ifndef _LPF_SYSTEM_LINUX_MEDIA_LINEARGRADIENTBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_LINEARGRADIENTBRUSH_H_

#include <System/Linux/Media/GradientBrush.h>
#include <System/Linux/Point.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class LinearGradientBrush : public GradientBrush
			{
			public:
				LinearGradientBrush();
//				LinearGradientBrush(GradientStopCollection);
//				LinearGradientBrush(GradientStopCollection, double);
				LinearGradientBrush(Color, Color, double);
//				LinearGradientBrush(GradientStopCollection, Point, Point);
				LinearGradientBrush(Color, Color, Point, Point);

				Point StartPoint;
				Point EndPoint;
			};
		}
	}
}

#endif

