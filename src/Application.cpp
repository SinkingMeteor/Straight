#include "Application.h"

namespace Straight
{
	Application::Application(HINSTANCE hInstance) :
		m_window(),
		m_renderer(),
		m_hInstance(hInstance)
	{

	}

	Application::~Application()
	{

	}

	bool Application::Initialize()
	{
		m_window = std::make_unique<Window>(this);
		return m_window->Initialize(640, 360);
	}

	void Application::Run()
	{

	}

	void Application::Dispose()
	{

	}

}