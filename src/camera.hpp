#ifndef TIGAME_CAMERA_HPP
#define TIGAME_CAMERA_HPP

#include <cstddef>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace tigame
{
	class Camera;
}

#include "object.hpp"
#include "scene.hpp"

namespace tigame
{
	class Camera : public Object
	{
	public:
		Camera(size_t viewport_width, size_t viewport_height);

		void Update(Scene * scene, float dt) override;

		glm::mat4 * GetProjection();
		glm::mat4 * GetView();

	private:
		glm::mat4 projection_;
		glm::mat4 view_;
	};
}

#endif