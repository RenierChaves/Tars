#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Tars {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			TARS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			TARS_TRACE(e);
		}
		while (true);
	}


}