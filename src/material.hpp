#ifndef TIGAME_MATERIAL_HPP
#define TIGAME_MATERIAL_HPP

#include "shader.hpp"

namespace tigame
{
	class Material
	{
	public:
		static Shader * Basic();

	private:
		static Shader * basic_;
	};
}

#endif