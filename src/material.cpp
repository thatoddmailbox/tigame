#include "material.hpp"

namespace tigame
{
	std::shared_ptr<Shader> Material::basic_ = nullptr;

	std::shared_ptr<Shader> Material::Basic()
	{
		// TODO: handle cleanup better
		if (basic_ == nullptr)
		{
			basic_ = std::make_shared<Shader>(
				"#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"layout (location = 1) in vec3 aNormal;\n"
				"layout (location = 2) in vec2 aUV;\n"
				"uniform mat4 model;\n"
				"uniform mat4 view;\n"
				"uniform mat4 projection;\n"
				"out vec3 Normal;\n"
				"out vec3 FragPos;\n"
				"out vec2 UV;\n"
				"void main()\n"
				"{\n"
				"	gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
				"	FragPos = vec3(model * vec4(aPos, 1.0));\n"
				"	Normal = aNormal;\n"
				"	UV = aUV;\n"
				"}",

				"#version 330 core\n"
				""
				"struct Material {\n"
				"	vec4 ambient;\n"
				"	vec4 diffuse;\n"
				"	vec4 specular;\n"
				"	float shininess;\n"
				"};\n"
				""
				"struct Light {\n"
				"	vec3 position;\n"
				"	vec4 color;\n"
				"	vec4 ambient;\n"
				"	vec4 diffuse;\n"
				"	vec4 specular;\n"
				"};\n"
				""
				"in vec3 Normal;\n"
				"in vec3 FragPos;\n"
				"in vec2 UV;\n"
				"out vec4 FragColor;\n"
				""
				"uniform mat3 normal_matrix;\n"
				"uniform vec3 camera_pos;\n"
				""
				"uniform Material material;\n"
				"uniform Light light;\n"
				""
				"uniform sampler2D tex;\n"
				""
				"void main()\n"
				"{\n"
				"	vec4 ambient = light.ambient * material.ambient * light.color;\n"
				""
				"	vec3 norm = normal_matrix * normalize(Normal);\n"
				"	vec3 lightDir = normalize(light.position - FragPos);\n"
				"	float diffuse_strength = max(dot(norm, lightDir), 0.0);\n"
				"	vec4 diffuse = light.diffuse * diffuse_strength * material.diffuse * light.color;\n"
				""
				"	vec3 camera_direction = normalize(camera_pos - FragPos);\n"
				"	vec3 reflectDir = reflect(-lightDir, norm);\n"
				"	float specular_strength = pow(max(dot(camera_direction, reflectDir), 0.0), material.shininess);\n"
				"	vec4 specular = light.specular * specular_strength * material.specular * light.color;\n"
				""
				"	FragColor = texture(tex, UV) * (ambient + diffuse + specular);\n"
				"}\n"
			);
		}
		return basic_;
	}
}