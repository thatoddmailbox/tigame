#include "orbit_component.hpp"

#include <cmath>
#include <cstdint>

#include <SDL2/SDL.h>

#include <glm/glm.hpp>

#include "object.hpp"

namespace tigame
{
	void OrbitComponent::Start()
	{

	}

	void OrbitComponent::Update(tigame::Game * game, tigame::Scene * scene, tigame::Object * object, double dt)
	{
		// TODO: an actual input subsystem instead of calling SDL?
		int mouse_x, mouse_y;
		uint32_t mouse_state = SDL_GetMouseState(&mouse_x, &mouse_y);
		bool mouse_down = (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT) != 0);

		if (mouse_down && mouse_down_last_)
		{
			yaw_ += (mouse_x - mouse_x_last_) * 0.5f;
			pitch_ += (mouse_y - mouse_y_last_) * 0.5f;
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

		mouse_x_last_ = mouse_x;
		mouse_y_last_ = mouse_y;
		mouse_down_last_ = mouse_down;
	}
}