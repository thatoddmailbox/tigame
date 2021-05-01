#include "game.hpp"

#include "component.hpp"
#include "mesh_factory.hpp"
#include "texture.hpp"

class SampleComponent : public tigame::Component
{
	void Start()
	{

	}

	void Update(tigame::Scene * scene, tigame::Object * object, double dt)
	{
		object->AddRotation(1, 0, 0);
	}
};

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game(argv[0], "tigame", "Demo");

	tigame::Texture texture = tigame::Texture("smile.png");
	tigame::Shader basic = tigame::Shader(
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aNormal;\n"
		"layout (location = 2) in vec2 aUV;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"out vec3 Normal;\n"
		"out vec3 FragPos;\n"
		"out vec2 UV;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"	FragPos = vec3(model * vec4(aPos, 1.0));\n"
		"	Normal = aNormal;\n"
		"	UV = aUV;\n"
		"}",

		"#version 330 core\n"
		""
		"struct Material {\n"
		"	vec4 ambient;\n"
		"	vec4 diffuse;\n"
		"	vec4 specular;\n"
		"	float shininess;\n"
		"};\n"
		""
		"struct Light {\n"
		"	vec3 position;\n"
		"	vec4 color;\n"
		"	vec4 ambient;\n"
		"	vec4 diffuse;\n"
		"	vec4 specular;\n"
		"};\n"
		""
		"in vec3 Normal;\n"
		"in vec3 FragPos;\n"
		"in vec2 UV;\n"
		"out vec4 FragColor;\n"
		""
		"uniform mat3 normal_matrix;\n"
		"uniform vec3 camera_pos;\n"
		""
		"uniform Material material;\n"
		"uniform Light light;\n"
		""
		"uniform sampler2D tex;\n"
		""
		"void main()\n"
		"{\n"
		"	vec4 ambient = light.ambient * material.ambient * light.color;\n"
		""
		"	vec3 norm = normal_matrix * normalize(Normal);\n"
		"	vec3 lightDir = normalize(light.position - FragPos);\n"
		"	float diffuse_strength = max(dot(norm, lightDir), 0.0);\n"
		"	vec4 diffuse = light.diffuse * diffuse_strength * material.diffuse * light.color;\n"
		""
		"	vec3 camera_direction = normalize(camera_pos - FragPos);\n"
		"	vec3 reflectDir = reflect(-lightDir, norm);\n"
		"	float specular_strength = pow(max(dot(camera_direction, reflectDir), 0.0), material.shininess);\n"
		"	vec4 specular = light.specular * specular_strength * material.specular * light.color;\n"
		""
		"	FragColor = texture(tex, UV) * (ambient + diffuse + specular);\n"
		"}\n"
	);

	tigame::Scene scene = tigame::Scene();
	game.SetScene(&scene);

	tigame::Camera camera = tigame::Camera(800, 600);
	camera.SetPosition(8, 4, 8);
	camera.LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	scene.AddObject(&camera);
	scene.SetMainCamera(&camera);

	tigame::Object thing = tigame::Object();
	thing.SetPosition(0, 2, 0);
	tigame::Mesh * box = tigame::MeshFactory::Box(&basic, 1, 1.25, 3);
	box->SetTexture(&texture);
	thing.mesh = box;
	thing.AddComponent(std::make_shared<SampleComponent>());
	scene.AddObject(&thing);

	tigame::Object floor = tigame::Object();
	tigame::Mesh * floor_box = tigame::MeshFactory::Box(&basic, 5, 0.25, 5);
	floor.mesh = floor_box;
	scene.AddObject(&floor);

	tigame::Object teapot = tigame::Object();
	teapot.SetPosition(-5, 0, 0);
	tigame::Mesh * teapot_mesh = tigame::MeshFactory::OBJ(&basic, "teapot.obj");
	teapot_mesh->SetTexture(&texture);
	teapot.mesh = teapot_mesh;
	scene.AddObject(&teapot);

	game.Run();

	delete box;
	delete floor_box;

	return 0;
}