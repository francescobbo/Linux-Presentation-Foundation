#ifndef _LPF_SYSTEM_LINUX_DEPENDENCYOBJECT_H_
#define _LPF_SYSTEM_LINUX_DEPENDENCYOBJECT_H_

#include <System/Linux/Threading/DispatcherObject.h>

namespace System
{
	namespace Linux
	{
		class DependencyObject : public Threading::DispatcherObject
		{
		public:
			DependencyObject();
			
//			ClearValue(DependencyProperty);
//			CoerceValue();
//			GetValue();
//			InvalidateProperty();
//			OnPropertyChanged();
//			ReadLocalValue();
//			SetCurrentValue();
//			SetValue(DependencyProperty, Object);
		};
	}
}

#endif

