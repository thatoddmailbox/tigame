#include "mesh.hpp"

#include <cstdio>
namespace tigame
{
	Mesh::Mesh(Shader * shader, VertexLayout layout, float * vertices, size_t vertices_size, size_t vertices_count) :
		shader_(shader), layout_(layout), vertices_(vertices), vertices_size_(vertices_size), vertices_count_(vertices_count)
	{
		texture_ = nullptr;

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
				8 * sizeof(float),
				(GLvoid *) 0
			);
			glEnableVertexAttribArray(ShaderLocation::POSITION);

			glVertexAttribPointer(
				ShaderLocation::NORMAL,
				3,
				GL_FLOAT,
				GL_FALSE,
				8 * sizeof(float),
				(GLvoid *) (3 * sizeof(float))
			);
			glEnableVertexAttribArray(ShaderLocation::NORMAL);

			glVertexAttribPointer(
				ShaderLocation::TEXTURE_UV,
				2,
				GL_FLOAT,
				GL_FALSE,
				8 * sizeof(float),
				(GLvoid *) (6 * sizeof(float))
			);
			glEnableVertexAttribArray(ShaderLocation::TEXTURE_UV);
		}
		else
		{
			// TODO: handle
		}

		material.Ambient = glm::vec4(0.0215f, 0.1745f, 0.0215f, 1.0f);
		material.Diffuse = glm::vec4(0.07568f, 0.61424f, 0.07568f, 1.0f);
		material.Specular = glm::vec4(0.633f, 0.727811, 0.633f, 1.0f);
		material.Shininess = 0.6f;
	}

	Mesh::~Mesh()
	{
		free(vertices_);
		glDeleteBuffers(1, &buffer_id_);
	}

	void Mesh::SetTexture(Texture * texture)
	{
		texture_ = texture;
	}

	void Mesh::Draw(glm::mat4 * projection, glm::mat4 * view, glm::mat4 * model, glm::mat3 * normal, glm::vec3 * camera_position, Light * light)
	{
		shader_->Activate();
		shader_->SetUniformMatrix4x4("projection", projection);
		shader_->SetUniformMatrix4x4("view", view);
		shader_->SetUniformMatrix4x4("model", model);
		shader_->SetUniformMatrix3x3("normal_matrix", normal);

		shader_->SetUniformVector3("camera_pos", camera_position);

		shader_->SetUniformVector4("material.ambient", &material.Ambient);
		shader_->SetUniformVector4("material.diffuse", &material.Diffuse);
		shader_->SetUniformVector4("material.specular", &material.Specular);
		shader_->SetUniformFloat("material.shininess", material.Shininess);

		shader_->SetUniformVector3("light.position", &light->Position);
		shader_->SetUniformVector4("light.color", &light->Color);
		shader_->SetUniformVector4("light.ambient", &light->Ambient);
		shader_->SetUniformVector4("light.diffuse", &light->Diffuse);
		shader_->SetUniformVector4("light.specular", &light->Specular);

		glBindBuffer(GL_ARRAY_BUFFER, buffer_id_);
		glBindVertexArray(vertex_array_id_);
		glDrawArrays(GL_TRIANGLES, 0, vertices_count_);
	}
}