#include <iostream>
#include <GLFW\glfw3.h>
#include "WindowManager.hpp"


int main() {
	WindowManager windowManager;
	
	windowManager.startUp();

	//Loop until the user closes the window
	while (!windowManager.checkForClose()) {
		//Reset the screen and buffers
		windowManager.cleanUpBuffer();

		//swap front and back buffers
		windowManager.swapFrameBuffer();

		//pool for and process events
		windowManager.pollEvents();
	}

	windowManager.shutDown();
	return 0;
}

