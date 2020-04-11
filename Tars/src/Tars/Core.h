#pragma once

#ifdef TARS_PLATFORM_WINDOWS
	#ifdef TARS_BUILD_DLL
		#define TARS_API __declspec(dllexport)
	#else
		#define TARS_API __declspec(dllimport)
	#endif
#else
	#error Tars only supports Windows!
#endif