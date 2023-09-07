

namespace Renderer
{
	class VBO
	{
	public:
		VBO();
		void AddBuffer(void* data);
		void Bind();
		void UnBind();
		~VBO();

	private:
		uint32_t m_RendererID;
	};
}