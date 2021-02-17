#include "game.hpp"

namespace tigame
{
	Game::Game(const char * argv0, std::string organization, std::string app_name) : organization_(organization), app_name_(app_name)
	{
		SDL_Init(SDL_INIT_VIDEO);

		int width = 800;
		int height = 600;
		window_ = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GLContext context = SDL_GL_CreateContext(window_);

		if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
		{
			std::cerr << "Failed to start OpenGL." << std::endl;
			return;
		}

		std::cout << glGetString(GL_VERSION) << std::endl;

		PHYSFS_init(argv0);
		PHYSFS_setSaneConfig(organization_.c_str(), app_name_.c_str(), "zip", false, true);

		SDL_initFramerate(&frame_manager_);
		SDL_setFramerate(&frame_manager_, 60);
	}

	Game::~Game()
	{
		PHYSFS_deinit();
		SDL_DestroyWindow(window_);
	}

	void Game::SetScene(Scene * new_scene)
	{
		current_scene_ = new_scene;
	}

	void Game::Run()
	{
		bool quit = false;
		SDL_Event e;

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.404, 0.577, 0.926, 1.0);

		while (!quit)
		{
			/*
			 * handle events
			 */
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
					break;
				}
			}

			if (quit)
			{
				break;
			}

			/*
			 * update
			 */
			if (current_scene_ != nullptr)
			{
				current_scene_->Update();
			}

			/*
			 * draw
			 */
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (current_scene_ != nullptr)
			{
				current_scene_->Draw();
			}

			SDL_GL_SwapWindow(window_);
			SDL_framerateDelay(&frame_manager_);
		}
	}
}