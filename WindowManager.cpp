//File: WindowManager.cpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#include "WindowManager.hpp"

WindowManager::WindowManager(GLuint w=800, GLuint h=600): width(w),height(h){}
WindowManager::~WindowManager() {}

int WindowManager::checkForClose() {
	return glfwWindowShouldClose(window);
}

void WindowManager::cleanUpBuffer() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void WindowManager::disableGLOption(GLenum target) {
	glDisable(target);
}

void WindowManager::enableGLOption(GLenum target) {
	glEnable(target);
}


void WindowManager::framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
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

void WindowManager::registerFrameBufferResizeCallback(GLFWframebuffersizefun fun) {
	glfwSetFramebufferSizeCallback(window, fun);
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
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

	//Check if the window exists
	if (!window) {
		glfwTerminate();
		return false;
	}

	//Set key callback for the window's input handling
	registerKeyCallback(WindowManager::key_callback);

	//Set framebuffer resize callback
	registerFrameBufferResizeCallback(WindowManager::framebuffer_resize_callback);

	//Make the window the current context
	glfwMakeContextCurrent(window);

	//glad: loads all OpenGl function pointer using 
	//OS specific function calls
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		return false;
	}

	return true;
}

void WindowManager::swapFrameBuffer() {
	glfwSwapBuffers(window);
}
