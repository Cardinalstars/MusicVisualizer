#include "ProgramAssembler.hpp"

ProgramAssembler::ProgramAssembler(bool debug) : debugToggle(debug) {}

unsigned int ProgramAssembler::attachShadersAndDebug(unsigned int& vertexShader, unsigned int& fragmentShader)
{
	auto shaderProgram = attachShaders(vertexShader, fragmentShader);

	if (debugToggle)
	{
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
	return shaderProgram;
	
	
}
unsigned int ProgramAssembler::attachShaders(unsigned int& vertexShader, unsigned int& fragmentShader)
{
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	return shaderProgram;
}
