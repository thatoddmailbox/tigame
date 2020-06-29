#include "scene.hpp"

namespace tigame
{
	void Scene::AddObject(Object * object)
	{
		objects_.push_back(object);	
	}

	void Scene::SetMainCamera(Camera * camera)
	{
		main_camera_ = camera;
	}

	void Scene::Update()
	{
		for (Object * object : objects_)
		{
			object->Update();
		}

		glm::vec3& rotation = objects_[1]->GetRotation();
		objects_[1]->SetRotation(rotation.x + 1, rotation.y, rotation.z);
	}

	void Scene::Draw()
	{
		for (Object * object : objects_)
		{
			object->Draw(main_camera_->GetProjection(), main_camera_->GetView());
		}
	}
}