#ifndef _LPF_SYSTEM_CHAR_H_
#define _LPF_SYSTEM_CHAR_H_

namespace System
{
	class Char
	{
	public:
		static bool IsLower(char c)
		{
			return c >= 'a' && c <= 'z';
		}

		static bool IsUpper(char c)
		{
			return c >= 'A' && c <= 'Z';
		}

		static char ToLower(char c)
		{
			if (IsUpper(c))
				return c | 0x20;
			return c;
		}

		static char ToUpper(char c)
		{
			if (IsLower(c))
				return c & ~0x20;
			return c;
		}
	};
}

#endif
