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

public:
	Actor(); // Constructor sets the ID
	void update(); // Called every frame, calls each component's update
	unsigned int getID(); // Retrieve the ID
	void addComponent(Component *component); // Add a component to the actor, the actor cannot have two components of the same type
	template<typename compType> Component * getComponent(); // Retrieve the component of type compType. Return null if no components match the type
};