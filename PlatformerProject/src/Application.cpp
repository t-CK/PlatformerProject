#include "Application.h"

namespace Game
{
	Application* Application::s_GameApp = nullptr;

	Application::Application()
	{
		m_IsRunning = true;
		s_GameApp = this;
	}

	bool Application::Init()
	{

		return true;
	}

	void Application::Run()
	{
		while (m_IsRunning);
	}

	Application::~Application()
	{

	}
}