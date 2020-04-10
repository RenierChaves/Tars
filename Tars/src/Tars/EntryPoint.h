#pragma once

#ifdef TARS_PLATFORM_WINDOWS

extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}

#endif
