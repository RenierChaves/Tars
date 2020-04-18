#pragma once

#include "tarspch.h"

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Tars {
	class TARS_API Log {
	public:
		static void Init();
		/* 
		Create two static function that return by reference the two shared_ptr of CoreLogger and ClientLogger.
		*/
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		// Create two attributes that will receive the spdlog::logger instance in Log.cpp.
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define TARS_CORE_ERROR(...)	::Tars::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TARS_CORE_WARN(...)		::Tars::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TARS_CORE_INFO(...)		::Tars::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TARS_CORE_TRACE(...)	::Tars::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TARS_CORE_FATAL(...)	::Tars::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TARS_ERROR(...)			::Tars::Log::GetClientLogger()->error(__VA_ARGS__)
#define TARS_WARN(...)			::Tars::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TARS_INFO(...)			::Tars::Log::GetClientLogger()->info(__VA_ARGS__)
#define TARS_TRACE(...)			::Tars::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TARS_FATAL(...)			::Tars::Log::GetClientLogger()->fatal(__VA_ARGS__)
