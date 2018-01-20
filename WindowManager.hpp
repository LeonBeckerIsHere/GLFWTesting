//File: WindowManager.hpp
//Author: Leon Becker
//E-mail: LeonAlexBecker@gmail.com
#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <glad\glad.h>
#include <GLFW\glfw3.h>

class WindowManager {

	//typedef for cleaner code
	using WindowPtr = GLFWwindow*;

public:

	/**	Empty constructor
	 *	Initialization of the object is done in startUp()
	 */
	WindowManager(GLuint w, GLuint h);

	/**	Empty deconstructor
	*	Window gets destroyed in shutDown()
	*/
	~WindowManager();


	/**
	 *	@brief Check if the glfw window should close
	 *	@return 0 if the window should close, 1 otherwise
	 */
	int checkForClose();

	/**
	*	@brief resets buffer bits and also clears the screen
	*/
	void cleanUpBuffer();
	
	/**
	*	@brief	Disables the specified gl option (e.g. depth testing, alpha blending, etc.)
	*	@param	target	Option to disable
	*/
	static void disableGLOption(GLenum target);

	/**
	 *	@brief	Enables the specified gl option (e.g. depth testing, alpha blending, etc.)
	 *	@param	target	Option to enable	
	 */
	static void enableGLOption(GLenum target);

	/**
	 *	@breif Allow glfw poll for events
	 */
	void pollEvents();

	/**
	*	@brief Assign the callback when the client resizes the window
	*/
	void registerFrameBufferResizeCallback(GLFWframebuffersizefun fun);

	/**
	*	@brief	Assign callback function to a window for input
	*	@param	cbfun	The key input handler
	*/
	void registerKeyCallback(GLFWkeyfun cbfun);
	
	/**
	*	@brief render items onto the screen
	*/
	void render();
	
	/**
	 *	@brief	Set glfw hints
	 *	@param	target	Hint to be changed
	 *	@param	value	New value of the hint
	 */
	static void setHint(const int target, const int value);

	/**
	*	@brief	Destruct the object and terminate glfw
	*/
	void shutDown();

	/**
	*	@brief	Intialize glfw and set all values for the window
	*	@return	True if startup is successfull, false otherwise
	*/
	bool startUp();

	/**
	 *	@brief Swap front and back framebuffer
	 */
	void swapFrameBuffer();

private:
	//GLFW Window that is managed by the class
	WindowPtr window;
	//Dimensions of the window
	GLuint width, height;
	/**
	 *	@brief	For key inputs
	 */
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);


	
	//Disable copy contructor/operator
	WindowManager(const WindowManager&);
	WindowManager& operator=(const WindowManager&);

};

#endif	//WINDOW_MANAGER_HPP