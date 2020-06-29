#ifndef TIGAME_SHADER_HPP
#define TIGAME_SHADER_HPP

#include <iostream>
#include <map>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace tigame
{
	class Shader
	{
	public:
		Shader(const char * vertex_source, const char * fragment_source);
		~Shader();

		void SetUniformMatrix4x4(const std::string& name, glm::mat4 * value);

		void Activate();

	private:
		GLuint program_;
	};

	enum ShaderLocation
	{
		POSITION = 0,
		TEXTURE_UV = 1
	};
}

#endif