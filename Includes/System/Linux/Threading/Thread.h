#ifndef _LPF_SYSTEM_LINUX_THREADING_THREAD_H_
#define _LPF_SYSTEM_LINUX_THREADING_THREAD_H_

#include <pthread.h>

namespace System
{
	namespace Linux
	{
		namespace Threading
		{
			class Thread
			{
			public:
				Thread(ThreadStart &);
			
				void Start();
				void Start(Object &p1);
				void Start(Object &p1, Object &p2);
				void Start(Object &p1, Object &p2, Object &p3);
				void Start(Object &p1, Object &p2, Object &p3, Object &p4);
				void Start(Object &p1, Object &p2, Object &p3, Object &p4, Object &p5);
				void Start(Object &p1, Object &p2, Object &p3, Object &p4, Object &p5, Object &p6);
			
				void Abort();
			
			private:
				static void *Run(void *threadParameters);
			
				ThreadStart *ts;
				pthread_t tid;
			};
		}
	}
}

#endif

