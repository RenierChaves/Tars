#include <Tars.h>

class ExampleLayer : public Tars::Layer {
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override {
		TARS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Tars::Event& event) override {
		TARS_TRACE("{0}", event);
	}
};


class SandBox : public Tars::Application {
public:
	SandBox() {
		PushLayer(new ExampleLayer());
	}

	~SandBox() {

	}
};

Tars::Application* Tars::CreateApplication() {
	return new SandBox();
}
