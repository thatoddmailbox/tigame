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

		clear_color = glm::vec3(0.404f, 0.577f, 0.926f);
	}

	void Scene::AddObject(Object * object)
	{
		objects_.push_back(object);	
	}

	void Scene::SetMainCamera(Camera * camera)
	{
		main_camera_ = camera;
	}

	void Scene::Update(Game * game, double dt)
	{
		for (Object * object : objects_)
		{
			object->Update(game, this, dt);
		}
	}

	void Scene::Draw()
	{
		for (Object * object : objects_)
		{
			object->Draw(main_camera_->GetProjection(), main_camera_->GetView(), &main_camera_->GetPosition(), &light);
		}
	}
}