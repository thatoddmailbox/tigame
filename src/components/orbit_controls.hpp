#ifndef TIGAME_ORBIT_COMPONENT_HPP
#define TIGAME_ORBIT_COMPONENT_HPP

#include "component.hpp"

namespace tigame
{
	class OrbitControlsComponent : public Component
	{
	public:
		void Start();
		void Update(Game *, Scene *, Object *, double dt);

	private:
		float yaw_ = 0.0f;
		float pitch_ = 0.0f;
		float radius_ = 8.0f;
	};
}

#endif