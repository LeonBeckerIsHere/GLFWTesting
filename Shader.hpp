//File: Shader.hpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#ifndef SHADER_HPP
#define SHADER_HPP
#include <glad\glad.h>
#include <glm\glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

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

	/**
	*	@brief Utility function to change a uniform 2 float vector value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*	
	*	Overload
	*	@param target	Name of the target uniform variable
	*	@param x	first float value
	*	@param y	second float value
	*/
	void setVec2(const std::string &target, const glm::vec2 &value) const;
	void setVec2(const std::string &target, float x, float y) const;

	/**
	*	@brief Utility function to change a uniform 3 float vector value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*	Overload
	*	@param target	Name of the target uniform variable
	*	@param x	first float value
	*	@param y	second float value
	*	@param z	third float value
	*/
	void setVec3(const std::string &target, const glm::vec3 &value) const;
	void setVec3(const std::string &target, float x, float y, float z) const;

	/**
	*	@brief Utility function to change a uniform 4 float vector value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*	Overload
	*	@param target	Name of the target uniform variable
	*	@param x	first float value
	*	@param y	second float value
	*	@param z	third float value
	*	@param w	fourth float value
	*/
	void setVec4(const std::string &target, const glm::vec4 &value) const;
	void setVec4(const std::string &target, float x, float y, float z, float w) const;

	/**
	*	@brief Utility function to change a uniform 2x2 Matrix value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*/
	void setMat2(const std::string &target, const glm::mat2 &value) const;

	/**
	*	@brief Utility function to change a uniform 3x3 Matrix value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*/
	void setMat3(const std::string &target, const glm::mat3 &value) const;

	/**
	*	@brief Utility function to change a uniform 4x4 Matrix value
	*	@param target	Name of the target uniform variable
	*	@param value	Value of the target uniform variable
	*/
	void setMat4(const std::string &target, const glm::mat4 &value) const;


private:
	//ID of the program
	GLuint programID;

	//Disallow default construction
	Shader();
	
};

#endif //SHADER_HPP