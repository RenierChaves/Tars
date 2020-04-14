#pragma once

#ifdef TARS_PLATFORM_WINDOWS

/*
	Declares Tars::Createapplication(), but does not define it. 
	Tars::Createapplication() is defined elsewhere, but the program can now use it since it knows what it is (an Tars::Application*).
*/
extern Tars::Application* Tars::CreateApplication();

int main(int argc, char** argv) {

	Tars::Log::Init();
	TARS_CORE_WARN("Initialized Log");
	int a = 5;
	TARS_INFO("Initialized Log, Var={0}", a);

	auto app = Tars::CreateApplication();
	app->Run();
	delete app;
}

#endif
