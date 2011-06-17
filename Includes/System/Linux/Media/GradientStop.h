#ifndef _LPF_SYSTEM_LINUX_MEDIA_GRADIENTSTOP_H_
#define _LPF_SYSTEM_LINUX_MEDIA_GRADIENTSTOP_H_

#include <System/Linux/Media/Color.h>
#include <System/Linux/Media/Animation/Animatable.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class GradientStop : public Animation::Animatable, public IFormattable
			{
			public:
				GradientStop();
				GradientStop(const GradientStop &);
				GradientStop(Color color, double offset);
	
				GradientStop &operator=(const GradientStop &);

				Media::Color color;
				double Offset;
				
				String ToString() const;
			};
		}
	}
}

#endif

