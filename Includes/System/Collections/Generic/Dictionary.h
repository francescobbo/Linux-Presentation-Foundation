#ifndef _LPF_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H_
#define _LPF_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H_

#include <map>
#include <System/Exception.h>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename TKey, typename TValue>
			class Dictionary
			{
			public:
				Dictionary() : Map()
				{
				}
				
				void Add(TKey key, TValue value)
				{
					Map.insert(std::pair<TKey, TValue>(key, value));
				}
				
				void Clear()
				{
					Map.clear();
				}

				bool ContainsKey(TKey key)
				{
					typename std::map<TKey, TValue>::iterator it = Map.find(key);
					return it != Map.end();
				}

				bool ContainsValue(TValue value)
				{
					for (typename std::map<TKey, TValue>::iterator it = Map.begin(); it != Map.end(); it++)
					{
						if ((*it)->second == value)
							return true;
					}
				
					return false;
				}
				
				TValue &operator[](TKey key)
				{
					if (!ContainsKey(key))
						throw System::Exception();
					return Map[key];
				}

			private:
				std::map<TKey, TValue> Map;
			};
		}
	}
}

#endif

