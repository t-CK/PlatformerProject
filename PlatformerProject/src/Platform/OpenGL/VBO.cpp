#include "VBO.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	VBO::VBO()
	{
		glGenBuffers(1, &m_RendererID);
	}

	void VBO::AddBuffer(void* data)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VBO::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}