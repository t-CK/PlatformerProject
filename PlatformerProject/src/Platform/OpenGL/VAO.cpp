#include "VAO.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	VAO::VAO()
	{
		glGenVertexArrays(1, &m_RendererID);
		Bind();
	}

	void VAO::Bind()
	{
		glBindVertexArray(m_RendererID);
	}

	void VAO::UnBind()
	{
		glBindVertexArray(0);
	}

	VAO::~VAO()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}
}