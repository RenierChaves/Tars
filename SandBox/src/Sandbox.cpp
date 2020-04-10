#include <Tars.h>

class SandBox : public Tars::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}
};

Tars::Application* Tars::CreateApplication() {
	return new SandBox();
}