#include "Renderer.h"
#include <glad/glad.h>
#include <iostream>

Renderer::Renderer(const char* fragmentPath, const char* vertexPath, float* t_vertices, int t_size_vertices, unsigned int* t_indices, int t_size_indices)
	: vertices(t_vertices), size_vertices(t_size_vertices), indices(t_indices), size_indices(t_size_indices) {

    shader.initShader(fragmentPath, vertexPath);

	unsigned int t_VAO, t_VBO, t_EBO;

	glGenVertexArrays(1, &t_VAO);
	glBindVertexArray(t_VAO);

	glGenBuffers(1, &t_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, t_VBO);
	glBufferData(GL_ARRAY_BUFFER, t_size_vertices * sizeof(float), t_vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &t_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, t_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, t_size_indices * sizeof(unsigned int), t_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	VAO = t_VAO;
	VBO = t_VBO;
	EBO = t_EBO;
}

void Renderer::update() {
	shader.use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0);
}