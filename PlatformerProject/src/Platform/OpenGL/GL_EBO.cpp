#include "GL_EBO.h"
#include <glad/glad.h>

namespace Game
{
	GL_EBO::GL_EBO(const unsigned int* data, int count)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	void GL_EBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}
	
	void GL_EBO::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	
	GL_EBO::~GL_EBO()
	{
	}
}