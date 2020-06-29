#ifndef TIGAME_OBJECT_HPP
#define TIGAME_OBJECT_HPP

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "mesh.hpp"

namespace tigame
{
	class Object
	{
	public:
		virtual void Update();
		void Draw(glm::mat4 * projection, glm::mat4 * view);

		glm::vec3& GetPosition();
		glm::vec3& GetRotation();
		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);

		Mesh * mesh;

	protected:
		glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 rotation_ = glm::vec3(0.0f, 0.0f, 0.0f);
		bool location_dirty_ = true;

		glm::mat4 model_;
	};
}

#endif