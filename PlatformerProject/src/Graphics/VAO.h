#include "Log.h"

class VertexBuffer;

namespace Game
{
	// Vertex array class to act as base class for platform spesific vertex buffers
	class VAO
	{
	public:
		VAO() = default;

		virtual void AddBuffer(const VertexBuffer& vb) = 0;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		~VAO() { }
	protected:
		unsigned int m_ID;

	};
}