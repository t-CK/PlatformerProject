

namespace Renderer
{
	class VBO;
	class VertexBufferLayout;
	class VAO
	{
	public:
		VAO();

		void AddBuffer(VBO& vbo, VertexBufferLayout& layout);

		void Bind();
		void UnBind();

		~VAO();
	private:
		unsigned int m_RendererID;
	};
}