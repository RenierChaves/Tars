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

#ifdef TARS_ENABLED_ASSERTS
	#define TARS_ASSERT(x, ...) {if(!(x)) { TARS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak() } }
	#define TARS_CORE_ASSERT(x, ...) {if(!(x)) { TARS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak() } }
#else
	#define TARS_ASSERT(x, ...)
	#define TARS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)