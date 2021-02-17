#include "scene.hpp"

namespace tigame
{
	Scene::Scene()
	{
		light.Position = glm::vec3(5, 5, 5);
		light.Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		light.Ambient = glm::vec4(0.2f, 0.2f, 0.2f, 1.0f);
		light.Diffuse = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
		light.Specular = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	void Scene::AddObject(Object * object)
	{
		objects_.push_back(object);	
	}

	void Scene::SetMainCamera(Camera * camera)
	{
		main_camera_ = camera;
	}

	static float time = 0.0f;

	void Scene::Update()
	{
		for (Object * object : objects_)
		{
			object->Update();
		}

		// hacks for the demo
		// TODO: move this into a component? or something?
		glm::vec3& rotation = objects_[1]->GetRotation();
		objects_[1]->SetRotation(rotation.x + 1, rotation.y, rotation.z);

		// main_camera_->SetPosition(4 * cos(time), 4, 10 * sin(time));
		// main_camera_->SetRotation(-18, 21 + time, 0);
		// main_camera_->LookAt(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		// main_camera_->Update();

		// TODO: use delta time
		time += 0.01f;
	}

	void Scene::Draw()
	{
		for (Object * object : objects_)
		{
			object->Draw(main_camera_->GetProjection(), main_camera_->GetView(), &main_camera_->GetPosition(), &light);
		}
	}
}