#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"
#include "Engine.h"
#include "Renderer.h"

int main(void) {

	// Vertices for rendering a triangle
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned int indices[] = {
		0, 1, 2
	};

	Engine engine = Engine();
	Scene scene = Scene();
	Actor actor = Actor();
	Renderer renderer = Renderer("simpleVShader.vs", "simpleFShader.fs", vertices, 9, indices, 3);
	actor.components.push_back(&renderer);
	scene.actors.push_back(&actor);
	engine.scene = &scene;

	engine.run();

	return 0;
}