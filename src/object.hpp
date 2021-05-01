#ifndef TIGAME_OBJECT_HPP
#define TIGAME_OBJECT_HPP

#include <memory>
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace tigame
{
	class Object;
}

#include "component.hpp"
#include "mesh.hpp"

namespace tigame
{
	class Object
	{
	public:
		virtual void Update();
		void Draw(glm::mat4 * projection, glm::mat4 * view, glm::vec3 * camera_position, Light * light);

		glm::vec3& GetPosition();
		glm::vec3& GetRotation();
		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		void AddPosition(float x, float y, float z);
		void AddRotation(float x, float y, float z);

		void LookAt(glm::vec3 target, glm::vec3 up);

		void AddComponent(const std::shared_ptr<Component>& component);

		Mesh * mesh = nullptr;

	protected:
		glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 rotation_ = glm::vec3(0.0f, 0.0f, 0.0f);
		bool location_dirty_ = true;

		glm::mat4 model_;
		glm::mat3 normal_;

		std::vector<std::shared_ptr<Component>> components_;
	};
}

#endif