#include "Log.h"

namespace Game
{
	// A base class for platform spesific index buffers
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data, int count = 4) :
			m_Count(count) { }

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		~IndexBuffer() { }
	protected:
		unsigned int m_ID;
		unsigned int m_Count;
	};
}