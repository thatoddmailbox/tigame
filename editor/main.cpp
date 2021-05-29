#include "game.hpp"

#include "component.hpp"
#include "mesh_factory.hpp"
#include "orbit_component.hpp"

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

		ImGui::Begin("Scene");
		ImGui::SetWindowSize(ImVec2(150, 150));
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

		ImGui::Begin("Properties");
		ImGui::SetWindowSize(ImVec2(250, 150));
		ImGui::SetWindowPos(ImVec2(300, 50));
		if (selected_object_ != nullptr)
		{
			ImGui::Text("Name: %s", selected_object_->GetName().c_str());

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

		ImGui::ShowDemoWindow();
	}
};

int main(int argc, char * argv[])
{
	tigame::Game game = tigame::Game(argv[0], "tigame", "Editor");

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

	tigame::Camera camera = tigame::Camera("Editor Camera", 800, 600);
	camera.SetPosition(8, 4, 8);
	camera.LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	camera.AddComponent(std::make_shared<tigame::OrbitComponent>());
	scene.AddObject(&camera);
	scene.SetMainCamera(&camera);

	tigame::Object thing = tigame::Object("Box");
	thing.SetPosition(0, 0, 0);
	tigame::Mesh * box = tigame::MeshFactory::Box(&basic, 1, 1.25, 3);
	thing.mesh = box;
	scene.AddObject(&thing);

	std::shared_ptr<EditorComponent> editor_component = std::make_shared<EditorComponent>();
	game.AddComponent(editor_component);

	game.Run();

	return 0;
}