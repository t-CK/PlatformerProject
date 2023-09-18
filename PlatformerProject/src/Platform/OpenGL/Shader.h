#include <string>

namespace Renderer
{
	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);

		void Activate();

		~Shader();
	private:
		// Load shader from file
		std::string LoadShader(const char* shaderPath);

		unsigned int m_RendererID;
	};
}