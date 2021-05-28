#include "game.hpp"

namespace tigame
{
	Game::Game(const char * argv0, std::string organization, std::string app_name) : organization_(organization), app_name_(app_name)
	{
		SDL_Init(SDL_INIT_VIDEO);

		int width = 800;
		int height = 600;
		window_ = SDL_CreateWindow(app_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

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

		// hack for debugging
		PHYSFS_mount("../data", NULL, 0);

		SDL_initFramerate(&frame_manager_);
		SDL_setFramerate(&frame_manager_, 60);

		input_manager_ = InputManager();

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.IniFilename = nullptr;

		ImGui::StyleColorsDark();

		ImGui_ImplOpenGL3_Init();
		ImGui_ImplSDL2_InitForOpenGL(window_, context);
	}

	Game::~Game()
	{
		ImGui_ImplSDL2_Shutdown();
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();

		PHYSFS_deinit();
		SDL_DestroyWindow(window_);
	}

	InputManager& Game::GetInputManager()
	{
		return input_manager_;
	}

	void Game::AddComponent(const std::shared_ptr<GameComponent>& game_component)
	{
		game_components_.push_back(game_component);
	}

	Scene * Game::GetScene()
	{
		return current_scene_;
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

		while (!quit)
		{
			ImGuiIO& io = ImGui::GetIO(); (void)io;

			input_manager_.EarlyUpdate();

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

				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
						break;
					}
				}

				bool should_we_handle = true;
				if (e.type == SDL_MOUSEWHEEL || e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
				{
					// it's mouse related, we should only handle it if imgui hasn't captured the mouse
					if (io.WantCaptureMouse)
					{
						should_we_handle = false;
					}
				}
				if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
				{
					// it's keyboard related, we should only handle it if imgui hasn't captured the keyboard
					if (io.WantCaptureKeyboard)
					{
						should_we_handle = false;
					}
				}

				if (should_we_handle)
				{
					input_manager_.ProcessEvent(&e);
				}
				ImGui_ImplSDL2_ProcessEvent(&e);
			}

			if (quit)
			{
				break;
			}

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplSDL2_NewFrame(window_);
			ImGui::NewFrame();

			/*
			 * update
			 */
			input_manager_.Update();
			for (std::shared_ptr<GameComponent>& game_component : game_components_)
			{
				// TODO: actually calculate delta time instead of assuming
				game_component->Update(this, 1.0f / 60.0f);
			}
			if (current_scene_ != nullptr)
			{
				// TODO: actually calculate delta time instead of assuming
				current_scene_->Update(this, 1.0f / 60.0f);
			}

			/*
			 * draw
			 */
			if (current_scene_ != nullptr)
			{
				glClearColor(current_scene_->clear_color.r, current_scene_->clear_color.g, current_scene_->clear_color.b, 1.0);
			}
			else
			{
				glClearColor(0.404, 0.577, 0.926, 1.0);
			}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (current_scene_ != nullptr)
			{
				current_scene_->Draw();
			}

			/*
			 * gui
			 */
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			SDL_GL_SwapWindow(window_);
			SDL_framerateDelay(&frame_manager_);
		}
	}
}