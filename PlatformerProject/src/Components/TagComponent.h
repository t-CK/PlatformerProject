#include "GameComponent.h"

namespace Game
{
	class TagComponent :
		public GameComponent
	{
		TagComponent(std::string& name) { m_Name = name; }

		// Check if component has a specific tag
		bool HasTag(std::string& tag)
		{
			for (auto i : m_Tags)
			{
				if (i == tag)
					return true;
			}
			return false;
		}
		// Adds tag to component if tag does not exist
		void AddTag(std::string& tag)
		{
			if (!HasTag(tag))
				m_Tags.push_back(tag);
		}

		// Get vector containing tags
		inline std::vector<std::string> GetTags() const { return m_Tags; }

	protected:
		std::vector<std::string> m_Tags;
	};
}