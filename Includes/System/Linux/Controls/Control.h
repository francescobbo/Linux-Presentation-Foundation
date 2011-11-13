#ifndef _LPF_SYSTEM_LINUX_CONTROLS_CONTROL_H_
#define _LPF_SYSTEM_LINUX_CONTROLS_CONTROL_H_

#include <System/Linux/FrameworkElement.h>
#include <System/Linux/Media/Brush.h>

namespace System
{
	namespace Linux
	{
		namespace Controls
		{
			class Control : public FrameworkElement
			{
			public:
				Control();

				Media::Brush *Background;
			};
		}
	}
}

#endif

