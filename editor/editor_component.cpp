#include "editor_component.hpp"

void EditorComponent::Start()
{

}

void EditorComponent::Update(tigame::Game * game, double dt)
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

	ImGui::Begin("Scene", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
	ImGui::SetWindowSize(ImVec2(150, 0));
	ImGui::SetWindowPos(ImVec2(0, 18));

	if (ImGui::Button("+ Add"))
	{
		// TODO: clean up the object?
		tigame::Object thing = tigame::Object("Box");
		thing.SetPosition(0, 0, 0);
		tigame::Mesh * box = tigame::MeshFactory::Box(tigame::Material::Basic(), 1, 1, 1);
		thing.mesh = box;
		current_scene->AddObject(std::make_shared<tigame::Object>(thing));
	}

	for (const std::shared_ptr<tigame::Object>& object : current_scene->GetObjects())
	{
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		if (object.get() == selected_object_)
		{
			flags |= ImGuiTreeNodeFlags_Selected;
		}
		ImGui::TreeNodeEx(object->GetName().c_str(), flags);
		if (ImGui::IsItemClicked())
		{
			selected_object_ = object.get();
		}
	}

	ImGui::End();

	ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
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

		ImGui::Separator();
		ImGui::Text("Components");

		for (const std::shared_ptr<tigame::Component>& component : selected_object_->GetComponents())
		{
			ImGui::Text(component->GetName());
		}
	}
	else
	{
		ImGui::Text("No object selected.");
	}
	ImGui::End();
}