#include "game.hpp"

#include "material.hpp"
#include "mesh_factory.hpp"

#include "components/orbit_controls.hpp"

#include "editor_component.hpp"

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game(argv[0], "tigame", "Editor");

	// TODO: we shouldn't need to have a texture here?
	// TODO: an actual material/shader system that allows not having a texture
	tigame::Texture blank = tigame::Texture("blank.png");

	tigame::Scene scene = tigame::Scene();
	game.SetScene(&scene);

	tigame::Camera camera = tigame::Camera("Editor Camera", 800, 600);
	camera.SetPosition(8, 4, 8);
	camera.LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	camera.AddComponent(std::make_shared<tigame::OrbitControlsComponent>());
	std::shared_ptr<tigame::Camera> camera_ptr = std::make_shared<tigame::Camera>(camera);
	scene.AddObject(camera_ptr);
	scene.SetMainCamera(camera_ptr.get());

	tigame::Object thing = tigame::Object("Box");
	thing.SetPosition(0, 0, 0);
	tigame::Mesh * box = tigame::MeshFactory::Box(tigame::Material::Basic(), 1, 1.25, 3);
	box->SetTexture(&blank);
	thing.mesh = box;
	scene.AddObject(std::make_shared<tigame::Object>(thing));

	tigame::Object thing2 = tigame::Object("Box 2");
	thing2.SetPosition(0, 2, 0);
	tigame::Mesh * box2 = tigame::MeshFactory::Box(tigame::Material::Basic(), 2, 1, 1);
	box2->SetTexture(&blank);
	thing2.mesh = box2;
	scene.AddObject(std::make_shared<tigame::Object>(thing2));

	tigame::Object arrow = tigame::Object();
	arrow.SetPosition(-2, 0, -1);
	tigame::Mesh * arrow_mesh = tigame::MeshFactory::OBJ(tigame::Material::Basic(), "arrow.obj");
	arrow_mesh->SetTexture(&blank);
	arrow.mesh = arrow_mesh;
	scene.AddObject(std::make_shared<tigame::Object>(arrow));

	tigame::Object arrow2 = tigame::Object();
	arrow2.SetPosition(-2, 0, -1);
	tigame::Mesh * arrow2_mesh = tigame::MeshFactory::OBJ(tigame::Material::Basic(), "arrow.obj");
	arrow2_mesh->SetTexture(&blank);
	arrow2.mesh = arrow2_mesh;
	scene.AddObject(std::make_shared<tigame::Object>(arrow2));

	tigame::Object arrow3 = tigame::Object();
	arrow3.SetPosition(-2, 0, -1);
	tigame::Mesh * arrow3_mesh = tigame::MeshFactory::OBJ(tigame::Material::Basic(), "arrow.obj");
	arrow3_mesh->SetTexture(&blank);
	arrow3.mesh = arrow3_mesh;
	scene.AddObject(std::make_shared<tigame::Object>(arrow3));

	std::shared_ptr<EditorComponent> editor_component = std::make_shared<EditorComponent>();
	game.AddComponent(editor_component);

	game.Run();

	return 0;
}