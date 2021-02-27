#ifndef TIGAME_SCENE_HPP
#define TIGAME_SCENE_HPP

#include <vector>

#include "camera.hpp"
#include "object.hpp"

namespace tigame
{
	class Scene
	{
	public:
		Scene();

		void AddObject(Object * object);
		void SetMainCamera(Camera * camera);

		void Update(double dt);
		void Draw();

		Light light;

	private:
		std::vector<Object *> objects_;
		Camera * main_camera_;
	};
}

#endif