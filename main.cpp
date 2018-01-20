#include "Shader.hpp"
#include "WindowManager.hpp"

#include <glm/glm.hpp>
int main() {

	//Create a WindowManager object;
	WindowManager windowManager(800,600);
	
	//Intialize the settings of the WindowManager
	if (!windowManager.startUp()) {
		std::cout << "WindowManager failed to start up" << std::endl;
		return -1;
	}

	//Load the and link shader files to the Shader object7
	Shader firstShader("firstVertex.glsl", "firstFragment.glsl");

	//~~~~~~~~~~~~~~~~~Delete B
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);	
	//~~~~~~~~~~~~~~~~~~~~~Delete B

	//Loop until the user closes the window
	while (!windowManager.checkForClose()) {
		//Reset the screen and buffers
		windowManager.cleanUpBuffer();
		
		//```````````````````````````Delete C
		firstShader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//``````````````````````````Delete C

		//Swap buffers
		windowManager.swapFrameBuffer();
		//pool for and process events
		windowManager.pollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	windowManager.shutDown();
	return 0;
}

