//#include "Log.h"
#include "Window.h"

struct GLFWwindow;

namespace Game
{
	class WindowGL :
		public Window
	{
	public:
		WindowGL(const WindowProps& props);

		virtual bool Init() override;
		virtual void Draw() override;
		virtual void Update() override;

		virtual void SetVSync(bool vSync) override;

		virtual void* GetNativeWindow() override { return (void*)m_Window; }

	private:
		GLFWwindow* m_Window;
	};
}