#include "mesh.hpp"

#include <cstdio>
namespace tigame
{
	Mesh::Mesh(Shader * shader, VertexLayout layout, float * vertices, size_t vertices_size, size_t vertices_count) :
		shader_(shader), layout_(layout), vertices_(vertices), vertices_size_(vertices_size), vertices_count_(vertices_count)
	{
		glGenBuffers(1, &buffer_id_);
		glBindBuffer(GL_ARRAY_BUFFER, buffer_id_);
		glBufferData(GL_ARRAY_BUFFER, vertices_size_, vertices, GL_STATIC_DRAW);

		if (layout == VertexLayout::XYZUV)
		{
			glGenVertexArrays(1, &vertex_array_id_);
			glBindVertexArray(vertex_array_id_);

			glVertexAttribPointer(
				ShaderLocation::POSITION,
				3,
				GL_FLOAT,
				GL_FALSE,
				5 * sizeof(float),
				(GLvoid *) 0
			);
			glEnableVertexAttribArray(ShaderLocation::POSITION);

			glVertexAttribPointer(
				ShaderLocation::TEXTURE_UV,
				2,
				GL_FLOAT,
				GL_FALSE,
				5 * sizeof(float),
				(GLvoid *) (3 * sizeof(float))
			);
			glEnableVertexAttribArray(ShaderLocation::TEXTURE_UV);
		}
		else
		{
			// TODO: handle
		}
	}

	Mesh::~Mesh()
	{
		free(vertices_);
		glDeleteBuffers(1, &buffer_id_);
	}

	void Mesh::Draw()
	{
		shader_->Activate();
		glBindBuffer(GL_ARRAY_BUFFER, buffer_id_);
		glBindVertexArray(vertex_array_id_);
		glDrawArrays(GL_TRIANGLES, 0, vertices_count_);
	}
}