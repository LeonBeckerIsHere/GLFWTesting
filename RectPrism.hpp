#pragma once
#ifndef RECT_PRISM_HPP
#define RECT_PRISM_HPP
#include <glad\glad.h>
#include <vector>
#include "Point.hpp"
class RectPrism {
public:
	RectPrism(Point cntr, GLint l, GLint w, GLint h);
private:
	Point center;
	GLint length, width, height;
	std::vector<GLfloat> vertices;
	GLuint VAO, VBO, EBO;

	void calculateVertices();

};

#endif