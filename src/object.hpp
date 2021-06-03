#ifndef TIGAME_OBJECT_HPP
#define TIGAME_OBJECT_HPP

#include <memory>
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "component.hpp"
#include "mesh.hpp"

namespace tigame
{
	class Game;

	class Object
	{
	public:
		Object();
		Object(const char * name);

		virtual void Update(Game * game, Scene * scene, float dt);
		void Draw(glm::mat4 * projection, glm::mat4 * view, glm::vec3 * camera_position, Light * light);

		const std::string& GetName();
		void SetName(const char * name);

		glm::vec3& GetPosition();
		glm::vec3& GetRotation();
		glm::vec3& GetScale();
		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		void SetScale(float x, float y, float z);
		void AddPosition(float x, float y, float z);
		void AddRotation(float x, float y, float z);
		void AddScale(float x, float y, float z);

		void LookAt(glm::vec3 target, glm::vec3 up);

		const std::vector<std::shared_ptr<Component>>& GetComponents();
		void AddComponent(const std::shared_ptr<Component>& component);

		Mesh * mesh = nullptr;

	protected:
		void UpdateMatrices(glm::mat4 * parent);

		std::string name_;

		glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 rotation_ = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 scale_ = glm::vec3(1.0f, 1.0f, 1.0f);
		bool location_dirty_ = true;

		glm::mat4 model_;
		glm::mat3 normal_;

		std::vector<std::shared_ptr<Component>> components_;
	};
}

#endif