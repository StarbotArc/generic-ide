#include "window.hpp"

#include "ui/ui.hpp"
#include "ui/ui_editor.hpp"

static int window_width;
static int window_height;

static void resize_handler(GLFWwindow* window, int width, int height)
{
	window_width = width;
	window_height = height;

	glViewport(0, 0, width, height);
}

Window::Window() : fr("resource/font.ttf")
{
	if (!glfwInit())
	{
		std::cout << "GLFW is not initialized" << std::endl;
		return;
	}

	this->window = glfwCreateWindow(800, 600, "generic-ide", NULL, NULL);
	window_width = 800;
	window_height = 600;

	if (!window)
	{
		std::cout << "Unable to create window." << std::endl;
		return;
	}

	gfx::Drawable* editor = dynamic_cast<gfx::Drawable*>(new ui::Editor);
	this->renderer.append(editor);
}
Window::~Window()
{
	glfwDestroyWindow(this->window);
}

void Window::link()
{
	glfwMakeContextCurrent(this->window);

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

		//this->renderer.draw();
		this->fr.print("hello world! text", 0.0f, 0.5f, 1.0f / 32.0f, 1.0f, 1.0f);

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}
