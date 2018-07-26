#pragma once
#include <string>
#include "Component.h"
#include "Texture.h"
#include "Renderer.h"
#include "Transform.h"
#include "Shader.h"

// Class for holding the size of a 2D sprite in the world, its shader and renderer
// Sprites are rectangular and are pivoted on the bottom-left corner of the rectangle,
// such that width and height go right and up from the parent actor's transform position
class Sprite : public Component {
private:
	// Size of the sprite in the world
	// Private with setter functions to adjust values in the vertex array
	float width;
	float height;

	// The transform of the actor the sprite is attached to, so it may calculate the coordinates of the vertices
	Transform *parentTransform;

	// Vertices of the rectangular sprite
	float* vertices; // Size 16: 4 vertices * (2 world coordinates + 2 texture coordinates)
	unsigned int* indices; // Size 6: the two triangles needed for the rectangle 

	// Texture, shader and renderer for displaying
	Texture texture;
	Shader shader;
	SpriteRenderer renderer;

	// Private functions for initializing the vertices and indices in constructor
	float* initVertices();
	unsigned int* initIndices();

	// Update vertices positions according to the parent transform
	inline void updateVertices();

public:
	Sprite(const std::string &vertexShaderPath, const std::string &fragmentShaderPath, std::string textureImgPath, Actor *parent, float t_width, float t_height);
	~Sprite();
	virtual void update() override;
};