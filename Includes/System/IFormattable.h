#ifndef _LPF_SYSTEM_IFORMATTABLE_H_
#define _LPF_SYSTEM_IFORMATTABLE_H_

#include <System.h>

namespace System
{
	class IFormattable
	{
	public:
		virtual String ToString() const = 0;
	};
}

#endif

