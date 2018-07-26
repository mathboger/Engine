#include "Sprite.h"

float* Sprite::initVertices() {
	float t_vertices[] = {
		parentTransform->position.x, parentTransform->position.y, 0.0f, 0.0f,// Bottom left
		parentTransform->position.x + width, parentTransform->position.y, 1.0f, 0.0f, // Botom right
		parentTransform->position.x + width, parentTransform->position.y + height, 1.0f, 1.0f,// Top right
		parentTransform->position.x, parentTransform->position.y + height, 0.0f, 1.0f, // Top left
		
	};
	float *p = new float[16];
	for (int i = 0; i < 16; i++) {
		p[i] = t_vertices[i];
	}
	return p;
}

unsigned int* Sprite::initIndices() {
	unsigned int t_indices[] = {
		0, 1, 3, // Bottom left triangle
		1, 2, 3 // Top right triangle
	};
	unsigned int *p = new unsigned int[6];
	for (int i = 0; i < 6; i++) {
		p[i] = t_indices[i];
	}
	return p;
}

Sprite::Sprite(const std::string &vertexShaderPath, const std::string &fragmentShaderPath, std::string textureImgPath, Actor *parent, float t_width, float t_height) :
	width(t_width), height(t_height), parentTransform((Transform *)parent->template getComponent<Transform>()),
	texture(textureImgPath), vertices(initVertices()), indices(initIndices()), shader(vertexShaderPath, fragmentShaderPath),
	renderer(&shader, &texture, vertices, 16, indices, 6) {

}

inline void Sprite::updateVertices() {
	// Bottom left
	vertices[0] = parentTransform->position.x;
	vertices[1] = parentTransform->position.y;
	// Top left
	vertices[12] = parentTransform->position.x;
	vertices[13] = parentTransform->position.y + height;
	// Top right
	vertices[8] = parentTransform->position.x + width;
	vertices[9] = parentTransform->position.y + height;
	// Bottom right
	vertices[4] = parentTransform->position.x + width;
	vertices[5] = parentTransform->position.y;
}

void Sprite::update() {
	updateVertices();
	renderer.draw();
}

Sprite::~Sprite() {
	delete vertices;
	delete indices;
}