#ifndef TIGAME_TEXTURE_HPP
#define TIGAME_TEXTURE_HPP

#include <cstdint>
#include <cstdlib>

#include <glad/glad.h>

namespace tigame
{
	class Texture
	{
	public:
		Texture(const char * path);
		~Texture();

	private:
		uint64_t width_;
		uint64_t height_;

		GLuint texture_;
	};
}

#endif