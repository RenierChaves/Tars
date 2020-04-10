#pragma once
#include "Core.h"

namespace Tars {

	class TARS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLI
	Application* CreateApplication();


}