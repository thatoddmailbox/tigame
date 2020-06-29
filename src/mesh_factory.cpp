#include "mesh_factory.hpp"

namespace tigame
{
	Mesh * MeshFactory::Box(Shader * shader, float width, float length, float depth)
	{
		size_t vertices_count = 3;
		size_t vertices_stride = 5;
		size_t vertices_size = vertices_count * vertices_stride;
		float * vertices = (float *) malloc(vertices_size * sizeof(float));

		vertices[(vertices_stride * 0) + 0] = -0.5f;
		vertices[(vertices_stride * 0) + 1] = -0.5f;
		vertices[(vertices_stride * 0) + 2] = 0.0f;
		vertices[(vertices_stride * 0) + 3] = 0.42f;
		vertices[(vertices_stride * 0) + 4] = 0.42f;

		vertices[(vertices_stride * 1) + 0] = 0.5f;
		vertices[(vertices_stride * 1) + 1] = -0.5f;
		vertices[(vertices_stride * 1) + 2] = 0.0f;
		vertices[(vertices_stride * 1) + 3] = 0.42f;
		vertices[(vertices_stride * 1) + 4] = 0.42f;

		vertices[(vertices_stride * 2) + 0] = 0.0f;
		vertices[(vertices_stride * 2) + 1] = 0.5f;
		vertices[(vertices_stride * 2) + 2] = 0.0f;
		vertices[(vertices_stride * 2) + 3] = 0.42f;
		vertices[(vertices_stride * 2) + 4] = 0.42f;
		
		Mesh * box = new Mesh(shader, VertexLayout::XYZUV, vertices, vertices_size * sizeof(float), vertices_count);
		return box;
	}
}