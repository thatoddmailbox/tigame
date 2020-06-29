#ifndef TIGAME_SHADER_HPP
#define TIGAME_SHADER_HPP

#include <iostream>

#include <glad/glad.h>

namespace tigame
{
	class Shader
	{
	public:
		Shader(const char * vertex_source, const char * fragment_source);
		~Shader();

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