#include <System/Linux/Media/GradientStopCollection.h>

#include "System/Linux/Media/GradientBrush.h"

namespace System
{
	namespace Linux
	{
		namespace Media
		{
			void GradientStopCollection::Add(GradientStop s)
			{
				list.push_back(s);
			}
			
			void GradientStopCollection::Clear()
			{
				list.clear();
			}
			
			bool GradientStopCollection::Contains(GradientStop s) const
			{
				return IndexOf(s) != -1;
			}
			
			int GradientStopCollection::IndexOf(GradientStop s) const
			{
				int pos = 0;
				for (std::list<GradientStop>::const_iterator it = list.begin(); it != list.end(); it++)
				{
					if (*it == s)
						return pos;
					pos++;
				}
				
				return -1;
			}

			void GradientStopCollection::Insert(GradientStop s)
			{
			}
			
			void GradientStopCollection::Remove(GradientStop s)
			{
				list.remove(s);
			}
			
			void GradientStopCollection::RemoveAt(unsigned int index)
			{
				std::list<GradientStop>::iterator it = list.begin();
				std::advance(it, index);
				list.erase(it);
			}
			
			unsigned int GradientStopCollection::Count() const
			{
				return list.size();
			}
			
			GradientStop &GradientStopCollection::operator[](unsigned int index)
			{
				std::list<GradientStop>::iterator it = list.begin();
				std::advance(it, index);
				return *it;
			}
		}
	}
}