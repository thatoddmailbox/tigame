#include "game.hpp"

#include "component.hpp"
#include "material.hpp"
#include "mesh_factory.hpp"
#include "texture.hpp"

#include "components/orbit_controls.hpp"

#include <cmath>

class SampleCameraComponent : public tigame::Component
{
	float time = 0.0f;

	void Start()
	{

	}

	void Update(tigame::Game * game, tigame::Scene * scene, tigame::Object * object, double dt)
	{
		object->SetPosition(8 * cos(time), 4, 8 * sin(time));
		object->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		// TODO: use delta time
		time += 0.01f;
	}
};

class SampleBoxComponent : public tigame::Component
{
	void Start()
	{

	}

	void Update(tigame::Game * game, tigame::Scene * scene, tigame::Object * object, double dt)
	{
		object->AddRotation(1, 0, 0);
	}
};

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game(argv[0], "tigame", "Demo");

	tigame::Texture blank = tigame::Texture("blank.png");
	tigame::Texture texture = tigame::Texture("smile.png");

	tigame::Scene scene = tigame::Scene();
	game.SetScene(&scene);

	tigame::Camera camera = tigame::Camera(800, 600);
	camera.SetPosition(8, 4, 8);
	camera.LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	camera.AddComponent(std::make_shared<tigame::OrbitControlsComponent>());
	scene.AddObject(&camera);
	scene.SetMainCamera(&camera);

	tigame::Object thing = tigame::Object();
	thing.SetPosition(0, 2, 0);
	tigame::Mesh * box = tigame::MeshFactory::Box(tigame::Material::Basic(), 1, 1.25, 3);
	box->SetTexture(&texture);
	thing.mesh = box;
	thing.AddComponent(std::make_shared<SampleBoxComponent>());
	scene.AddObject(&thing);

	tigame::Object floor = tigame::Object();
	tigame::Mesh * floor_box = tigame::MeshFactory::Box(tigame::Material::Basic(), 5, 0.25, 5);
	floor.mesh = floor_box;
	scene.AddObject(&floor);

	tigame::Object teapot = tigame::Object();
	teapot.SetPosition(-5, 0, 0);
	tigame::Mesh * teapot_mesh = tigame::MeshFactory::OBJ(tigame::Material::Basic(), "teapot.obj");
	teapot_mesh->SetTexture(&texture);
	teapot.mesh = teapot_mesh;
	scene.AddObject(&teapot);

	game.Run();

	delete box;
	delete floor_box;

	return 0;
}