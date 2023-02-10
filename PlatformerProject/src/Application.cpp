#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Game
{
	Application* Application::s_GameApp = nullptr;

	Application::Application()
	{
		m_IsRunning = true;
		s_GameApp = this;
		m_GameWindow = Window::Create();
	}

	bool Application::Init()
	{
		if (!m_GameWindow->Init())
		{
			ONYX_ERROR("Failed to initialize window");
			return false;
		}
		return true;
	}

	void Application::OnEvent()
	{

	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
		    glfwPollEvents();
			m_GameWindow->Update();
			m_GameWindow->Draw();
		}
	}

	Application::~Application()
	{

	}
}