#ifndef TIGAME_MESH_FACTORY_HPP
#define TIGAME_MESH_FACTORY_HPP

#include <cstddef>

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include <glad/glad.h>

#include <physfs.h>

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
		static Mesh * Box(std::shared_ptr<Shader> shader, float width, float length, float depth);
		static Mesh * OBJ(std::shared_ptr<Shader> shader, const char * path);

	private:
		MeshFactory() {}
	};
}

#endif