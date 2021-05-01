#include "object.hpp"

namespace tigame
{
	void Object::Update(Scene * scene, float dt)
	{
		for (std::shared_ptr<Component>& component : components_)
		{
			component->Update(scene, this, 0);
		}
	}

	void Object::Draw(glm::mat4 * projection, glm::mat4 * view, glm::vec3 * camera_position, Light * light)
	{
		if (location_dirty_)
		{
			model_ = glm::mat4(1.0f);
			model_ = glm::translate(model_, position_);
			model_ = glm::rotate(model_, glm::radians(rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
			model_ = glm::rotate(model_, glm::radians(rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
			model_ = glm::rotate(model_, glm::radians(rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));
			model_ = glm::scale(model_, scale_);

			normal_ = glm::mat3(glm::transpose(glm::inverse(model_)));

			location_dirty_ = false;
		}

		if (mesh != nullptr)
		{
			mesh->Draw(projection, view, &model_, &normal_, camera_position, light);
		}
	}

	glm::vec3& Object::GetPosition()
	{
		return position_;
	}

	glm::vec3& Object::GetRotation()
	{
		return rotation_;
	}

	glm::vec3& Object::GetScale()
	{
		return scale_;
	}

	void Object::SetPosition(float x, float y, float z)
	{
		position_.x = x;
		position_.y = y;
		position_.z = z;
		location_dirty_ = true;
	}

	void Object::SetRotation(float x, float y, float z)
	{
		rotation_.x = x;
		rotation_.y = y;
		rotation_.z = z;
		location_dirty_ = true;
	}

	void Object::SetScale(float x, float y, float z)
	{
		scale_.x = x;
		scale_.y = y;
		scale_.z = z;
		location_dirty_ = true;
	}

	void Object::AddPosition(float x, float y, float z)
	{
		glm::vec3& position = GetPosition();
		SetPosition(position.x + x, position.y + y, position.z + z);
	}

	void Object::AddRotation(float x, float y, float z)
	{
		glm::vec3& rotation = GetRotation();
		SetRotation(rotation.x + x, rotation.y + y, rotation.z + z);
	}

	void Object::AddScale(float x, float y, float z)
	{
		glm::vec3& scale = GetScale();
		SetScale(scale.x + x, scale.y + y, scale.z + z);
	}

	void Object::LookAt(glm::vec3 target, glm::vec3 up)
	{
		glm::mat4 look_at_matrix = glm::lookAt(position_, target, up);

		// based on https://github.com/mrdoob/three.js/blob/ab1bac16e8d82c1d5c1dacb22d552a8fdced3add/src/math/Euler.js#L136

		float m11 = glm::row(look_at_matrix, 0)[0];
		float m12 = glm::row(look_at_matrix, 0)[1];
		float m13 = glm::row(look_at_matrix, 0)[2];
		float m22 = glm::row(look_at_matrix, 1)[1];
		float m23 = glm::row(look_at_matrix, 1)[2];
		float m32 = glm::row(look_at_matrix, 2)[1];
		float m33 = glm::row(look_at_matrix, 2)[2];

		float clampedm13 = (m13 < -1 ? -1 : (m13 > 1 ? 1 : m13));

		rotation_.y = glm::degrees(-asinf(clampedm13));

		if (abs(m13) < 0.9999999)
		{
			rotation_.x = glm::degrees(-atan2f(-m23, m33));
			rotation_.z = glm::degrees(atan2f(-m12, m11));
		}
		else
		{
			rotation_.x = glm::degrees(-atan2f(m32, m22));
			rotation_.z = 0;
		}

		location_dirty_ = true;
	}

	void Object::AddComponent(const std::shared_ptr<Component>& component)
	{
		components_.push_back(component);
	}
}