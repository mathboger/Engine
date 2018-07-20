#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Engine;

// Callback function for resizing (global for being accesible to GLFW) (the scope operator turns it incompatible)
void framebufferSizeCallback(GLFWwindow *t_window, int t_width, int t_height);

class WindowManager {

private:
	// Window size - CURRENTLY NOT BEING UPDATED BY THE RESIZE CALLBACK FUNCTION
	int width;
	int height;

	// Pointer to the engine to get scene's name for naming the window
	Engine* engine;

public:
	GLFWwindow *window; // The game's window
	// This pointer (should) need(s) to be public to be passed to GLFW functions

	int getWidth();
	int getHeight();

	// Maybe make a set function to change window size from code?

	WindowManager(int t_width, int t_height, Engine* t_engine);

	// Default constructors and destructors do nothing special,
	// (the constructor just sets width and height and the engine pointer)
	// call init and shutdown instead
	void init();
	void shutdown();
};