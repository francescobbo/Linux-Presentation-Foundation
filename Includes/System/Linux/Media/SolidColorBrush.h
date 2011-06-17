#ifndef _LPF_SYSTEM_LINUX_MEDIA_SOLIDCOLORBRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_SOLIDCOLORBRUSH_H_

#include <System/Linux/Media/Brush.h>
#include <System/Linux/Media/Color.h>

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

				Color color;
			};
		}
	}
}

#endif

