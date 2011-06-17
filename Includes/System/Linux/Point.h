#ifndef _LPF_SYSTEM_LINUX_POINT_H_
#define _LPF_SYSTEM_LINUX_POINT_H_

namespace System
{
	namespace Linux
	{
		struct Point : public IFormattable
		{
			Point(double x = 0.0, double y = 0.0);
			Point(const Point &);

			Point &operator=(const Point &);
	
			bool operator==(Point p);
			bool operator!=(Point p);

			double X, Y;
	
			void Offset(double offX, double offY);
			
			String ToString() const;
		};
	}
}

#endif

