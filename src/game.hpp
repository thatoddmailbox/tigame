#ifndef TIGAME_GAME_HPP
#define TIGAME_GAME_HPP

#include <iostream>

#include <SDL.h>
#include <SDL2_framerate.h>

#include <glad/glad.h>

#include <physfs.h>

#include "input_manager.hpp"
#include "scene.hpp"

namespace tigame
{
	class Game
	{
	public:
		Game(const char * argv0, std::string organization, std::string app_name);
		~Game();

		void SetScene(Scene * new_scene);

		void Run();

	private:
		FPSmanager frame_manager_;
		SDL_Window * window_;
		Scene * current_scene_ = nullptr;

		InputManager input_manager_;

		std::string organization_;
		std::string app_name_;
	};
}

#endif