#include "window.hpp"

#include "ui/ui.hpp"
#include "ui/ui_editor.hpp"

static void resize_handler(GLFWwindow* window, int width, int height)
{
	current_window->resize(
		static_cast<unsigned int>(width),
		static_cast<unsigned int>(height)
	);

	glViewport(0, 0, width, height);
}
static void keypress_handler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action != GLFW_RELEASE)
	{
		current_window->keypress(key, mods);
	}
}
static void keytyped_handler(GLFWwindow* window, unsigned int code)
{
	current_window->keytyped(code);
}

Window::Window() : fr("resource/font.ttf")
{
	if (!glfwInit())
	{
		std::cout << "GLFW is not initialized" << std::endl;
		return;
	}

	this->window = glfwCreateWindow(800, 600, "generic-ide", NULL, NULL);
	
	this->resize(800, 600);

	if (!window)
	{
		std::cout << "Unable to create window." << std::endl;
		return;
	}


	glfwSetKeyCallback(this->window, keypress_handler);
	glfwSetCharCallback(this->window, keytyped_handler);

	glfwSetFramebufferSizeCallback(this->window, resize_handler);

	ui::Editor* editor = new ui::Editor(&this->fr);
	this->renderer.append(editor);
}
Window::~Window()
{
	glfwDestroyWindow(this->window);
	current_window = NULL;
}

void Window::resize(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;

	this->fr.resize(width, height);
}

void Window::keypress(unsigned int key, unsigned int modifiers)
{
	ui::Editor* editor = static_cast<ui::Editor*>(this->renderer.find("FileEditor"));
	
	editor->onkeypress(key, modifiers);
}

void Window::keytyped(unsigned int key)
{
	ui::Editor* editor = static_cast<ui::Editor*>(this->renderer.find("FileEditor"));
	
	editor->onkeytyped(key);
}

void Window::link()
{
	glfwMakeContextCurrent(this->window);
	
	current_window = this;

	this->fr.init();

	glfwSwapInterval(1);
}
void Window::run()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		this->renderer.draw();

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}
