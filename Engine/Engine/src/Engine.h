#pragma once
#include "Scene.h"
#include "WindowManager.h"

// CONSIDER IF SINGLETON APPROACH IS REALLY NEEDED
// Maybe the window size problem can be solved with events? 

// The main singleton class which needs to be instatiated for anything to run
class Engine {

public:

	Scene *scene; // The scene wich the game loads (make it a vector!)

	// Managers
	WindowManager windowManager; // A manager for creating the window and OpenGL context

	Engine(Scene *t_scene); // Do only basic assignments is constructor
	~Engine(); // Deactivate managers in descructor

	void init(); // Start up the engine
	void shutdown();

	int run(); // Run the loaded game
};
