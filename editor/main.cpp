#include "game.hpp"

#include "component.hpp"
#include "material.hpp"
#include "mesh_factory.hpp"

#include "components/orbit_controls.hpp"

class EditorComponent : public tigame::GameComponent
{
	tigame::Object * selected_object_ = nullptr;

	void Start()
	{

	}

	void Update(tigame::Game * game, double dt)
	{
		// TODO: update is probably not the best place to do this?
		tigame::Scene * current_scene = game->GetScene();

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Quit"))
				{
					game->RequestQuit();
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}

		ImGui::Begin("Scene", nullptr, ImGuiWindowFlags_NoResize);
		ImGui::SetWindowSize(ImVec2(150, 0));
		ImGui::SetWindowPos(ImVec2(0, 18));

		if (ImGui::Button("+ Add"))
		{
			// TODO: clean up the object?
			tigame::Object * thing = new tigame::Object("Box");
			thing->SetPosition(0, 0, 0);
			tigame::Mesh * box = tigame::MeshFactory::Box(tigame::Material::Basic(), 1, 1, 1);
			thing->mesh = box;
			current_scene->AddObject(thing);
		}

		for (tigame::Object * object : current_scene->GetObjects())
		{
			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
			if (object == selected_object_)
			{
				flags |= ImGuiTreeNodeFlags_Selected;
			}
			ImGui::TreeNodeEx(object->GetName().c_str(), flags);
			if (ImGui::IsItemClicked())
			{
				selected_object_ = object;
			}
		}

		ImGui::End();

		ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoResize);
		ImGui::SetWindowSize(ImVec2(250, 0));
		ImGui::SetWindowPos(ImVec2(io.DisplaySize.x - 250, 18));
		if (selected_object_ != nullptr)
		{
			// TODO: this sucks
			// this should use the thing where you can use std::string with imgui's text
			// copying something every frame is bad
			// this is only the editor though, so eh
			static char name_buffer[32];
			strncpy(name_buffer, selected_object_->GetName().c_str(), 32);
			name_buffer[31] = '\0';

			if (ImGui::InputText("Name", name_buffer, 32))
			{
				selected_object_->SetName(name_buffer);
			}

			glm::vec3& position = selected_object_->GetPosition();
			float position_float[3] = {
				position.x,
				position.y,
				position.z
			};
			if (ImGui::InputFloat3("Position", position_float))
			{
				selected_object_->SetPosition(position_float[0], position_float[1], position_float[2]);
			}

			glm::vec3& rotation = selected_object_->GetRotation();
			float rotation_float[3] = {
				rotation.x,
				rotation.y,
				rotation.z
			};
			if (ImGui::InputFloat3("Rotation", rotation_float))
			{
				selected_object_->SetRotation(rotation_float[0], rotation_float[1], rotation_float[2]);
			}

			glm::vec3& scale = selected_object_->GetScale();
			float scale_float[3] = {
				scale.x,
				scale.y,
				scale.z
			};
			if (ImGui::InputFloat3("Scale", scale_float))
			{
				selected_object_->SetScale(scale_float[0], scale_float[1], scale_float[2]);
			}
		}
		else
		{
			ImGui::Text("No object selected.");
		}
		ImGui::End();

		// ImGui::ShowDemoWindow();
	}
};

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
	scene.AddObject(&camera);
	scene.SetMainCamera(&camera);

	tigame::Object thing = tigame::Object("Box");
	thing.SetPosition(0, 0, 0);
	tigame::Mesh * box = tigame::MeshFactory::Box(tigame::Material::Basic(), 1, 1.25, 3);
	box->SetTexture(&blank);
	thing.mesh = box;
	scene.AddObject(&thing);

	tigame::Object thing2 = tigame::Object("Box 2");
	thing2.SetPosition(0, 2, 0);
	tigame::Mesh * box2 = tigame::MeshFactory::Box(tigame::Material::Basic(), 2, 1, 1);
	box2->SetTexture(&blank);
	thing2.mesh = box2;
	scene.AddObject(&thing2);

	std::shared_ptr<EditorComponent> editor_component = std::make_shared<EditorComponent>();
	game.AddComponent(editor_component);

	game.Run();

	return 0;
}