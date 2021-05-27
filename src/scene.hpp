#ifndef TIGAME_SCENE_HPP
#define TIGAME_SCENE_HPP

#include <vector>

#include <glm/glm.hpp>

#include "camera.hpp"
#include "mesh.hpp"
#include "object.hpp"

namespace tigame
{
	class Game;

	class Scene
	{
	public:
		Scene();

		void AddObject(Object * object);
		const std::vector<Object *>& GetObjects();

		void SetMainCamera(Camera * camera);

		void Update(Game * game, double dt);
		void Draw();

		Light light;
		glm::vec3 clear_color;

	private:
		std::vector<Object *> objects_;
		Camera * main_camera_;
	};
}

#endif