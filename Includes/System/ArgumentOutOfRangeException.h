#ifndef _LPF_SYSTEM_ARGUMENTOUTOFRANGEEXCEPTION_H_
#define _LPF_SYSTEM_ARGUMENTOUTOFRANGEEXCEPTION_H_

#include <System/ArgumentException.h>

namespace System
{
	class ArgumentOutOfRangeException : public ArgumentException
	{
	public:
		ArgumentOutOfRangeException();
		ArgumentOutOfRangeException(String);
		ArgumentOutOfRangeException(String, Exception &inner);
	};
}

#endif

