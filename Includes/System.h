#ifndef _LPF_SYSTEM_H_
#define _LPF_SYSTEM_H_

typedef unsigned char byte;
typedef unsigned short int ushort;
typedef unsigned int uint;
#ifdef __64bit__
typedef unsigned long ulong;
#else
typedef unsigned long long ulong;
#endif

#include <System/Object.h>
#include <System/Char.h>
#include <System/String.h>
#include <System/Exception.h>
#include <System/SystemException.h>
#include <System/ArgumentException.h>
#include <System/ArgumentOutOfRangeException.h>
#include <System/NotImplementedException.h>
#include <System/Type.h>

using namespace System;

#endif

