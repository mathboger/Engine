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

	Scene scene = Scene("Main");
	Engine engine = Engine(&scene);
	engine.init();

	Actor actor = Actor();
	Renderer renderer = Renderer("simpleVShader.vs", "simpleFShader.fs", vertices, 9, indices, 3);
	actor.addComponent(&renderer);
	scene.addActor(&actor);

	engine.run();
	engine.shutdown();

	return 0;
}