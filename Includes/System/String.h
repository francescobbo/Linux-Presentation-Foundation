#ifndef _LPF_SYSTEM_STRING_H_
#define _LPF_SYSTEM_STRING_H_

#include <vector>

namespace System
{
	class String
	{
	public:
		String();
		String(const String &copy);
		String(const char *str);
		String(char c, size_t n);
		String(const String &orig, int startIndex, int length);
		~String();

		String &operator=(const String &copy);
		String &operator+=(const String &app);

		size_t Length() const;

		bool operator==(const String &op) const;
		bool operator!=(const String &op) const;
		bool operator==(const char *op) const;
		bool operator!=(const char *op) const;
		String operator+(const String &op) const;

		operator const char *() const;
		char operator[](size_t index) const;

		const static String Empty;

		bool Contains(char c) const;
		bool Contains(String str) const;

		bool EndsWith(String str) const;

		int IndexOf(char c) const;
		int IndexOf(char c, int startIndex) const;
		int IndexOf(char c, int startIndex, int length) const;
		int IndexOf(String str) const;
		int IndexOf(String str, int startIndex) const;
		int IndexOf(String str, int startIndex, int lenght) const;

		String Insert(unsigned int startIndex, String value) const;

#if 0
		static String Join(std::vector<String> strs, String sep);
#endif

		String Remove(int startIndex) const;
		String Remove(int startIndex, int length) const;

		String Replace(char oldChar, char newChar) const;
		String Replace(String oldS, String newS) const;

#if 0
		std::vector<String> Split(String sep) const;
#endif

		bool StartsWith(String str) const;

		String Substring(unsigned int startIndex) const;
		String Substring(unsigned int startIndex, unsigned int length) const;

		String ToLower() const;
		String ToUpper() const;

		String Trim(String remove = Empty) const;
		String TrimStart(String remove = Empty) const;
		String TrimEnd(String remove = Empty) const;

	private:
		char *buff;
	};
}

#endif

