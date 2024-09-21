#include "gfx/renderer.hpp"
#include "ui/ui.hpp"

#include "window.hpp"

#include <iostream>

class mydrawable: public gfx::Drawable
{
public:
	mydrawable() : gfx::Drawable("mydrawable") { };
	~mydrawable()
	{
		std::cout << "he blew up" << std::endl;
	};

	void update() { };
	void draw()
	{
		glBegin(GL_QUADS);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);
		glEnd();
	}
};

int window_width, window_height;

void resize_event(GLFWwindow* window, int width, int height)
{
	window_width = width;
	window_height = height;

	glViewport(0, 0, width, height);
}

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << std::endl;

	if (!glfwInit())
	{
		std::cout << "GLFW is not initialized" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "generic-ide", NULL, NULL);

	if (!window)
	{
		glfwTerminate();

		std::cout << "Window wasn't created" << std::endl;
		return 1;
	}
	glfwSetWindowSizeCallback(window, resize_event);
	glfwMakeContextCurrent(window);

	gfx::Renderer renderer;

	renderer.append(new mydrawable());

	glClearColor(0.2f, 0.4f, 1.0f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glScalef(2.0f, -2.0f, 1.0f);
		glTranslatef(-0.5f, -0.5f, 0.0f);

		renderer.draw();

		glPopMatrix();

		glfwSwapBuffers(window);
		glfwWaitEvents();
	}

	return 0;
}
