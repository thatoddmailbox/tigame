#ifndef TIGAME_EDITOR_EDITOR_COMPONENT_HPP
#define TIGAME_EDITOR_EDITOR_COMPONENT_HPP

#include "game.hpp"

#include "component.hpp"
#include "material.hpp"
#include "mesh_factory.hpp"

class EditorComponent : public tigame::GameComponent
{
	tigame::Object * selected_object_ = nullptr;

	void Start();
	void Update(tigame::Game * game, double dt);
};

#endif