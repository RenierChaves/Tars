#pragma once

#ifdef TARS_PLATFORM_WINDOWS

/*
	Declares Tars::Createapplication(), but does not define it. 
	Tars::Createapplication() is defined elsewhere, but the program can now use it since it knows what it is (an Tars::Application*).
*/
extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {
	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}

#endif
