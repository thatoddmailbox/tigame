#include "texture.hpp"

#include <physfs.h>
#include <png.h>

namespace tigame
{
	Texture::Texture(const char * path)
	{
		png_image image = {
			.opaque = nullptr,
			.version = PNG_IMAGE_VERSION
		};

		// TODO: don't copy the physfs file into memory
		PHYSFS_File * file = PHYSFS_openRead(path);
		PHYSFS_sint64 file_length = PHYSFS_fileLength(file);
		char * file_data = (char *) malloc(file_length);
		PHYSFS_readBytes(file, file_data, file_length);
		PHYSFS_close(file);

		png_image_begin_read_from_memory(&image, file_data, file_length);
		image.format = PNG_FORMAT_RGBA;

		unsigned char * texture_data = (unsigned char *) malloc(image.width * image.height * 4);
		png_image_finish_read(&image, nullptr, texture_data, image.width * 4, nullptr);

		free(texture_data);
		free(file_data);
	}

	Texture::~Texture()
	{

	}
}