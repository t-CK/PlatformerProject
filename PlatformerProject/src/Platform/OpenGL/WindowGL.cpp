#include "WindowGL.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Game
{
	WindowGL::WindowGL(const WindowProps& props)
	{
		m_Props = props;
	}

	bool WindowGL::Init()
	{
		int result = glfwInit();

		if (!result)
		{
			ONYX_ERROR("Failed to initialize glfw!");
			return false;
		}
		ONYX_INFO("Initialized glfw");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title.c_str(), NULL, NULL);
		if (!m_Window)
		{
			const char* msg;
			glfwGetError(&msg);
			ONYX_ERROR("Failed to create window:\n\t{0}", msg);
			return false;
		}
		ONYX_INFO("Created glfw window");

		glfwMakeContextCurrent(m_Window);

		result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (result == GLFW_FALSE)
		{
			const char* msg;
			glfwGetError(&msg);
			ONYX_ERROR("Failed to initialize glad:\n\t{0}", msg);
			return false;
		}
		ONYX_INFO("Initialized glad");

		return true;
	}

	void WindowGL::Draw()
	{
		glfwSwapBuffers(m_Window);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void WindowGL::Update()
	{
		glClearColor(1.f, 0.5f, 0.5f, 0.f);
	}

	void WindowGL::SetVSync(bool vSync)
	{
		// Set glfw swap interval AKA V-Sync
		vSync ? glfwSwapInterval(1) : glfwSwapInterval(0);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowGL(props);
	}
}