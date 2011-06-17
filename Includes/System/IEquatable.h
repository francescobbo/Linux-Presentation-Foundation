#ifndef _LPF_SYSTEM_IEQUATABLE_H_
#define _LPF_SYSTEM_IEQUATABLE_H_

namespace System
{
	template<typename T>
	class IEquatable
	{
	public:
		bool Equals(T other) const;
	};
}

#endif

