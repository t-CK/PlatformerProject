#include "Log.h"
#include <string>

namespace Game
{
	struct WindowProps
	{
		int Width, Height;
		std::string Title;
		bool VSync = true;

		WindowProps(int width = 1280, int height = 720, const std::string& name = "Platformer Game") :
			Width(width), Height(height), Title(name) { }
	};

	// A base class for API spesific window classes
	class Window
	{
	public:
		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		// Get window properties
		inline WindowProps GetProps() const { return m_Props; }
		inline unsigned int GetWidth() const { return m_Props.Width; }
		inline unsigned int GetHeight() const { return m_Props.Height; }
		inline std::string GetTitle() const { return m_Props.Title; }

		//////////////////// V-Sync /////////////////////

		virtual void SetVSync(bool vSync) = 0;
		inline bool GetVSync() { return m_Props.VSync; }
		/////////////////////////////////////////////////

		virtual void* GetNativeWindow() = 0;

		// Create an instance of window
		static Window* Create(const WindowProps& props = WindowProps());

	protected:
		WindowProps m_Props;
	};
}