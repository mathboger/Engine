#pragma once
#include <vector>
#include <string>
#include "Actor.h"

// A class that represents a level or a screen of the game
class Scene {

private:
	std::vector<Actor *> actors; // All actors in the scene
	std::string name;

public:
	Scene(std::string t_name); // Every scene needs a unique name
	void update(); // Called every frame, calls every actor's update
	void addActor(Actor *actor); // Add an actor to the scene
	std::string getName();
};