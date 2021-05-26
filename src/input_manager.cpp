#include "input_manager.hpp"

namespace tigame
{
	double InputManager::GetAxis(InputAxis axis)
	{
		if (axis == InputAxis::Horizontal)
		{
			return horizontal_;
		}
		else if (axis == InputAxis::Vertical)
		{
			return vertical_;
		}
	}

	void InputManager::ProcessEvent(SDL_Event * e)
	{
		
	}

	void InputManager::Update()
	{
		int mouse_x, mouse_y;
		uint32_t mouse_state = SDL_GetMouseState(&mouse_x, &mouse_y);
		bool mouse_down = (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT) != 0);

		if (mouse_down && mouse_down_last_)
		{
			horizontal_ = (mouse_x - mouse_x_last_);
			vertical_ = (mouse_y - mouse_y_last_);
		}
		else
		{
			horizontal_ = 0;
			vertical_ = 0;
		}

		mouse_x_last_ = mouse_x;
		mouse_y_last_ = mouse_y;
		mouse_down_last_ = mouse_down;
	}
}