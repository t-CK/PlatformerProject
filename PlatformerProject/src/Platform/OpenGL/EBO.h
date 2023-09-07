

namespace Renderer
{
	class EBO
	{
	public:
		EBO();

		void AddBuffer(const void* data);
		void Bind();
		void UnBind();

		~EBO();
	private:
		uint32_t m_RendererID;
	};
}