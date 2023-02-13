#pragma once
#include <string>
#include <vector>

namespace Game
{
	class GameComponent
	{
	public:
		GameComponent() = default;

		inline std::string& GetName() { return m_Name; }

		virtual ~GameComponent() = 0;
	protected:
		std::string m_Name;
	};
}