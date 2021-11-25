#pragma once

#ifdef WIN32

#include <Windows.h>
#include <cstdio>
#include <iostream>

#endif

#ifdef BUILD_DLL
	#define FACENGINE_API __declspec(dllexport)
#else
	#define FACENGINE_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#include "common/Logger.h"
#include "common/Time.h"
#include "core/PerGameSettings.h"