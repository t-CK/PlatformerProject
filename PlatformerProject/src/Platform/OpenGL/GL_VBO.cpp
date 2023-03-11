#include "GL_VBO.h"

#include <glad/glad.h>

namespace Game
{
	GL_VBO::GL_VBO(VertexData data)
	{
		for (int i = 0; i < 12; i++)
		{
			float m_Vertecies[12];
			int indexCounter = 0;

			if (indexCounter == 0)
				m_Vertecies[i] = data.data[i].X;
			else if (indexCounter == 1)
				m_Vertecies[i] == data.data[i].Y;
			else if (indexCounter == 2)
			{
				m_Vertecies[i] = data.data[i].Z;
				indexCounter = 0;
			}
		}

		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertecies), m_Vertecies, GL_STATIC_DRAW);
	}

	void GL_VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertecies), m_Vertecies, GL_STATIC_DRAW);
	}

	void GL_VBO::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GL_VBO::~GL_VBO()
	{
		glDeleteBuffers(1, &m_ID);
	}
}
