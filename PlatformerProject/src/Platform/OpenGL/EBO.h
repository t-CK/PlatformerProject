
namespace Renderer
{
	class VertexBufferLayout;
	
	class EBO
	{
	public:
		EBO(const unsigned int* data, unsigned int count);

		void Bind();
		void UnBind();

		~EBO();
	private:
		unsigned int m_RendererID;
	};
}