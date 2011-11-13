#pragma once

#include <System/Linux/Media/GradientStop.h>
#include <System/Collections/IList.h>

#include <list>

namespace System
{
    namespace Linux
    {
        namespace Media
        {
            class GradientStopCollection : Collections::IList<GradientStop>
            {
            public:
                void Add(GradientStop s);
                void Clear();
                bool Contains(GradientStop s) const;
                int IndexOf(GradientStop s) const;
                void Insert(GradientStop s);
                void Remove(GradientStop s);
                void RemoveAt(unsigned int index);
                
                unsigned int Count() const;
                GradientStop &operator[](unsigned int);
                
            private:
                std::list<GradientStop> list;
            };
        }
    }
}