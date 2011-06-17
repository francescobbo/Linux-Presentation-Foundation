#ifndef _LPF_SYSTEM_LINUX_FRAMEWORKELEMENT_H_
#define _LPF_SYSTEM_LINUX_FRAMEWORKELEMENT_H_

#include <System/Linux/UIElement.h>

namespace System
{
	namespace Linux
	{
		class FrameworkElement : public UIElement
		{
		public:
			FrameworkElement();
			
			double Width, Height;
			double MinWidth, MinHeight;
			double MaxWidth, MaxHeight;
		};
	}
}

#endif

