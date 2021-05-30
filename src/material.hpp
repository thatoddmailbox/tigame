#ifndef TIGAME_MATERIAL_HPP
#define TIGAME_MATERIAL_HPP

#include <memory>

#include "shader.hpp"

namespace tigame
{
	class Material
	{
	public:
		static std::shared_ptr<Shader> Basic();

	private:
		static std::shared_ptr<Shader> basic_;
	};
}

#endif