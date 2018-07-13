#pragma once
#include "Component.h"
#include <vector>

class Actor {

public:
	std::vector<Component *> components;
	void update();
};