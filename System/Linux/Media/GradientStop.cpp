#include <System/Linux/Media/GradientStop.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			GradientStop::GradientStop()
			{
			}
			
			GradientStop::GradientStop(Color c, double offset)
			{
				color = c;
				Offset = offset;
			}
			
			GradientStop::GradientStop(const GradientStop &copy)
			{
				*this = copy;
			}
			
			GradientStop &GradientStop::operator=(const GradientStop &copy)
			{
				Offset = copy.Offset;
				color = copy.color;
			}
			
			bool GradientStop::operator==(const GradientStop &cmp) const
			{
				return (Offset == cmp.Offset) && (color == cmp.color);
			}
			
			String GradientStop::ToString() const
			{
				return "";
			}
		}
	}
}