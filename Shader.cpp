//File: Shader.cpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com

#include "Shader.hpp"

Shader::Shader(const GLchar* vertex, const GLchar* fragment) {
	//Open source code in ifstream objects
	std::string vertexCode, fragmentCode;
	std::ifstream vShaderFile, fShaderFile;

	//Allow ifstream objects to throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try 
	{
		//Open files
		vShaderFile.open(vertex);
		fShaderFile.open(fragment);
		
		//Read the contents of both files into stringstreams
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		//close the ifstream objects
		vShaderFile.close();
		fShaderFile.close();

		//Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "Shader Error: File not read successfully" << std::endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	GLint success;
	GLchar infoLog[512];

	//Compile vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	//Check if the vertex shader compiled successfully
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Shader Error: Vertex compilation failed\n" << infoLog << std::endl;
	}

	//Compile fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	//Check if the fragment shader compiled successfully
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Shader Error: Fragment compilation failed\n" << infoLog << std::endl;
	}

	//Shader Program
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	//Check if the program successfully linked to the shaders
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(programID, 512, NULL, infoLog);
		std::cout << "Shader Error: Program failed to link\n" << infoLog << std::endl;
	}

	//Delete the shaders because theyre linked to 
	//the programIF and no longer need to be stored by us
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() {
	glUseProgram(programID);
}

GLuint Shader::getID() {
	return programID;
}

void Shader::setBool(const std::string &name, bool value) const {
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}