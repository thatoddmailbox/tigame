#ifndef TIGAME_COMPONENT_HPP
#define TIGAME_COMPONENT_HPP

namespace tigame
{
	class Game;
	class Scene;
	class Object;

	class Component
	{
	public:
		virtual void Start() = 0;
		virtual const char * GetName() = 0;
		virtual void Update(Game *, Scene *, Object *, double dt) = 0;
	};

	class GameComponent
	{
	public:
		virtual void Start() = 0;
		virtual void Update(Game *, double dt) = 0;
	};
}

#endif