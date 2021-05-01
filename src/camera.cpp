#include "camera.hpp"

namespace tigame
{
	Camera::Camera(size_t viewport_width, size_t viewport_height)
	{
		projection_ = glm::perspective(glm::radians(45.0f), ((float) viewport_width) / ((float) viewport_height), 0.1f, 100.0f);
	}

	void Camera::Update(tigame::Scene * scene, float dt)
	{
		if (location_dirty_)
		{
			view_ = glm::mat4(1.0f);
			view_ = glm::rotate(view_, glm::radians(-rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
			view_ = glm::rotate(view_, glm::radians(-rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
			view_ = glm::rotate(view_, glm::radians(-rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));
			view_ = glm::translate(view_, position_ * glm::vec3(-1.0f));
		}

		Object::Update(scene, dt);
	}

	glm::mat4 * Camera::GetProjection()
	{
		return &projection_;
	}

	glm::mat4 * Camera::GetView()
	{
		return &view_;
	}
}