#ifndef TIGAME_GAME_HPP
#define TIGAME_GAME_HPP

#include <iostream>

#include <SDL.h>
#include <SDL2_framerate.h>

#include <glad/glad.h>

#include "scene.hpp"

namespace tigame
{
	class Game
	{
	public:
		Game();
		~Game();

		void SetScene(Scene * new_scene);

		void Run();

	private:
		FPSmanager frame_manager_;
		SDL_Window * window_;
		Scene * current_scene_ = nullptr;
	};
}

#endif