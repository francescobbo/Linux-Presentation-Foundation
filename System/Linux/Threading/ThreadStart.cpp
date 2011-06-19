#include <System.h>
#include <System/Linux/Threading.h>

#include <iostream>
using namespace std;

namespace System
{
	namespace Linux
	{
		namespace Threading
		{
			ThreadStart::ThreadStart(Action act)
			{
				cout << "P0" << endl;
			
				functionPtr = (void *) act;
				ArgCount = 0;
			}

			ThreadStart::ThreadStart(Action1 act)
			{
				cout << "P1" << endl;

				functionPtr = (void *) act;
				ArgCount = 1;
			}

			ThreadStart::ThreadStart(Action2 act)
			{
				functionPtr = (void *) act;
				ArgCount = 2;
			}

			ThreadStart::ThreadStart(Action3 act)
			{
				functionPtr = (void *) act;
				ArgCount = 3;
			}

			ThreadStart::ThreadStart(Action4 act)
			{
				functionPtr = (void *) act;
				ArgCount = 4;
			}

			ThreadStart::ThreadStart(Action5 act)
			{
				functionPtr = (void *) act;
				ArgCount = 5;
			}
		
			ThreadStart::ThreadStart(Action6 act)
			{
				functionPtr = (void *) act;
				ArgCount = 6;
			}
		}
	}
}

