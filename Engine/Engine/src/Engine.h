#pragma once
#include "Scene.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// The main class which needs to be instatiated once for anything to run

class Engine {

public:

	Scene *scene; // The scene wich the game loads (make it a vector!)
	GLFWwindow *window; // The window (encapsulate it with our own class!)

	Engine(Scene *t_scene); // Activate managers in constructor
	~Engine(); // Deactivate managers in descructor

	int run(); // Run the loaded game
};
