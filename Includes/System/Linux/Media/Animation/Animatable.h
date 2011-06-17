#ifndef _LPF_SYSTEM_LINUX_MEDIA_ANIMATION_ANIMATABLE_H_
#define _LPF_SYSTEM_LINUX_MEDIA_ANIMATION_ANIMATABLE_H_

#include <System/Linux/Freezable.h>
#include <System/Linux/Media/Animation/IAnimatable.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			namespace Animation
			{
				class Animatable : public Freezable, public IAnimatable
				{
				public:
					Animatable();
					
					// TODO
				};
			}
		}
	}
}

#endif

