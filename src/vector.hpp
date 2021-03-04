#ifndef TIGAME_VECTOR_HPP
#define TIGAME_VECTOR_HPP

#include <cstdint>

namespace tigame
{
	struct Vector3i
	{
		uint32_t x;
		uint32_t y;
		uint32_t z;
	};

	struct Vector3f
	{
		float x;
		float y;
		float z;
	};
}

#endif