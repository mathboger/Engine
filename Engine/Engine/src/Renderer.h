#pragma once
#include "Shader.h"
#include "Texture.h"

class SpriteRenderer {

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

	float *vertices;
	int size_vertices;
	unsigned int *indices;
	int size_indices;

	Shader* shader;
	Texture* texture;

public:

	SpriteRenderer(Shader* t_shader, Texture* t_texture, float* t_vertices, int t_size_vertices, unsigned int * t_indices, int t_size_indices);
	void draw();
};