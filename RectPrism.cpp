#include "RectPrism.hpp"

void RectPrism::calculateVertices() {
	float nX = width / 2.0, nY = height / 2.0, nZ = length / 2.0;

	vertices = {
		-nX, -nY, -nZ,  0.0f, 0.0f,
		 nX, -nY, -nZ,  1.0f, 0.0f,
		 nX,  nY, -nZ,  1.0f, 1.0f,
		 nX,  nY, -nZ,  1.0f, 1.0f,
		-nX,  nY, -nZ,  0.0f, 1.0f,
		-nX, -nY, -nZ,  0.0f, 0.0f,

		-nX, -nY,  nZ,  0.0f, 0.0f,
		 nX, -nY,  nZ,  1.0f, 0.0f,
		 nX,  nY,  nZ,  1.0f, 1.0f,
		 nX,  nY,  nZ,  1.0f, 1.0f,
		-nX,  nY,  nZ,  0.0f, 1.0f,
		-nX, -nY,  nZ,  0.0f, 0.0f,

		-nX,  nY,  nZ,  1.0f, 0.0f,
		-nX,  nY, -nZ,  1.0f, 1.0f,
		-nX, -nY, -nZ,  0.0f, 1.0f,
		-nX, -nY, -nZ,  0.0f, 1.0f,
		-nX, -nY,  nZ,  0.0f, 0.0f,
		-nX,  nY,  nZ,  1.0f, 0.0f,

		 nX,  nY,  nZ,  1.0f, 0.0f,
		 nX,  nY, -nZ,  1.0f, 1.0f,
		 nX, -nY, -nZ,  0.0f, 1.0f,
		 nX, -nY, -nZ,  0.0f, 1.0f,
		 nX, -nY,  nZ,  0.0f, 0.0f,
		 nX,  nY,  nZ,  1.0f, 0.0f,

		-nX, -nY, -nZ,  0.0f, 1.0f,
		 nX, -nY, -nZ,  1.0f, 1.0f,
		 nX, -nY,  nZ,  1.0f, 0.0f,
		 nX, -nY,  nZ,  1.0f, 0.0f,
		-nX, -nY,  nZ,  0.0f, 0.0f,
		-nX, -nY, -0.5f,  0.0f, 1.0f,

		-nX,  nY, -nZ,  0.0f, 1.0f,
		 nX,  nY, -nZ,  1.0f, 1.0f,
		 nX,  nY,  nZ,  1.0f, 0.0f,
		 nX,  nY,  nZ,  1.0f, 0.0f,
		-nX,  nY,  nZ,  0.0f, 0.0f,
		-nX,  nY, -nZ,  0.0f, 1.0f
	};
}

RectPrism::RectPrism(Point cntr, GLint l=0, GLint w=0, GLint h=0): center(cntr),length(l), width(w), height(h){
	
	calculateVertices();
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Not sure if vertices.data() is the proper thing to put for a vector
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

