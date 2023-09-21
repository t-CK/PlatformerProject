#include "WindowGL.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Game
{
	// glfw ErrorCallback
	static void glfwErrorCallback(int errorCode, const char* errorMessage)
	{
		ONYX_ERROR("glfw Error [{0}]: {1}", errorCode, errorMessage);
	}

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

		// Set glfw ErrorCallback
		glfwSetErrorCallback(glfwErrorCallback);

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

		glClearColor(1.f, 0.5f, 0.5f, 0.f);

		return true;
	}

	void WindowGL::Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		float vertecies[] = {
			// position		 
			0.0f,  0.5f, 0.0f, // Top
			0.5f, -0.5f, 0.0f, // right
		   -0.5f, -0.5f, 0.0f  // left
		};

		unsigned int indecies[] = {
			0, 1, 2
		};

		Renderer::VAO vao;
		
		Renderer::VBO vbo(vertecies, sizeof(vertecies));

		Renderer::EBO ebo(indecies, 3);

		glEnableVertexAttribArray(0);


		Renderer::Shader shader("assets/vertexShader.glsl", "assets/fragmentShader.glsl");

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		shader.Activate();

		ebo.Bind();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(m_Window);
	}

	void WindowGL::Update()
	{
		
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