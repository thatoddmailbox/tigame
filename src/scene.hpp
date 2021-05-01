#ifndef TIGAME_SCENE_HPP
#define TIGAME_SCENE_HPP

#include <vector>

#include <glm/glm.hpp>

#include "camera.hpp"
#include "mesh.hpp"
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
		glm::vec3 clear_color;

	private:
		std::vector<Object *> objects_;
		Camera * main_camera_;
	};
}

#endif