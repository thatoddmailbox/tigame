#include "input_manager.hpp"

#include <imgui.h>

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
		else if (axis == InputAxis::MouseScrollX)
		{
			return mouse_scroll_x_;
		}
		else if (axis == InputAxis::MouseScrollY)
		{
			return mouse_scroll_y_;
		}
	}

	void InputManager::EarlyUpdate()
	{
		mouse_scroll_x_ = 0;
		mouse_scroll_y_ = 0;
	}

	void InputManager::ProcessEvent(SDL_Event * e)
	{
		if (e->type == SDL_MOUSEWHEEL)
		{
			if (e->wheel.x != 0)
			{
				mouse_scroll_x_ = e->wheel.x;
			}
			if (e->wheel.y != 0)
			{
				mouse_scroll_y_ = e->wheel.y;
			}
		}
	}

	void InputManager::Update()
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		if (io.WantCaptureMouse)
		{
			// we're just doing mouse stuff here, so get out
			return;
		}

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