#include "Log.h"
#include "Application.h"

int main()
{
	Game::Log::Init();

	Game::Application* app = new Game::Application();

	if (!app->Init())
	{
		ONYX_ERROR("Failed to create application in main");
		return -1;
	}
	app->Run();
	delete app;

	return 0;
}