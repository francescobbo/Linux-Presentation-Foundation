#include <System.h>

/* To use memcpy in MemberwiseCopy */
#include <string.h>

namespace System
{
	Object::Object()
	{
	}
	
	bool Object::Equals(Object &o) const
	{
		return (&o != 0) && GetHashCode() == o.GetHashCode();
	}
	
	bool Object::Equals(Object &o1, Object &o2)
	{
		return (&o1 != 0 && &o2 != 0) && o1.Equals(o2);
	}

	long Object::GetHashCode() const
	{
		/* On different Objects, GetHashCode of .NET returns different (pseudo-random) values. We return the pointer. Seems a good choice */
		return (long) this;
	}

	bool Object::ReferenceEquals(Object &o1, Object &o2)
	{
		return &o1 == &o2;
	}
	
	Type Object::GetType() const
	{
		return Type(*this);
	}

	String Object::ToString() const
	{
		return GetType().Name();
	}

	/* NOTE: Returned object must be DELETED manually! */
	Object &Object::MemberwiseClone() const
	{
		Object *obj = new Object;
		
		/* Replace this ugly function please... */
		memcpy((void *) obj, (const void *) this, sizeof(*this));
		
		return *obj;
	}
	
	void Object::Finalize()
	{
	}
}

