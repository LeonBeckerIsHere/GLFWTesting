//File: Shader.hpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#ifndef SHADER_HPP
#define SHADER_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad\glad.h>

class Shader {
public:
	/*
	 *	@brief Constructor for the Shader class
	 *	@param vertex	The file path to the vertex shader
	 *	@param fragment	The file path to the fragment shader
	 */
	Shader(const GLchar* vertex, const GLchar* fragment);

	/**
	 *	@brief Inform glfw to use this shader for the following draw
	 */
	void use();

	/**
	 *	@brief Get program id of this shader object
	 *	@return	Returns the ID of this shader object
	 */
	GLuint getID();

	/**
	 *	@brief Utility function to change a uniform bool value
	 *	@param target	Name of the target uniform variable
	 *	@param value	Value of the target uniform variable
	 */
	void setBool(const std::string &target, bool value) const;

	/**
	*	@brief Utility function to change a uniform int value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*/
	void setInt(const std::string &target, int value) const;

	/**
	*	@brief Utility function to change a uniform float value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*/
	void setFloat(const std::string &target, float value) const;


private:
	//ID of the program
	GLuint programID;

	//Disallow default construction
	Shader();
	
};

#endif //SHADER_HPP