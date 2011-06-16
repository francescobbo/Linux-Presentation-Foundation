#include <System.h>

namespace System
{
	ArgumentOutOfRangeException::ArgumentOutOfRangeException() : ArgumentException()
	{
	}
	
	ArgumentOutOfRangeException::ArgumentOutOfRangeException(String message) : ArgumentException(message)
	{
	}
	
	ArgumentOutOfRangeException::ArgumentOutOfRangeException(String message, Exception &innerException) : ArgumentException(message, innerException)
	{
	}
}

