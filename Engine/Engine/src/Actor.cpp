#include "Actor.h"
#include<typeinfo>
#include "Component.h" // since it's not included by Actor.h because of forward declaration

unsigned int Actor::IDCount = 0;

Actor::Actor() {
	ID = IDCount++;
}

void Actor::update() {
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
		(*c)->update();
	}
}

unsigned int Actor::getID() {
	return ID;
}

void Actor::addComponent(Component * component) {
	bool canAdd = true;
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end() && canAdd == true; c++) {
		if (typeid(*c) == typeid(component)) {
			canAdd = false;
		}
	}
	if (canAdd) {
		components.push_back(component);
		component->parent = this;
	}
}

template<typename compType> Component* Actor::getComponent() {
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
		if (typeid(*c) == compType) {
			return *c;
		}
	}
	return nullptr;
}
