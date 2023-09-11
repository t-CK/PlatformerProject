

namespace Renderer
{
	class VBO
	{
	public:
		VBO();
		void AddBuffer(const void* data);
		void Bind();
		void UnBind();
		~VBO();

	private:
		unsigned int m_RendererID;
	};
}