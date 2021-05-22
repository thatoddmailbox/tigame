#ifndef TIGAME_INPUT_MANAGER_HPP
#define TIGAME_INPUT_MANAGER_HPP

namespace tigame
{
	enum InputAxis
	{
		MouseX,
		MouseY
	};

	class InputManager
	{
		double GetAxis(InputAxis axis);
	};
}

#endif