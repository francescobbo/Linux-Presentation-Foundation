#ifndef _LPF_SYSTEM_EXCEPTION_H_
#define _LPF_SYSTEM_EXCEPTION_H_

#include <System/Exception.h>

namespace System
{
	class Exception : public Object
	{
	public:
		/* Constructors */
		Exception();
		Exception(String);
		Exception(String, Exception &inner);

		/* Properties */
		virtual String Message() const;
		virtual Exception &InnerException() const;
		virtual String Source() const;
		virtual void Source(String s);
		virtual String StackTrace() const;

		/* Methods */
		virtual Exception &GetBaseException();
		virtual String ToString() const;

	private:
		void Init();
	
	protected:	
		String message;
		String source;
				
		Exception *innerException;
	};
}

#endif

