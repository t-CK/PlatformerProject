

namespace Renderer
{
	class VAO
	{
	public:
		VAO();

		void Bind();
		void UnBind();

		~VAO();
	private:
		uint32_t m_RendererID;
	}
}