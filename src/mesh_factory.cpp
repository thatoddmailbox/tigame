#include "mesh_factory.hpp"

namespace tigame
{
	Mesh * MeshFactory::Box(Shader * shader, float width, float height, float depth)
	{
		size_t vertices_count = 36;
		size_t vertices_stride = 5;
		size_t vertices_size = vertices_count * vertices_stride;
		float * vertices = (float *) malloc(vertices_size * sizeof(float));

		/*
		 * front face
		 */
		vertices[(vertices_stride * 0) + 0] = -(width / 2);
		vertices[(vertices_stride * 0) + 1] = -(height / 2);
		vertices[(vertices_stride * 0) + 2] = (depth / 2);
		vertices[(vertices_stride * 0) + 3] = 0.42f;
		vertices[(vertices_stride * 0) + 4] = 0.42f;

		vertices[(vertices_stride * 1) + 0] = -(width / 2);
		vertices[(vertices_stride * 1) + 1] = (height / 2);
		vertices[(vertices_stride * 1) + 2] = (depth / 2);
		vertices[(vertices_stride * 1) + 3] = 0.42f;
		vertices[(vertices_stride * 1) + 4] = 0.42f;

		vertices[(vertices_stride * 2) + 0] = (width / 2);
		vertices[(vertices_stride * 2) + 1] = (height / 2);
		vertices[(vertices_stride * 2) + 2] = (depth / 2);
		vertices[(vertices_stride * 2) + 3] = 0.42f;
		vertices[(vertices_stride * 2) + 4] = 0.42f;

		vertices[(vertices_stride * 3) + 0] = (width / 2);
		vertices[(vertices_stride * 3) + 1] = (height / 2);
		vertices[(vertices_stride * 3) + 2] = (depth / 2);
		vertices[(vertices_stride * 3) + 3] = 0.42f;
		vertices[(vertices_stride * 3) + 4] = 0.42f;

		vertices[(vertices_stride * 4) + 0] = (width / 2);
		vertices[(vertices_stride * 4) + 1] = -(height / 2);
		vertices[(vertices_stride * 4) + 2] = (depth / 2);
		vertices[(vertices_stride * 4) + 3] = 0.42f;
		vertices[(vertices_stride * 4) + 4] = 0.42f;

		vertices[(vertices_stride * 5) + 0] = -(width / 2);
		vertices[(vertices_stride * 5) + 1] = -(height / 2);
		vertices[(vertices_stride * 5) + 2] = (depth / 2);
		vertices[(vertices_stride * 5) + 3] = 0.42f;
		vertices[(vertices_stride * 5) + 4] = 0.42f;

		/*
		 * right face
		 */
		vertices[(vertices_stride * 6) + 0] = (width / 2);
		vertices[(vertices_stride * 6) + 1] = (height / 2);
		vertices[(vertices_stride * 6) + 2] = (depth / 2);
		vertices[(vertices_stride * 6) + 3] = 0.42f;
		vertices[(vertices_stride * 6) + 4] = 0.42f;

		vertices[(vertices_stride * 7) + 0] = (width / 2);
		vertices[(vertices_stride * 7) + 1] = -(height / 2);
		vertices[(vertices_stride * 7) + 2] = (depth / 2);
		vertices[(vertices_stride * 7) + 3] = 0.42f;
		vertices[(vertices_stride * 7) + 4] = 0.42f;

		vertices[(vertices_stride * 8) + 0] = (width / 2);
		vertices[(vertices_stride * 8) + 1] = (height / 2);
		vertices[(vertices_stride * 8) + 2] = -(depth / 2);
		vertices[(vertices_stride * 8) + 3] = 0.42f;
		vertices[(vertices_stride * 8) + 4] = 0.42f;

		vertices[(vertices_stride * 9) + 0] = (width / 2);
		vertices[(vertices_stride * 9) + 1] = (height / 2);
		vertices[(vertices_stride * 9) + 2] = -(depth / 2);
		vertices[(vertices_stride * 9) + 3] = 0.42f;
		vertices[(vertices_stride * 9) + 4] = 0.42f;

		vertices[(vertices_stride * 10) + 0] = (width / 2);
		vertices[(vertices_stride * 10) + 1] = -(height / 2);
		vertices[(vertices_stride * 10) + 2] = -(depth / 2);
		vertices[(vertices_stride * 10) + 3] = 0.42f;
		vertices[(vertices_stride * 10) + 4] = 0.42f;

		vertices[(vertices_stride * 11) + 0] = (width / 2);
		vertices[(vertices_stride * 11) + 1] = -(height / 2);
		vertices[(vertices_stride * 11) + 2] = (depth / 2);
		vertices[(vertices_stride * 11) + 3] = 0.42f;
		vertices[(vertices_stride * 11) + 4] = 0.42f;

		/*
		 * back face
		 */
		vertices[(vertices_stride * 12) + 0] = (width / 2);
		vertices[(vertices_stride * 12) + 1] = (height / 2);
		vertices[(vertices_stride * 12) + 2] = -(depth / 2);
		vertices[(vertices_stride * 12) + 3] = 0.42f;
		vertices[(vertices_stride * 12) + 4] = 0.42f;

		vertices[(vertices_stride * 13) + 0] = (width / 2);
		vertices[(vertices_stride * 13) + 1] = -(height / 2);
		vertices[(vertices_stride * 13) + 2] = -(depth / 2);
		vertices[(vertices_stride * 13) + 3] = 0.42f;
		vertices[(vertices_stride * 13) + 4] = 0.42f;

		vertices[(vertices_stride * 14) + 0] = -(width / 2);
		vertices[(vertices_stride * 14) + 1] = -(height / 2);
		vertices[(vertices_stride * 14) + 2] = -(depth / 2);
		vertices[(vertices_stride * 14) + 3] = 0.42f;
		vertices[(vertices_stride * 14) + 4] = 0.42f;

		vertices[(vertices_stride * 15) + 0] = -(width / 2);
		vertices[(vertices_stride * 15) + 1] = (height / 2);
		vertices[(vertices_stride * 15) + 2] = -(depth / 2);
		vertices[(vertices_stride * 15) + 3] = 0.42f;
		vertices[(vertices_stride * 15) + 4] = 0.42f;

		vertices[(vertices_stride * 16) + 0] = (width / 2);
		vertices[(vertices_stride * 16) + 1] = (height / 2);
		vertices[(vertices_stride * 16) + 2] = -(depth / 2);
		vertices[(vertices_stride * 16) + 3] = 0.42f;
		vertices[(vertices_stride * 16) + 4] = 0.42f;

		vertices[(vertices_stride * 17) + 0] = -(width / 2);
		vertices[(vertices_stride * 17) + 1] = -(height / 2);
		vertices[(vertices_stride * 17) + 2] = -(depth / 2);
		vertices[(vertices_stride * 17) + 3] = 0.42f;
		vertices[(vertices_stride * 17) + 4] = 0.42f;

		/*
		 * left face
		 */
		vertices[(vertices_stride * 18) + 0] = -(width / 2);
		vertices[(vertices_stride * 18) + 1] = -(height / 2);
		vertices[(vertices_stride * 18) + 2] = -(depth / 2);
		vertices[(vertices_stride * 18) + 3] = 0.42f;
		vertices[(vertices_stride * 18) + 4] = 0.42f;

		vertices[(vertices_stride * 19) + 0] = -(width / 2);
		vertices[(vertices_stride * 19) + 1] = (height / 2);
		vertices[(vertices_stride * 19) + 2] = -(depth / 2);
		vertices[(vertices_stride * 19) + 3] = 0.42f;
		vertices[(vertices_stride * 19) + 4] = 0.42f;

		vertices[(vertices_stride * 20) + 0] = -(width / 2);
		vertices[(vertices_stride * 20) + 1] = (height / 2);
		vertices[(vertices_stride * 20) + 2] = (depth / 2);
		vertices[(vertices_stride * 20) + 3] = 0.42f;
		vertices[(vertices_stride * 20) + 4] = 0.42f;

		vertices[(vertices_stride * 21) + 0] = -(width / 2);
		vertices[(vertices_stride * 21) + 1] = (height / 2);
		vertices[(vertices_stride * 21) + 2] = (depth / 2);
		vertices[(vertices_stride * 21) + 3] = 0.42f;
		vertices[(vertices_stride * 21) + 4] = 0.42f;

		vertices[(vertices_stride * 22) + 0] = -(width / 2);
		vertices[(vertices_stride * 22) + 1] = -(height / 2);
		vertices[(vertices_stride * 22) + 2] = -(depth / 2);
		vertices[(vertices_stride * 22) + 3] = 0.42f;
		vertices[(vertices_stride * 22) + 4] = 0.42f;

		vertices[(vertices_stride * 23) + 0] = -(width / 2);
		vertices[(vertices_stride * 23) + 1] = -(height / 2);
		vertices[(vertices_stride * 23) + 2] = (depth / 2);
		vertices[(vertices_stride * 23) + 3] = 0.42f;
		vertices[(vertices_stride * 23) + 4] = 0.42f;

		/*
		 * bottom face
		 */
		vertices[(vertices_stride * 24) + 0] = -(width / 2);
		vertices[(vertices_stride * 24) + 1] = -(height / 2);
		vertices[(vertices_stride * 24) + 2] = (depth / 2);
		vertices[(vertices_stride * 24) + 3] = 0.42f;
		vertices[(vertices_stride * 24) + 4] = 0.42f;

		vertices[(vertices_stride * 25) + 0] = -(width / 2);
		vertices[(vertices_stride * 25) + 1] = -(height / 2);
		vertices[(vertices_stride * 25) + 2] = -(depth / 2);
		vertices[(vertices_stride * 25) + 3] = 0.42f;
		vertices[(vertices_stride * 25) + 4] = 0.42f;

		vertices[(vertices_stride * 26) + 0] = (width / 2);
		vertices[(vertices_stride * 26) + 1] = -(height / 2);
		vertices[(vertices_stride * 26) + 2] = -(depth / 2);
		vertices[(vertices_stride * 26) + 3] = 0.42f;
		vertices[(vertices_stride * 26) + 4] = 0.42f;

		vertices[(vertices_stride * 27) + 0] = (width / 2);
		vertices[(vertices_stride * 27) + 1] = -(height / 2);
		vertices[(vertices_stride * 27) + 2] = -(depth / 2);
		vertices[(vertices_stride * 27) + 3] = 0.42f;
		vertices[(vertices_stride * 27) + 4] = 0.42f;

		vertices[(vertices_stride * 28) + 0] = -(width / 2);
		vertices[(vertices_stride * 28) + 1] = -(height / 2);
		vertices[(vertices_stride * 28) + 2] = (depth / 2);
		vertices[(vertices_stride * 28) + 3] = 0.42f;
		vertices[(vertices_stride * 28) + 4] = 0.42f;

		vertices[(vertices_stride * 29) + 0] = (width / 2);
		vertices[(vertices_stride * 29) + 1] = -(height / 2);
		vertices[(vertices_stride * 29) + 2] = (depth / 2);
		vertices[(vertices_stride * 29) + 3] = 0.42f;
		vertices[(vertices_stride * 29) + 4] = 0.42f;

		/*
		 * top face
		 */
		vertices[(vertices_stride * 30) + 0] = -(width / 2);
		vertices[(vertices_stride * 30) + 1] = (height / 2);
		vertices[(vertices_stride * 30) + 2] = (depth / 2);
		vertices[(vertices_stride * 30) + 3] = 0.42f;
		vertices[(vertices_stride * 30) + 4] = 0.42f;

		vertices[(vertices_stride * 31) + 0] = -(width / 2);
		vertices[(vertices_stride * 31) + 1] = (height / 2);
		vertices[(vertices_stride * 31) + 2] = -(depth / 2);
		vertices[(vertices_stride * 31) + 3] = 0.42f;
		vertices[(vertices_stride * 31) + 4] = 0.42f;

		vertices[(vertices_stride * 32) + 0] = (width / 2);
		vertices[(vertices_stride * 32) + 1] = (height / 2);
		vertices[(vertices_stride * 32) + 2] = -(depth / 2);
		vertices[(vertices_stride * 32) + 3] = 0.42f;
		vertices[(vertices_stride * 32) + 4] = 0.42f;

		vertices[(vertices_stride * 33) + 0] = (width / 2);
		vertices[(vertices_stride * 33) + 1] = (height / 2);
		vertices[(vertices_stride * 33) + 2] = -(depth / 2);
		vertices[(vertices_stride * 33) + 3] = 0.42f;
		vertices[(vertices_stride * 33) + 4] = 0.42f;

		vertices[(vertices_stride * 34) + 0] = -(width / 2);
		vertices[(vertices_stride * 34) + 1] = (height / 2);
		vertices[(vertices_stride * 34) + 2] = (depth / 2);
		vertices[(vertices_stride * 34) + 3] = 0.42f;
		vertices[(vertices_stride * 34) + 4] = 0.42f;

		vertices[(vertices_stride * 35) + 0] = (width / 2);
		vertices[(vertices_stride * 35) + 1] = (height / 2);
		vertices[(vertices_stride * 35) + 2] = (depth / 2);
		vertices[(vertices_stride * 35) + 3] = 0.42f;
		vertices[(vertices_stride * 35) + 4] = 0.42f;
		
		Mesh * box = new Mesh(shader, VertexLayout::XYZUV, vertices, vertices_size * sizeof(float), vertices_count);
		return box;
	}
}