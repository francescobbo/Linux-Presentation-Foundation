#ifndef _LPF_SYSTEM_NOTIMPLEMENTEDEXCEPTION_H_
#define _LPF_SYSTEM_NOTIMPLEMENTEDEXCEPTION_H_

#include <System/SystemException.h>

namespace System
{
	class NotImplementedException : public SystemException
	{
	public:
		NotImplementedException();
		NotImplementedException(String);
		NotImplementedException(String, Exception &inner);
	};
}

#endif

