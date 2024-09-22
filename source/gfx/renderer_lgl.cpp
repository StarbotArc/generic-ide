#include <GL/gl.h>
#include "renderer.hpp"

/**
 *	generic-ide - Legacy OpenGL Renderer.
**/

using namespace gfx;

// WARNING: Use this function for pointers.
template<typename T> static void purge(std::vector<T> &v)
{
	for (auto i : v) delete i;
	v.clear();
}

Renderer::Renderer()
{
}
Renderer::~Renderer()
{
	purge(this->drawables);
}

void Renderer::append(Drawable* drawable)
{
	this->drawables.push_back(drawable);
}

// TODO: This method should probably be finished later.
Drawable* Renderer::find(std::string drawable)
{
	return NULL;
}

void Renderer::draw()
{
	glPushMatrix();
	glScalef(2.0f, -2.0f, 0.0f);
	glTranslatef(-0.5f, -0.5f, 0.0f);

	for (Drawable* d : this->drawables)
	{
		d->draw();
	}
	glPopMatrix();
}

Drawable::Drawable(std::string name)
{
	this->name = name;
}
