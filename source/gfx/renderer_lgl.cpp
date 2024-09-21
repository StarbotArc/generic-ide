#include "renderer.hpp"

/**
 *	generic-ide - Legacy OpenGL Renderer.
**/

// Yes, we're using. Yes, it will probably be removed.
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
	for (Drawable* d : this->drawables)
	{
		d->draw();
	}
}

Drawable::Drawable(std::string name)
{
	this->name = name;
}
