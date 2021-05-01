#ifndef TIGAME_COMPONENT_HPP
#define TIGAME_COMPONENT_HPP

namespace tigame
{
	class Scene;
	class Object;

	class Component
	{
	public:
		virtual void Start() = 0;
		virtual void Update(tigame::Scene *, tigame::Object *, double dt) = 0;
	};
}

#endif