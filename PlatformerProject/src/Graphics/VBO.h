#include "Log.h"

#include <vector>

namespace Game
{
	struct VertexData
	{
		struct Vertex { 
			Vertex(float x, float y, float z) :
				X(x), Y(y), Z(z) { }
			float X;
			float Y;
			float Z = 0;
		};

		std::vector<Vertex> data;
	};

	// Vertex buffer class to act as base class for platform spesific VBO classes
	class VBO
	{
	public:
		VBO(VertexData data) { }

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		VBO() { }

	protected:
		float m_Vertecies[12];
		unsigned int m_ID;
	};
}