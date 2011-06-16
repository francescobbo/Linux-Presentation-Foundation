#include <System.h>

namespace System
{
	SystemException::SystemException() : Exception()
	{
	}
	
	SystemException::SystemException(String message) : Exception(message)
	{
	}
	
	SystemException::SystemException(String message, Exception &innerException) : Exception(message, innerException)
	{
	}
}

