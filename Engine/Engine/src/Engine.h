#pragma once
#include "Scene.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// The main class which needs to be instatiated once for anything to run

class Engine {

public:

	Scene *scene;
	GLFWwindow *window;

	Engine(); // Activate managers in constructor
	~Engine(); // Deactivate managers in descructor

	int run(); // Run the loaded game
};
