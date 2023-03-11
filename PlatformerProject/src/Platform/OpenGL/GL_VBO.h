#include "Graphics/VBO.h"

namespace Game
{
	class GL_VBO :
		public VBO
	{
	public:
		GL_VBO(VertexData data);

		virtual void Bind() override;
		virtual void UnBind() override;

		~GL_VBO()

	};
}