#pragma once
#include <string>

// Class that represents a texture for Sprites
// Notice that it does NOT inherit Component
class Texture {
private:
	// Texture data
	int width;
	int height;
	int nrChannels;

	// OpenGL object ID
	unsigned int texture;

public:
	int getWidth();
	int getHeight();
	int getNrChannels();

	// Binds the texture for use
	void useTexture();

	// Load the texture data from image file in constructor
	Texture(std::string imgFilePath);
};