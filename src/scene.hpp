#ifndef TIGAME_SCENE_HPP
#define TIGAME_SCENE_HPP

#include <vector>

#include "object.hpp"

namespace tigame
{
	class Scene
	{
	public:
		void AddObject(Object * object);
		void Update();
		void Draw();

	private:
		std::vector<Object *> objects_;
	};
}

#endif