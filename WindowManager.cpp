//File: WindowManager.cpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#include "WindowManager.hpp"

int WindowManager::checkForClose() {
	return glfwWindowShouldClose(window);
}

void WindowManager::cleanUpBuffer() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//Check if the escape key was pressed and then exit the program
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void WindowManager::pollEvents() {
	glfwPollEvents();
}

void WindowManager::registerKeyCallback(GLFWkeyfun cbfun) {
	glfwSetKeyCallback(window, WindowManager::key_callback);
}

void WindowManager::render() {

}

void WindowManager::setHint(const int target, const int value) {
	glfwWindowHint(target, value);
}

void WindowManager::shutDown() {
	glfwTerminate();
}

bool WindowManager::startUp() {
	//Intialize glfw
	if (!glfwInit())
		return false;

	/**	Set hints for glfw
	*	GLFW v3.3
	*/
	WindowManager::setHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	WindowManager::setHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	WindowManager::setHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create the window to be managed
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);

	//Check if the window exists
	if (!window)
		return false;

	//Set key callback for the window's input handling
	registerKeyCallback(WindowManager::key_callback);

	//Make the window the current context
	glfwMakeContextCurrent(window);

	return true;
}

void WindowManager::swapFrameBuffer() {
	glfwSwapBuffers(window);
}
