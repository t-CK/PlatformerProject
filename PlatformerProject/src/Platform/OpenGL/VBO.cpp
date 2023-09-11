#include "VBO.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	VBO::VBO(const void* data, unsigned int size)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VBO::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VBO::~VBO()
	{
		glDeleteBuffers(1, &m_RendererID);
	}
}