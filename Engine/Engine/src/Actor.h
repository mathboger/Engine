#pragma once
#include <vector>

// Forward declaration for using a pointer
class Component;

// A class that represents the basic Game Object
class Actor {

private:
	unsigned int ID;
	static unsigned int IDCount; // For assigning each Actor's ID
	std::vector<Component *> components; // List of components of each Actor
	// Note that every Actor initializes itself with a Transform component

public:
	Actor(); // Constructor sets the ID
	void update(); // Called every frame, calls each component's update
	unsigned int getID(); // Retrieve the ID

	// Function definitions inside header due to them being a template function

	// Add a component to the actor, the actor cannot have two components of the same type
	template<typename compType> void addComponent(Component *component) {
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
	}

	// Retrieve the component of type compType. Return null if no components match the type
	template<typename compType> Component * getComponent() {
		for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
			if (dynamic_cast<compType *>(*c) != nullptr) {
				return *c;
			}
		}
		return nullptr;
	}
};