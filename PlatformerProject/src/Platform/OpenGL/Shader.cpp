#include "Shader.h"
#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>

namespace Renderer
{
	Shader::Shader(const char* veretexPath, const char* FragmentPath)
	{
		// Create vertex and fragment shaders in gpu
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Load vertex shader file into vertexSource variable
		std::string vertexSource = LoadShader(veretexPath);

		{
			// Convert vertexSource to c_str
			const char* shaderData = vertexSource.c_str();
			// Load shader source into gpu
			glShaderSource(vertexShader, 1, &shaderData, NULL);
		}
		// Compile shader
		glCompileShader(vertexShader);

		// Perform error checking to vertex shader
		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::SHADER::VERTEX::COMPILATION FAILED:\n\t{0}", infoLog);
		}

		// Load fragment shader source into file
		std::string fragmentSource = LoadShader(FragmentPath);
		{
			// Cast fragment shader data to c_str
			const char* shaderData = fragmentSource.c_str();
			// Load fragment data into gpu
			glShaderSource(fragmentShader, 1, &shaderData, NULL);
		}
		// Compile fragment shader
		glCompileShader(fragmentShader);

		// Perform error checking to fragment shader
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION FAILED:\n\t{0}", infoLog);
		}

		// Create shader program and save programs ID to class into m_RendererID variable
		m_RendererID = glCreateProgram();
		glAttachShader(m_RendererID, vertexShader);
		glAttachShader(m_RendererID, fragmentShader);

		// Perform error check to shader program
		glGetProgramiv(m_RendererID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(vertexShader, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::PROGRAM::COMPILATION:\n\t{0}", infoLog);
		}

		// Link shader program and validate it
		glLinkProgram(m_RendererID);
		glValidateProgram(m_RendererID);

		// Perform error checking for program linking
		glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_RendererID, 512, NULL, infoLog);
			ONYX_ERROR("ERROR::PROGRAM::LINKING:\n\t{0}", infoLog);
		}
		// Delete shaders from memory as they have been loaded into gpu and we don't need them any more as unsigned integers
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	std::string Shader::LoadShader(const char* shaderPath)
	{
		// Open an input stream from file using filepath passed as parameter
		std::ifstream shaderSrc;
		shaderSrc.open(shaderPath);
		// Verify that file is open, return false otherwise
		if (!shaderSrc.is_open())
		{
			ONYX_ERROR("Failed to load shader {0}", shaderPath);
			return "";
		}

		// Open stringstream and read in content of the file 
		std::string line;
		std::stringstream retStr;
		while (std::getline(shaderSrc, line))
		{
			retStr << line << '\n'; // Push line from file into stringstream
		}
		// Close file to prevent memory leaks
		shaderSrc.close();
		// Return content of stringstream casted into std::string
		return retStr.str();
	}

	void Shader::Activate()
	{
		glUseProgram(m_RendererID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}
}