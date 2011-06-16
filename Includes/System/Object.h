#ifndef _LPF_SYSTEM_OBJECT_H_
#define _LPF_SYSTEM_OBJECT_H_

namespace System
{
	class Type;
	class String;

	class Object
	{
	public:
		Object();
	
		virtual bool Equals(Object &) const;
		static bool Equals(Object &, Object &);
		virtual long GetHashCode() const;
		static bool ReferenceEquals(Object &, Object &);

		/* TODO: Implement Type and String */
		Type GetType() const;
		virtual String ToString() const;

	protected:
		Object &MemberwiseClone() const;
		virtual void Finalize();
	};
}

#endif

