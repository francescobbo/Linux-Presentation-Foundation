#ifndef _LPF_BASICTYPES_H_
#define _LPF_BASICTYPES_H_

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
#ifdef __amd64__
typedef unsigned long ulong;
#else
typedef unsigned long long ulong;
#error wtf
#endif

namespace System
{
	class Object;
	
	typedef void *(*Action)();
	typedef void *(*Action1)(Object &param);
	typedef void *(*Action2)(Object &param1, Object &param2);
	typedef void *(*Action3)(Object &param1, Object &param2, Object &param3);
	typedef void *(*Action4)(Object &param1, Object &param2, Object &param3, Object &param4);
	typedef void *(*Action5)(Object &param1, Object &param2, Object &param3, Object &param4, Object &param5);
	typedef void *(*Action6)(Object &param1, Object &param2, Object &param3, Object &param4, Object &param5, Object &param6);
}

#endif

