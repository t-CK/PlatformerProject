#pragma once

namespace Game
{
	class Application
	{
	public:
		Application();

		// Initialize an application.
		// Returns true if succesful, false if not
		bool Init();
		void Run();

		// Get an instance of Applkication as pointer
		inline static Application* Get() { return s_GameApp; }

		~Application();

	private:
		bool m_IsRunning;

		// Static member object of Application class becouse
		// we only need one instance of an application running at once
		static Application* s_GameApp;
	};
}