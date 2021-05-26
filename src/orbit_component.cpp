#include "orbit_component.hpp"

#include <cmath>
#include <cstdint>

#include <SDL2/SDL.h>

#include <glm/glm.hpp>

#include "game.hpp"
#include "object.hpp"

namespace tigame
{
	void OrbitComponent::Start()
	{

	}

	void OrbitComponent::Update(tigame::Game * game, tigame::Scene * scene, tigame::Object * object, double dt)
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

		object->SetPosition(
			radius_ * cos(glm::radians(yaw_)) * cos(glm::radians(pitch_)),
			radius_ * sin(glm::radians(pitch_)),
			radius_ * sin(glm::radians(yaw_)) * cos(glm::radians(pitch_))
		);
		object->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	}
}