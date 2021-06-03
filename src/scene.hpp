#ifndef TIGAME_SCENE_HPP
#define TIGAME_SCENE_HPP

#include <memory>
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

		void AddObject(const std::shared_ptr<Object>& object);
		const std::vector<std::shared_ptr<Object>>& GetObjects();

		void SetMainCamera(Camera * camera);

		void Update(Game * game, double dt);
		void Draw();

		Light light;
		glm::vec3 clear_color;

	private:
		std::vector<std::shared_ptr<Object>> objects_;
		Camera * main_camera_;
	};
}

#endif