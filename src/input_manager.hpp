#ifndef TIGAME_INPUT_MANAGER_HPP
#define TIGAME_INPUT_MANAGER_HPP

#include <SDL.h>

namespace tigame
{
	enum InputAxis
	{
		Horizontal,
		Vertical,

		MouseX,
		MouseY
	};

	enum InputButton
	{
	};

	class InputManager
	{
	public:
		double GetAxis(InputAxis axis);

	private:
		friend class Game;

		void ProcessEvent(SDL_Event * e);
		void Update();
	};
}

#endif