

namespace Renderer
{
	class VBO
	{
	public:
		VBO(const void* data, unsigned int size);
		void Bind();
		void UnBind();
		~VBO();

	private:
		unsigned int m_RendererID;
	};
}