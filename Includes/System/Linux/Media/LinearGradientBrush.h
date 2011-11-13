#ifndef _LPF_SYSTEM_LINUX_MEDIA_LINEARGRADIENTBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_LINEARGRADIENTBRUSH_H_

#include <System/Linux/Media/GradientBrush.h>
#include <System/Linux/Media/GradientStopCollection.h>
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
                                LinearGradientBrush(const LinearGradientBrush &copy);
//				LinearGradientBrush(GradientStopCollection);
//				LinearGradientBrush(GradientStopCollection, double);
				LinearGradientBrush(Color start, Color end, double angle);
//				LinearGradientBrush(GradientStopCollection, Point, Point);
				LinearGradientBrush(Color start, Color end, Point startPoint, Point endPoint);

				Point StartPoint;
				Point EndPoint;
                                
                                void SetupContext(Cairo::RefPtr<Cairo::Context> ctx, double w, double h);

                                GradientStopCollection GradientStops;
        		};
		}
	}
}

#endif
