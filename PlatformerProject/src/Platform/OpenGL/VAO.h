

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
		unsigned int m_RendererID;
	};
}