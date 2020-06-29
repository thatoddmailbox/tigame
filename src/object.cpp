#include "object.hpp"

namespace tigame
{
	void Object::Update()
	{
		
	}

	void Object::Draw()
	{
		if (mesh != nullptr)
		{
			mesh->Draw();
		}
	}
}