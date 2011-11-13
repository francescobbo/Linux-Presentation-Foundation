#include <System.h>

/* libc support */
#include <string.h>

namespace System
{
	const String String::Empty = "";

	String::String()
	{
		buff = 0;
		*this = Empty;
	}

	String::String(const String &copy)
	{
		buff = 0;
		*this = copy;
	}

	String::String(const char *s)
	{
		buff = 0;
		if (!s)
			*this = Empty;

		buff = new char[strlen(s) + 1];
		strcpy(buff, s);
	}

	String::String(char c, unsigned int n)
	{
		buff = 0;
		if (n == 0)
			*this = Empty;
		else
		{
			buff = new char[n + 1];
			memset(buff, c, n);
		}
	}

	String::String(const String &src, int startIndex, int length)
	{
		buff = 0;
		*this = src.Substring(startIndex, length);
	}

	String::~String()
	{
		if (buff != 0)
			delete[] buff;
	}

	String &String::operator=(const String &copy)
	{
		if (&copy == this)
			return *this;

		unsigned int len = copy.Length();

		if (buff != 0)
			delete[] buff;
		buff = new char[len + 1];

		// Let's do the dirty work
		strcpy(buff, copy.buff);

		return *this;
	}

	String &String::operator+=(const String &append)
	{
		*this = *this + append;
		return *this;
	}

	bool String::operator==(const String &cmp) const
	{
		return strcmp(buff, cmp.buff) == 0;
	}

	bool String::operator==(const char *cmp) const
	{
		return strcmp(buff, cmp) == 0;
	}

	bool String::operator!=(const String &cmp) const
	{
		return !(*this == cmp);
	}

	bool String::operator!=(const char *cmp) const
	{
		return !(*this == cmp);
	}

	String String::operator+(const String &add) const
	{
		if (!buff)
			return String(add);

		unsigned int thisLen = Length();
		unsigned int addLen = add.Length();

		unsigned int totLen = thisLen + addLen;
		char *tmpBuff = new char[totLen + 1];

		if (buff)
			strcpy(tmpBuff, buff);
		strcpy(tmpBuff + thisLen, add.buff);

		String ret(tmpBuff);
		delete[] tmpBuff;
		return ret;
	}

	char String::operator[](unsigned int index) const
	{
		if (index >= Length())
			throw ArgumentOutOfRangeException();

		return buff[index];
	}

	bool String::Contains(char c) const
	{
		return IndexOf(c) >= 0;
	}

	bool String::Contains(String str) const
	{
		return IndexOf(str) >= 0;
	}

	bool String::EndsWith(String str) const
	{
		if (str == Empty)
			return true;

		if (!buff)
			return false;

		unsigned int thisLen = Length(), strLen = str.Length();
		if (thisLen < strLen)
			return false;

		unsigned int begin = thisLen - strLen;
		if (!strcmp(buff + begin, str.buff))
			return true;
		return false;
	}

	unsigned int String::Length() const
	{
		if (buff)
			return strlen(buff);
		else
			return 0;
	}
	
	String::operator const char *() const
	{
		return buff;
	}

	int String::IndexOf(char c) const
	{
		char *p = buff;
		while (*p)
		{
			if (*p == c)
				return p - buff;
			*p++;
		}

		return -1;
	}

	int String::IndexOf(String str) const
	{
		if (str == Empty)
			return 0;

		if (!buff)
			return -1;

		/* ASDFG can't be contained in ASD. It's too long */
		unsigned int thisLen = Length(), strLen = str.Length();
		if (thisLen < strLen)
			return -1;

		/* It's waste of time to check for ASD in the last two characters... */
		unsigned int maxTest = thisLen - strLen + 1;
		for (unsigned int i = 0; i < maxTest; i++)
		{
			if (!strncmp(buff + i, str.buff, strLen))
				return i;
		}

		return -1;
	}

	int String::IndexOf(char c, int startIndex) const
	{
		int ret = Substring(startIndex).IndexOf(c);
		return (ret == -1) ? -1 : ret + startIndex;
	}

	int String::IndexOf(String str, int startIndex) const
	{
		int ret = Substring(startIndex).IndexOf(str);
		return (ret == -1) ? -1 : ret + startIndex;
	}

	int String::IndexOf(char c, int startIndex, int length) const
	{
		int ret = Substring(startIndex, length).IndexOf(c);
		return (ret == -1) ? -1 : ret + startIndex;
	}

