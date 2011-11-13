#include <System/Linux/Point.h>

namespace System
{
	namespace Linux
	{
		Point::Point(double x, double y)
		{
			X = x;
			Y = y;
		}
		
		Point::Point(const Point &copy)
		{
			*this = copy;
		}
		
		Point &Point::operator=(const Point &copy)
		{
			X = copy.X;
			Y = copy.Y;
		}
		
		String Point::ToString() const
		{
			return String("[]");
		}
	}
}

