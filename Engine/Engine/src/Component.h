#pragma once
#include "Actor.h"

// A class that represents the behaviors or properties an Actor has
class Component {

private:
	Actor *parent; // The actor this component is attached to
	// The parent is set by Actor::addComponent
	friend void Actor::addComponent(Component *component);
public:
	Component(); // Constructor sets parent to null
	virtual void update(); // Called every frame by the actor
};
