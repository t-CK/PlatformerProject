#include "EBO.h"
#include "VertexBufferLayout.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	EBO::EBO(const unsigned int* data, unsigned int count)
	{
		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
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