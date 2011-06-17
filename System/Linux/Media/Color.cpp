#include <System/Linux/Media/Color.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			Color::Color()
			{
				R = G = B = A = 0;
			}

			Color::Color(const Color &copy)
			{
				*this = copy;
			}

			Color &Color::operator=(const Color &copy)
			{
				R = copy.R;
				G = copy.G;
				B = copy.B;
				A = copy.A;
	
				return *this;
			}

			Color Color::FromArgb(byte a, byte r, byte g, byte b)
			{
				Color c;
				c.A = a;
				c.R = r;
				c.G = g;
				c.B = b;
				
				return c;
			}

			Color Color::FromRgb(byte r, byte g, byte b)
			{
				Color c;
				c.A = 0xFF;
				c.R = r;
				c.G = g;
				c.B = b;
				
				return c;
			}

			bool Color::Equals(Color c) const
			{
				return *this == c;
			}

			bool Color::operator==(Color c) const
			{
				return A == c.A && R == c.R && G == c.G && B == c.B;
			}
			
			bool Color::operator!=(Color c) const
			{
				return !(*this == c);
			}
			
			String Color::ToString() const
			{
				/* TODO: Need conversion to hexadecimal... */
				//return String("#") + R + G + B + A;
				return String("#RRGGBBAA");
			}
		}
	}
}

