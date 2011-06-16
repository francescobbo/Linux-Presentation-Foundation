#ifndef _LPF_SYSTEM_ARGUMENTEXCEPTION_H_
#define _LPF_SYSTEM_ARGUMENTEXCEPTION_H_

#include <System/SystemException.h>

namespace System
{
	class ArgumentException : public SystemException
	{
	public:
		ArgumentException();
		ArgumentException(String);
		ArgumentException(String, Exception &inner);

		ArgumentException(String, String paramName);
		ArgumentException(String, String paramName, Exception &inner);
		
		String Message() const;
		
	protected:
		String param;
	};
}

#endif

