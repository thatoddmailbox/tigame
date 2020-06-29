#ifndef TIGAME_MESH_FACTORY_HPP
#define TIGAME_MESH_FACTORY_HPP

#include <cstddef>

#include <glad/glad.h>

#include "mesh.hpp"

namespace tigame
{
	/*
	 * width is along x
	 * length is along y
	 * height is along z
	 */
	class MeshFactory
	{
	public:
		static Mesh * Box(Shader * shader, float width, float length, float depth);

	private:
		MeshFactory() {}
	};
}

#endif