#include "Scene.h"

Scene::Scene(std::string t_name) : name(t_name) {}

void Scene::update() {
	for (std::vector<Actor *>::iterator a = actors.begin(); a != actors.end(); a++) {
		(*a)->update();
	}
}

void Scene::addActor(Actor *actor) {
	actors.push_back(actor);
}

std::string Scene::getName() {
	return name;
}
