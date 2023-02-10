// Reused from OnyxEngine @ https://github.com/t-CK/OnyxEngine

#pragma once

// Vendors
#include <spdlog/spdlog.h>


namespace Game
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

// Makros are left as ONYX_:: to indicate, that they have been reused
#if _DEBUG
							   		   
#define ONYX_FATAL(...)        Game::Log::GetLogger()->critical(__VA_ARGS__)
#define ONYX_ERROR(...)        Game::Log::GetLogger()->error(__VA_ARGS__)
#define ONYX_WARNING(...)      Game::Log::GetLogger()->warn(__VA_ARGS__)
#define ONYX_INFO(...)         Game::Log::GetLogger()->info(__VA_ARGS__)
#define ONYX_TRACE(...)        Game::Log::GetLogger()->trace(__VA_ARGS__)

#else

#define ONYX_FATAL(...)
#define ONYX_ERROR(...)
#define ONYX_WARNING(...)
#define ONYX_INFO(...)

#endif