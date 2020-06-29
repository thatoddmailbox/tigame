#ifndef TIGAME_OBJECT_HPP
#define TIGAME_OBJECT_HPP

#include <iostream>

#include "mesh.hpp"

namespace tigame
{
	class Object
	{
	public:
		void Update();
		void Draw();

		Mesh * mesh;
	};
}

#endif