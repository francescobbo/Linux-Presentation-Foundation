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

#endif

