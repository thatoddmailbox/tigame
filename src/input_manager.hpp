#ifndef TIGAME_INPUT_MANAGER_HPP
#define TIGAME_INPUT_MANAGER_HPP

namespace tigame
{
	enum InputAxis
	{
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

		void Update();
	};
}

#endif