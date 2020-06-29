#include "scene.hpp"

namespace tigame
{
	void Scene::AddObject(Object * object)
	{
		objects_.push_back(object);	
	}

	void Scene::Update()
	{
		for (Object * object : objects_)
		{
			object->Update();
		}
	}

	void Scene::Draw()
	{
		for (Object * object : objects_)
		{
			object->Draw();
		}
	}
}