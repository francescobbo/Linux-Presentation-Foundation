#ifndef _LPF_SYSTEM_LINUX_MEDIA_BRUSH_H_
#define _LPF_SYSTEM_LINUX_MEDIA_BRUSH_H_

#include <System/Linux/Media/Animation/Animatable.h>
#include <System/IFormattable.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			class Brush : public Animation::Animatable, public IFormattable
			{
			public:
				Brush();
			
				String ToString() const;
			
				double Opacity;
			};
		}
	}
}

#endif

