#include "game.hpp"

#include "mesh_factory.hpp"

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game();

	tigame::Shader basic = tigame::Shader(
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"}",

		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n"
	);

	tigame::Scene scene = tigame::Scene();
	game.SetScene(&scene);

	tigame::Camera camera = tigame::Camera(800, 600);
	camera.SetPosition(2, 1, 4);
	camera.SetRotation(-10, 25, 0);
	scene.AddObject(&camera);
	scene.SetMainCamera(&camera);

	tigame::Object thing = tigame::Object();
	tigame::Mesh * box = tigame::MeshFactory::Box(&basic, 1, 1.25, 3);
	thing.mesh = box;
	scene.AddObject(&thing);

	game.Run();

	delete box;

	return 0;
}