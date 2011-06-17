#ifndef _LPF_SYSTEM_LINUX_MEDIA_COLOR_H_
#define _LPF_SYSTEM_LINUX_MEDIA_COLOR_H_

#include <BasicTypes.h>
#include <System/IFormattable.h>
#include <System/IEquatable.h>

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			struct Color : IFormattable, IEquatable<Color>
			{
			public:
				Color();
				Color(const Color &);
				
				static Color FromArgb(byte a, byte r, byte g, byte b);
				static Color FromRgb(byte r, byte g, byte b);

				Color &operator=(const Color &);
				bool operator==(Color) const;
				bool operator!=(Color) const;
	
				unsigned int R, G, B, A;
				
				bool Equals(Color c) const;
				String ToString() const;
			};
		}
	}
}

#endif

