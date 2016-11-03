#pragma once

#include <extdll.h>
#include <enginecallback.h>

#include <meta_api.h>
#include <h_export.h>

#include "rehlds_api.h"
#include "engine_rehlds.h"

#include "main.h"

#undef DLLEXPORT

#ifdef _WIN32
	#define DLLEXPORT __declspec(dllexport)
	#define NOINLINE __declspec(noinline)
#else
	#define DLLEXPORT __attribute__((visibility("default")))
	#define NOINLINE __attribute__((noinline))
	#define WINAPI
#endif // _WIN32

extern void UTIL_LogPrintf(const char *fmt, ...);
