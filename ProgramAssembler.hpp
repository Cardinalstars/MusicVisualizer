#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class ProgramAssembler
{
public: 
	ProgramAssembler(bool debugToggle);
	unsigned int attachShadersAndDebug(unsigned int& vertexShader, unsigned int& fragmentShader);
	unsigned int attachShaders(unsigned int& vertexShader, unsigned int& fragmentShader);
private:
	bool debugToggle;
	int success;
	char infoLog[512];
};