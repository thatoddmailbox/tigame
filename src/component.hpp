#ifndef TIGAME_COMPONENT_HPP
#define TIGAME_COMPONENT_HPP

#include "object.hpp"

namespace tigame
{
	class Component
	{
	public:
		virtual void Start() = 0;
		virtual void Update(double dt, tigame::Object *) = 0;
	};
}

#endif