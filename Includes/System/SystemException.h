#ifndef _LPF_SYSTEM_SYSTEMEXCEPTION_H_
#define _LPF_SYSTEM_SYSTEMEXCEPTION_H_

#include <System/Exception.h>

namespace System
{
	class SystemException : public Exception
	{
	public:
		SystemException();
		SystemException(String);
		SystemException(String, Exception &inner);
	};
}

#endif

