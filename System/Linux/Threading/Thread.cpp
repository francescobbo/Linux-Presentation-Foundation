#include <System/Linux/Threading.h>

#include <iostream>
using namespace std;

namespace System
{
	namespace Linux
	{
		namespace Threading
		{
			struct ThreadParam
			{
				ThreadParam(ThreadStart *ts)
				{					
					this->ts = ts;
				}
			
				ThreadParam(ThreadStart *ts, Object &p1)
				{
					this->p1 = (void *) &p1;
					
					this->ts = ts;
				}
				
				ThreadParam(ThreadStart *ts, Object &p1, Object &p2)
				{
					this->p1 = (void *) &p1;
					this->p2 = (void *) &p2;
					
					this->ts = ts;
				}
				
				ThreadParam(ThreadStart *ts, Object &p1, Object &p2, Object &p3)
				{
					this->p1 = (void *) &p1;
					this->p2 = (void *) &p2;
					this->p3 = (void *) &p3;
					
					this->ts = ts;
				}
				
				ThreadParam(ThreadStart *ts, Object &p1, Object &p2, Object &p3, Object &p4)
				{
					this->p1 = (void *) &p1;
					this->p2 = (void *) &p2;
					this->p3 = (void *) &p3;
					this->p4 = (void *) &p4;
					
					this->ts = ts;
				}
				
				ThreadParam(ThreadStart *ts, Object &p1, Object &p2, Object &p3, Object &p4, Object &p5)
				{
					this->p1 = (void *) &p1;
					this->p2 = (void *) &p2;
					this->p3 = (void *) &p3;
					this->p4 = (void *) &p4;
					this->p5 = (void *) &p5;
					
					this->ts = ts;
				}
				
				ThreadParam(ThreadStart *ts, Object &p1, Object &p2, Object &p3, Object &p4, Object &p5, Object &p6)
				{
					this->p1 = (void *) &p1;
					this->p2 = (void *) &p2;
					this->p3 = (void *) &p3;
					this->p4 = (void *) &p4;
					this->p5 = (void *) &p5;
					this->p6 = (void *) &p6;
					
					this->ts = ts;
				}
			
				void *p1, *p2, *p3, *p4, *p5, *p6;
				ThreadStart *ts;
			};

			Thread::Thread(ThreadStart &ts)
			{
				this->ts = &ts;
			}

			void Thread::Abort()
			{
				pthread_cancel(tid);
			}
			
			void Thread::Start()
			{
				ThreadParam *tp = new ThreadParam(ts);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}

			void Thread::Start(Object &p1)
			{
				ThreadParam *tp = new ThreadParam(ts, p1);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void Thread::Start(Object &p1, Object &p2)
			{
				ThreadParam *tp = new ThreadParam(ts, p1, p2);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void Thread::Start(Object &p1, Object &p2, Object &p3)
			{
				ThreadParam *tp = new ThreadParam(ts, p1, p2, p3);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void Thread::Start(Object &p1, Object &p2, Object &p3, Object &p4)
			{
				ThreadParam *tp = new ThreadParam(ts, p1, p2, p3, p4);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void Thread::Start(Object &p1, Object &p2, Object &p3, Object &p4, Object &p5)
			{
				ThreadParam *tp = new ThreadParam(ts, p1, p2, p3, p4, p5);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void Thread::Start(Object &p1, Object &p2, Object &p3, Object &p4, Object &p5, Object &p6)
			{
				ThreadParam *tp = new ThreadParam(ts, p1, p2, p3, p4, p5, p6);
				pthread_create(&tid, NULL, Run, (void *) tp);
				pthread_detach(tid);
			}
			
			void *Thread::Run(void *param)
			{
				ThreadParam *tp = (ThreadParam *) param;

				Object *p1 = (Object *) tp->p1;
				Object *p2 = (Object *) tp->p2;
				Object *p3 = (Object *) tp->p3;
				Object *p4 = (Object *) tp->p4;
				Object *p5 = (Object *) tp->p5;
				Object *p6 = (Object *) tp->p6;

				ThreadStart *ts = tp->ts;

				cout << "Running with parm: " << p1 << ". ArgCount: " << ts->ArgCount << endl;

				delete tp;

				switch (ts->ArgCount)
				{
					case 0:
					{
						Action a = (Action) ts->functionPtr;
						a();
						break;
					}
					case 1:
					{
						cout << "Final p1: " << p1 << ". ArgCount: " << ts->ArgCount << endl;
						Action1 a = (Action1) ts->functionPtr;
						a(*p1);
						break;
					}
					case 2:
					{
						Action2 a = (Action2) ts->functionPtr;
						a(*p1, *p2);
						break;
					}
					case 3:
					{
						Action3 a = (Action3) ts->functionPtr;
						a(*p1, *p2, *p3);
						break;
					}
					case 4:
					{
						Action4 a = (Action4) ts->functionPtr;
						a(*p1, *p2, *p3, *p4);
						break;
					}
					case 5:
					{
						Action5 a = (Action5) ts->functionPtr;
						a(*p1, *p2, *p3, *p4, *p5);
						break;
					}
					case 6:
					{
						Action6 a = (Action6) ts->functionPtr;
						a(*p1, *p2, *p3, *p4, *p5, *p6);
						break;
					}
				}
				
				pthread_exit(NULL);
			}
		}
	}
}

