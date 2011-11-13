#include <System/Linux/Controls/Control.h>
#include <System/Linux/Media/SolidColorBrush.h>
#include <System/Linux/Media/Brushes.h>

namespace System
{
	namespace Linux
	{
		namespace Controls
		{
			Control::Control() : FrameworkElement()
			{
				Background = new Media::SolidColorBrush(Media::Brushes::White);
			}
		}
	}
}

