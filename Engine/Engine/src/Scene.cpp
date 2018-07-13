#include "Scene.h"

void Scene::update() {
	for (std::vector<Actor *>::iterator a = actors.begin(); a != actors.end(); a++) {
		(*a)->update();
	}
}
