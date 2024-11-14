#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "gfx/renderer.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window();
	virtual ~Window();

	void link();
	void run();
private:
	GLFWwindow* window;
	gfx::Renderer renderer;
	gfx::FontRenderer fr;
};

#endif//__WINDOW_HPP__
