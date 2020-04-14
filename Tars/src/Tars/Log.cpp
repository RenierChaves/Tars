#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Tars {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	// The Init function assign values to the shared_ptr.
	void Log::Init() {
		spdlog::set_pattern("%^[%t] %n: %v%$");

		// Create a logger for TARS and assing its shared_ptr value to s_CoreLogger.
		s_CoreLogger = spdlog::stdout_color_mt("TARS"); 
		s_CoreLogger->set_level(spdlog::level::trace);

		// Create a logger for TARS and assing its shared_ptr value to s_ClientLogger.
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}
}
