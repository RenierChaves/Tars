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
		std::stringstream test;
		test << "IsInCategory: " << e.IsInCategory(EventCategoryApplication);
		if (e.IsInCategory(EventCategoryApplication)) {
			TARS_TRACE(e);
			TARS_TRACE(test.str());
			TARS_TRACE(e.GetEventType());
			TARS_TRACE(e.GetCategoryFlags());
			TARS_TRACE(e.GetName());
			TARS_TRACE(e.GetWidth());
			TARS_TRACE(e.GetHeight());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			TARS_TRACE(e);
		}
		while (true);
	}


}