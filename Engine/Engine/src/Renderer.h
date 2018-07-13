#pragma once
#include "Component.h"
#include "shader.h"

class Renderer : public Component {

private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;

public:
	Shader shader;
	float *vertices;
	int size_vertices;
	unsigned int *indices;
	int size_indices;

	Renderer(const char* fragmentPath, const char* vertexPath, float* t_vertices, int t_size_vertices, unsigned int * t_indices, int t_size_indices);
	virtual void update() override;
};