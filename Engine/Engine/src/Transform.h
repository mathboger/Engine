#include "Component.h"
#include <glm/glm.hpp>

// Class for saving positions in the world
class Transform : public Component {
public:
	glm::vec3 position;

	// Move constructor to source file when implementing the rest of the class
	Transform() {
		position.x = 0;
		position.y = 0;
		position.z = 0;
	}
};