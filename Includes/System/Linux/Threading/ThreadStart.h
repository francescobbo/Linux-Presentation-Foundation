#ifndef _LPF_SYSTEM_THREADSTART_H_
#define _LPF_SYSTEM_THREADSTART_H_

#include <BasicTypes.h>

namespace System
{
	namespace Linux
	{
		namespace Threading
		{
			class ThreadStart
			{
			public:
				ThreadStart(Action act);
				ThreadStart(Action1 act);
				ThreadStart(Action2 act);
				ThreadStart(Action3 act);
				ThreadStart(Action4 act);
				ThreadStart(Action5 act);
				ThreadStart(Action6 act);
			
				int ArgCount;
				void *functionPtr;
			};
		}
	}
}

#endif

