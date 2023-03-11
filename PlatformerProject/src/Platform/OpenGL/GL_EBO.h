#include "Graphics/IndexBuffer.h"

namespace Game
{
	class GL_EBO :
		public IndexBuffer
	{
	public:
		GL_EBO(const unsigned int* data, int count = 4);

		virtual void Bind() override;
		virtual void UnBind() override;

		~GL_EBO();
	protected:

	};
}