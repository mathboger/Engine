#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"
#include "Engine.h"
#include "Sprite.h"

int main(void) {

	Scene scene = Scene("Main");
	Engine engine = Engine(&scene);
	engine.init();

	Actor* actor = new Actor();
	Sprite* sprite = new Sprite("simpleVShader.vs", "simpleFShader.fs", "wall.jpg", actor, 0.5f, 0.5f);
    actor->addComponent<Sprite>(sprite);
	scene.addActor(actor);

	engine.run();
	engine.shutdown();

	return 0;
}