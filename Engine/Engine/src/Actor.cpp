#include "Actor.h"

void Actor::update() {
	for (std::vector<Component *>::iterator c = components.begin(); c != components.end(); c++) {
		(*c)->update();
	}
}
