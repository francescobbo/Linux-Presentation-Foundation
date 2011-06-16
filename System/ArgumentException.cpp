#include <System.h>

namespace System
{
	ArgumentException::ArgumentException() : SystemException()
	{
	}
	
	ArgumentException::ArgumentException(String message) : SystemException(message)
	{
	}
	
	ArgumentException::ArgumentException(String message, Exception &innerException) : SystemException(message, innerException)
	{
	}
	
	ArgumentException::ArgumentException(String message, String paramName) : SystemException(message)
	{
		param = paramName;
	}
	
	ArgumentException::ArgumentException(String message, String paramName, Exception &inner) : SystemException(message, inner)
	{
		param = paramName;
	}
	
	String ArgumentException::Message() const
	{
		String ret = message;
		if (param != String::Empty)
			ret += String("\n") + param;
		
		return ret;
	}
}

