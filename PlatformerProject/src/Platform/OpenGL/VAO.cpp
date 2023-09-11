#include "VAO.h"
#include "VBO.h"
#include "VertexBufferLayout.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Renderer
{
	VAO::VAO()
	{
		glGenVertexArrays(1, &m_RendererID);
		Bind();
	}

	void VAO::AddBuffer(VBO& vbo, VertexBufferLayout& layout)
	{
		Bind();
		vbo.Bind();

		const auto& elements = layout.GetElements();

		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, elements[i].GetSizeOfType(elements[i].type), elements[i].type, elements[i].normalized, layout.GetStride(), (const void*)offset);
			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
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