	int String::IndexOf(String str, int startIndex, int length) const
	{
		int ret = Substring(startIndex, length).IndexOf(str);
		return (ret == -1) ? -1 : ret + startIndex;
	}

	String String::Insert(unsigned int startIndex, String value) const
	{
		if (startIndex > Length())
			throw ArgumentOutOfRangeException();

		String ret = Substring(0, startIndex);
		String end = Substring(startIndex);
		ret += value + end;
		return ret;
	}

#if 0
	String String::Join(std::vector<String> strs, String sep)
	{
		String ret = "";
		for (auto it = strs.begin(); it != strs.end(); it++)
		{
			if (it != strs.begin())
				ret += sep;

			ret += *it;
		}

		return ret;
	}
#endif

	String String::Remove(int firstIndex) const
	{
		return Substring(0, firstIndex);
	}

	String String::Remove(int firstIndex, int length) const
	{
		return Substring(0, firstIndex) + Substring(firstIndex + length);
	}

	String String::Replace(char oldC, char newC) const
	{
		if (!buff)
			return Empty;

		int len = Length();
		char *tmpBuff = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			tmpBuff[i] = (buff[i] == oldC) ? newC : buff[i];
		}
		tmpBuff[len] = 0;

		String ret(tmpBuff);
		delete[] tmpBuff;
		return ret;
	}

	String String::Replace(String oldS, String newS) const
	{
		if (oldS == newS)
			return *this;

		String ret = *this;

		int pos = 0;
		while ((pos = ret.IndexOf(oldS)) >= 0)
		{
			ret = ret.Remove(pos, oldS.Length());
			ret = ret.Insert(pos, newS);			
		}

		return ret;
	}

#if 0
	std::vector<String> String::Split(String sep) const
	{
		if (sep == Empty)
			sep = " ";

		String tmp = *this;
		std::vector<String> ret;

		int pos = tmp.IndexOf(sep);
		while (pos >= 0)
		{
			ret.push_back(tmp.Substring(0, pos));
			tmp = tmp.Substring(pos + sep.Length());
			pos = tmp.IndexOf(sep);
		}

		ret.push_back(tmp);

		return ret;
	}
#endif

	bool String::StartsWith(String str) const
	{
		if (str == Empty)
			return true;

		if (!buff)
			return false;

		return strncmp(buff, str.buff, str.Length()) == 0;
	}

	String String::Substring(unsigned int startIndex) const
	{
		if (!buff || startIndex > Length())
			throw ArgumentOutOfRangeException();

		int length = Length() - startIndex;
		return Substring(startIndex, length);
	}

	String String::Substring(unsigned int startIndex, unsigned int length) const
	{
		if (!buff || (startIndex + length) > Length())
			throw ArgumentOutOfRangeException();

		char *tmpBuff = new char[length + 1];
		strncpy(tmpBuff, buff + startIndex, length);
		tmpBuff[length] = 0;

		String ret(tmpBuff);
		delete[] tmpBuff;

		return ret;
	}

	String String::ToLower() const
	{
		unsigned int l = Length();
		char *tmpBuff = new char[l + 1];
		for (unsigned int i = 0; i < l; i++)
		{
			tmpBuff[i] = Char::ToLower(buff[i]);
		}
		tmpBuff[l] = 0;

		String ret(tmpBuff);
		delete[] tmpBuff;
		return ret;
	}

	String String::ToUpper() const
	{
		unsigned int l = Length();
		char *tmpBuff = new char[l + 1];
		for (unsigned int i = 0; i < l; i++)
		{
			tmpBuff[i] = Char::ToUpper(buff[i]);
		}
		tmpBuff[l] = 0;

		String ret(tmpBuff);
		delete[] tmpBuff;
		return ret;
	}

	String String::Trim(String remove) const
	{
		String noStart = TrimStart(remove);
		return noStart.TrimEnd(remove);
	}

	String String::TrimStart(String remove) const
	{
		if (!buff)
			return Empty;

		if (remove == Empty)
			remove = " \n\r\t";

		int newFirst = 0;
		while (remove.IndexOf(buff[newFirst]) >= 0)
			newFirst++;

		return Substring(newFirst);
	}

	String String::TrimEnd(String remove) const
	{
		if (!buff)
			return Empty;

		if (remove == Empty)
			remove = " \n\r\t";

		int newLength = Length();
		while (remove.IndexOf(buff[newLength]) >= 0)
			newLength--;

		return Substring(0, newLength);
	}
}

