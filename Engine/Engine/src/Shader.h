#pragma once

// Include glad to get all the required OpenGL headers
#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader {
private:

	// the program ID
	unsigned int ID;

	// Constructor reads and builds the shader
	void initShader(const std::string &vertexPath, const std::string &fragmentPath);

public:
	Shader(const std::string &vertexPath, const std::string &fragmentPath);

	// use / activate the shader
	void useShader();

	// utility uniform functions
	//void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	//void setFloat(const std::string &name, int value) const;
};