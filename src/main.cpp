#include "game.hpp"

#include "mesh_factory.hpp"

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game();

	tigame::Shader basic = tigame::Shader(
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aNormal;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"out vec3 Normal;\n"
		"out vec3 FragPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"	FragPos = vec3(model * vec4(aPos, 1.0));\n"
		"	Normal = aNormal;\n"
		"}",

		"#version 330 core\n"
		"in vec3 Normal;\n"
		"in vec3 FragPos;\n"
		"out vec4 FragColor;\n"
		"uniform mat3 normal_matrix;\n"
		"uniform vec3 light_pos;\n"
		"void main()\n"
		"{\n"
		"	vec4 light_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"	vec4 object_color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		""
		"	float ambient_strength = 0.1;\n"
		"	vec4 ambient = ambient_strength * light_color;\n"
		""
		"	vec3 norm = normal_matrix * normalize(Normal);\n"
		"	vec3 lightDir = normalize(light_pos - FragPos);\n"
		"	float diffuse_strength = max(dot(norm, lightDir), 0.0);\n"
		"	vec4 diffuse = diffuse_strength * light_color;\n"
		""
		"	FragColor = (ambient + diffuse) * object_color;\n"
		"}\n"
	);

	tigame::Scene scene = tigame::Scene();
	game.SetScene(&scene);

	tigame::Camera camera = tigame::Camera(800, 600);
	camera.SetPosition(2, 1, 4);
	camera.SetRotation(-12.5, 25, 0);
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