#include "Engine.h"
#include <iostream>

// NOTICE: NOT PART OF THE CLASS -> NEEDS REFACTORING FOR A WINDOW MANAGER
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// FIND A WAY TO INITIALIZE AND THROW ERRORS ACCORDINGLY WHEN NECESSARY
Engine::Engine(Scene *t_scene) : scene(t_scene), windowManager(800, 600, this) {
}

Engine::~Engine() {
}

void Engine::init() {
	windowManager.init();
}

void Engine::shutdown() {
	windowManager.shutdown();
}


int Engine::run() {

	// MAIN LOOP - AGAIN TOO MUCH OTHER CLASS STUFF (RenderManager?)
	while (!glfwWindowShouldClose(windowManager.window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		scene->update();

		glfwSwapBuffers(windowManager.window);
		glfwPollEvents();
	}

	glfwTerminate(); // MOVE TO SHUTDOWN?
	return 0;
}
