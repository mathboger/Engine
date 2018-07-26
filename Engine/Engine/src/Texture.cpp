#include "Texture.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>

// Using stb_image.h for loading image files
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}

int Texture::getNrChannels() {
	return nrChannels;
}

void Texture::useTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}

Texture::Texture(std::string imgFilePath) {

	// Generate and bind the texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set wrapping/filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(imgFilePath.c_str(), &width, &height, &nrChannels, 0);

	// Be careful to use RGB or RGBA. Inconsistent use (with the number of channels) causes the program to crash
	if (data != nullptr) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
}