//File: WindowManager.cpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#include "WindowManager.hpp"

bool WindowManager::startUp() {
	if (!glfwInit())
		return false;

	WindowManager::setHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	WindowManager::setHint(GLFW_CONTEXT_VERSION_MINOR, 3);

}

void WindowManager::setHint(const int target, const int value) {
	glfwWindowHint(target, value);
}