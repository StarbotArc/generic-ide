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

	void resize(unsigned int width, unsigned int height);

	void keypress(unsigned int key, unsigned int modifiers);
	void keytyped(unsigned int key);

	void link();
	void run();
private:
	unsigned int width, height;

	GLFWwindow* window;
	gfx::Renderer renderer;
	gfx::FontRenderer fr;
};

static Window* current_window;

#endif//__WINDOW_HPP__
