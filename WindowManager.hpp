//File: WindowManager.hpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <memory>
#include <GLFW\glfw3.h>

class WindowManager {

	//typedef for cleaner code
	using WindowPtr = std::shared_ptr<GLFWwindow>;

public:
	/**
	 *	@brief	Intialize glfw and set all values for the window
	 *	@return	True if startup is successfull, false otherwise
	 */
	static bool startUp();
	
	/**
	 *	@brief	Makes a window the current context
	 */
	static void makeContextCurrent(WindowPtr &window);

	/**
	*	@brief	Assign callback function to a window for input
	*	@param	window	The target window
	*	@param	cbfun	The key input handler
	*/
	static void registerKeyCallback(WindowPtr &window, GLFWkeyfun cbfun);

	/**
	 *	@brief	Set glfw hints
	 *	@param	target	Hint to be changed
	 *	@param	value	New value of the hint
	 */
	static void setHint(const int target, const int value);

	/**
	 *	@brief	Destruct the object and terminate glfw
	 */
	static void shutDown();

private:
	/**
	 *	@brief	For key inputs
	 */
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	/**
	 *	@brief	GLFW Window being managed
	 */
	WindowPtr window;

	//Prevent compiler from generating the following methods
	WindowManager();
	~WindowManager();
	WindowManager(const WindowManager&);
	WindowManager& operator=(const WindowManager&);

};

#endif	//WINDOW_MANAGER_H