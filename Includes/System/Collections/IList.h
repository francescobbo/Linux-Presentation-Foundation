#pragma once

namespace System
{
    namespace Collections
    {
        template <typename T>
        class IList
        {
        public:
            virtual void Add(T t) = 0;
            virtual void Clear() = 0;
            virtual bool Contains(T t) const = 0;
            virtual int IndexOf(T t) const = 0;
            virtual void Insert(T t) = 0;
            virtual void Remove(T t) = 0;
            virtual void RemoveAt(unsigned int index) = 0;
            
            virtual unsigned int Count() const = 0;
            virtual T &operator[](unsigned int index) = 0;
        };
    }
}
