#include <iostream>

#include <SDL.h>
#include <SDL2_framerate.h>

#include <glad/glad.h>

int main(int argc, char * argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	int width = 800;
	int height = 600;
	SDL_Window * window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to start OpenGL." << std::endl;
		return 1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	FPSmanager frame_manager;
	SDL_initFramerate(&frame_manager);
	SDL_setFramerate(&frame_manager, 60);

	bool quit = false;
	SDL_Event e;

	glClearColor(0.5, 1.0, 0.5, 1.0);
	while (!quit)
	{
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

		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
		SDL_framerateDelay(&frame_manager);
	}

	SDL_DestroyWindow(window);

	return 0;
}