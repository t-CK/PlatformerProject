#include "WindowGL.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//#include <iostream>

const char* VERTEX =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos, 1.0);\n"
"}\0";

const char* FRAGMENT =
"#version 330 core\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"fragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
"}\0";

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
		
		unsigned int VAO, VBO, EBO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO); 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecies), indecies, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &VERTEX, NULL);
		glCompileShader(vertexShader);

		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::SHADER::VERTEX::COMPILATION FAILED:\n\t{0}", infoLog);
		}
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &FRAGMENT, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION FAILED:\n\t{0}", infoLog);
		}

		unsigned int program = glCreateProgram();
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glGetProgramiv(program, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(vertexShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::PROGRAM::COMPILATION:\n\t{0}", infoLog);
		}

		glLinkProgram(program);
		glValidateProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::PROGRAM::LINKING:\n\t{0}", infoLog);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		glUseProgram(program);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(m_Window);
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