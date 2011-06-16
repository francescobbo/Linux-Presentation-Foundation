#include <System.h>

#include <typeinfo>

namespace System
{
	Type::Type(Object o) : Object()
	{
		name = typeid(o).name();
	}
		
	String Type::Name()
	{
		return name;
	}
}

