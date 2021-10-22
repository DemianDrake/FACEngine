#pragma once

#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define FACENGINE_API __declspec(dllexport)
#else
	#define FACENGINE_API __declspec(dllimport)
#endif