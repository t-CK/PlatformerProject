#include "GL_VAO.h"

#include <glad/glad.h>

namespace Game
{
	GL_VAO::GL_VAO()
	{
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}

	void GL_VAO::AddBuffer(const VertexBuffer& vb)
	{
		// TODO
	}

	void GL_VAO::Bind()
	{
		glBindVertexArray(m_ID);
	}

	void GL_VAO::UnBind()
	{
		glBindVertexArray(0);
	}

	GL_VAO::~GL_VAO()
	{
		
	}
}