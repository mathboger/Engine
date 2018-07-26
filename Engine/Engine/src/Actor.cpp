#include "Actor.h"
#include<typeinfo>
#include "Component.h" // since it's not included by Actor.h because of forward declaration
#include "Transform.h"

unsigned int Actor::IDCount = 0;

Actor::Actor() {
	ID = IDCount++;
	addComponent<Transform>(new Transform());
}

void Actor::update() {
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
		(*c)->update();
	}
}

unsigned int Actor::getID() {
	return ID;
}

/*void Actor::addComponent(Component * component) {
	bool canAdd = true;
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end() && canAdd == true; c++) {
		if (dynamic_cast<compType *>(*c) != nullptr) {
			canAdd = false;
		}
	}
	if (canAdd) {
		components.push_back(component);
		component->parent = this;
	}
}*/

// Function definition moved to header due to it being a template function
/*template<typename compType> Component* Actor::getComponent() {
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
		if (dynamic_cast<compType *>(*c) != nullptr) {
			return *c;
		}
	}
	return nullptr;
}*/
