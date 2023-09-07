#include "EBO.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	EBO::EBO()
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void EBO::AddBuffer(const void* data)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}

	void EBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void EBO::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	EBO::~EBO()
	{
		glDeleteBuffers(1, &m_RendererID);
	}
}