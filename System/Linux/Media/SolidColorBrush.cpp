#include <System/Linux/Media/SolidColorBrush.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			SolidColorBrush::SolidColorBrush() : Brush()
			{
			}

			SolidColorBrush::SolidColorBrush(Color color) : Brush()
			{
				this->color = color;
			}
		}
	}
}
