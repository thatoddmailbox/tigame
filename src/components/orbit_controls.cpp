#include "orbit_controls.hpp"

#include <cmath>
#include <cstdint>

#include <glm/glm.hpp>

#include "game.hpp"
#include "object.hpp"

namespace tigame
{
	void OrbitControlsComponent::Start()
	{

	}

	const char * OrbitControlsComponent::GetName()
	{
		static const char * name = "Orbit Controls";
		return name;
	}

	void OrbitControlsComponent::Update(Game * game, Scene * scene, Object * object, double dt)
	{
		double horizontal = game->GetInputManager().GetAxis(InputAxis::Horizontal);
		double vertical = game->GetInputManager().GetAxis(InputAxis::Vertical);

		if (horizontal != 0 || vertical != 0)
		{
			yaw_ += horizontal * 0.5f;
			pitch_ += vertical * 0.5f;
			if (pitch_ > 89.0f)
			{
				pitch_ = 89.0f;
			}
			if (pitch_ < -89.0f)
			{
				pitch_ = -89.0f;
			}
		}

		double scroll = game->GetInputManager().GetAxis(InputAxis::MouseScrollY);
		if (scroll != 0)
		{
			radius_ -= scroll;
		}

		object->SetPosition(
			radius_ * cos(glm::radians(yaw_)) * cos(glm::radians(pitch_)),
			radius_ * sin(glm::radians(pitch_)),
			radius_ * sin(glm::radians(yaw_)) * cos(glm::radians(pitch_))
		);
		object->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	}
}