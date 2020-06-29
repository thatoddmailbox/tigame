#include "object.hpp"

namespace tigame
{
	void Object::Update()
	{
		
	}

	void Object::Draw(glm::mat4 * projection, glm::mat4 * view)
	{
		if (location_dirty_)
		{
			model_ = glm::mat4(1.0f);
			model_ = glm::rotate(model_, glm::radians(rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
			model_ = glm::rotate(model_, glm::radians(rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
			model_ = glm::rotate(model_, glm::radians(rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));
			model_ = glm::translate(model_, position_);
			location_dirty_ = false;
		}

		if (mesh != nullptr)
		{
			mesh->Draw(projection, view, &model_);
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
}