#ifndef TIGAME_GAME_HPP
#define TIGAME_GAME_HPP

#include <iostream>

#include <SDL.h>
#include <SDL2_framerate.h>

#include <glad/glad.h>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

#include <physfs.h>

#include "component.hpp"
#include "input_manager.hpp"
#include "scene.hpp"

namespace tigame
{
	class Game
	{
	public:
		Game(const char * argv0, std::string organization, std::string app_name);
		~Game();

		InputManager& GetInputManager();

		void RequestQuit();

		void AddComponent(const std::shared_ptr<GameComponent>& game_component);

		Scene * GetScene();
		void SetScene(Scene * new_scene);

		void Run();

	private:
		bool quit_ = false;

		FPSmanager frame_manager_;
		SDL_Window * window_;
		Scene * current_scene_ = nullptr;

		InputManager input_manager_;

		std::string organization_;
		std::string app_name_;

		std::vector<std::shared_ptr<GameComponent>> game_components_;
	};
}

#endif