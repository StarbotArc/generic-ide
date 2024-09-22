#include "window.hpp"

#include "ui/ui.hpp"
#include "ui/ui_editor.hpp"

static void resize_handler(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::Window()
{
	if (!glfwInit())
	{
		std::cout << "GLFW is not initialized" << std::endl;
		return;
	}

	this->window = glfwCreateWindow(800, 600, "generic-ide", NULL, NULL);

	if (!window)
	{
		std::cout << "Unable to create window." << std::endl;
		return;
	}

	gfx::Drawable* editor = static_cast<gfx::Drawable*>(new ui::Editor);
	this->renderer.append(editor);
}
Window::~Window()
{
	glfwDestroyWindow(this->window);
}

void Window::link()
{
	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);
}
void Window::run()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		this->renderer.draw();

		glfwSwapBuffers(this->window);
		glfwWaitEvents();
	}
}
