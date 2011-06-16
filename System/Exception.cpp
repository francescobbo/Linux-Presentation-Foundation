#include <System.h>

namespace System
{
	Exception::Exception() : Object()
	{
		Init();
	}
	
	Exception::Exception(String message) : Object()
	{
		Init();
		this->message = message;
	}
	
	Exception::Exception(String message, Exception &innerException) : Object()
	{
		Init();
		this->message = message;
		this->innerException = &innerException;
	}
	
	void Exception::Init()
	{
		message = 0;
	}
	
	String Exception::Message() const
	{
		return message;
	}

	Exception &Exception::InnerException() const
	{
		return *innerException;
	}
	
	String Exception::Source() const
	{
		return source;
	}
	
	void Exception::Source(String s)
	{
		source = s;
	}
	
	String Exception::StackTrace() const
	{
		throw NotImplementedException();
	}

	Exception &Exception::GetBaseException()
	{
		if (innerException == 0)
			return *this;
		else
			return innerException->GetBaseException();
	}

	String Exception::ToString() const
	{
		return String("Exception: ") + message;
	}
}

