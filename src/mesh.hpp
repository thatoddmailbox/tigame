#ifndef TIGAME_MESH_HPP
#define TIGAME_MESH_HPP

#include <cstddef>
#include <cstdlib>

#include <glad/glad.h>

#include <glm/glm.hpp>

#include "shader.hpp"

namespace tigame
{
	enum VertexLayout
	{
		XYZUV
	};

	class Mesh
	{
	public:
		Mesh(Shader * shader, VertexLayout layout, float * vertices, size_t vertices_size, size_t vertices_count);
		~Mesh();

		void Draw(glm::mat4 * projection, glm::mat4 * view, glm::mat4 * model);

	private:
		Shader * shader_;
		VertexLayout layout_;
		float * vertices_;
		size_t vertices_size_;
		size_t vertices_count_;

		GLuint buffer_id_;
		GLuint vertex_array_id_;
	};
}

#endif