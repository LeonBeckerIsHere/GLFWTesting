//File: main.cpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#include <iostream>
#include <GLFW\glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		std::cout << "Escape key was pressed" << std::endl;
	}
}

int main() {
	//Intialize library
	if (!glfwInit()) {
		return -1;
	}
	
	//Set hints so the window knows what opengl version we are targeting
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


	//Create a windowed mode window and its OpenGl context
	GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	
	//Check if window has been made
	if (!window){
		std::cerr << "Failed to create a GLFW window." << std::endl;
		glfwTerminate();
		return -1;
	}
	
	//add input callback to window
	glfwSetKeyCallback(window, key_callback);

	//Make the window's context current
	glfwMakeContextCurrent(window);

	//Loop until the user closes the window
	while (!glfwWindowShouldClose(window)) {

		//render here
		glClear(GL_COLOR_BUFFER_BIT);

		//swap front and back buffers
		glfwSwapBuffers(window);

		//pool for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

