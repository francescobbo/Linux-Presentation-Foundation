#ifndef _LPF_SYSTEM_TYPE_H_
#define _LPF_SYSTEM_TYPE_H_

#include <System.h>

#include <typeinfo>

namespace System
{
	class Type : public Object
	{
	public:
		Type(Object o);		
		String Name();
		
	private:
		String name;
	};
}

#endif

