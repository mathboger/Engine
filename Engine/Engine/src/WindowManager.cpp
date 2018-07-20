#include "WindowManager.h"
#include "Engine.h"
#include <iostream>

int WindowManager::getWidth() {
	return width;
}

int WindowManager::getHeight() {
	return height;
}

WindowManager::WindowManager(int t_width, int t_height, Engine* t_engine) : width(t_width), height(t_height), engine(t_engine) {
}

void WindowManager::init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(800, 600, engine->scene->getName().c_str(), NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		//return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		//return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

void WindowManager::shutdown() {

}

void framebufferSizeCallback(GLFWwindow* t_window, int t_width, int t_height) {
	glViewport(0, 0, t_width, t_height);
	//width = t_width;
	//height = t_height; AKA FIND A WAY TO UPDATE THE VALUES OF THE WINDOWMANAGER!
}