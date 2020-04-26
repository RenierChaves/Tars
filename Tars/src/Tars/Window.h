#pragma once

#include "tarspch.h"

#include "Tars/Core.h"
#include "Tars/Events/Event.h"

namespace Tars {

	// All-platform basic properties from a window.
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Tars Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system based Window
	class TARS_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		// EventCallbackFn is new type, that stores a function that receives
		// a Event& as a parameter and return void.

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
