#include <System.h>

namespace System
{
	NotImplementedException::NotImplementedException() : SystemException()
	{
	}
	
	NotImplementedException::NotImplementedException(String message) : SystemException(message)
	{
	}
	
	NotImplementedException::NotImplementedException(String message, Exception &innerException) : SystemException(message, innerException)
	{
	}
}

