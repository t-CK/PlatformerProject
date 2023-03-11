#include "Graphics/VAO.h"

namespace Game
{
	class GL_VAO :
		public VAO
	{
	public:
		GL_VAO();

		virtual void AddBuffer(const VertexBuffer& vb) override;

		virtual void Bind() override;
		virtual void UnBind() override;

		~GL_VAO() { }
	private:

	};
}