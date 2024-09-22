#ifndef __GFX_RENDERER_HPP__
#define __GFX_RENDERER_HPP__

#include <string>
#include <vector>

namespace gfx
{
	class Drawable
	{
	public:
		Drawable(std::string name);
		virtual ~Drawable() {};

		virtual void update() {};
		virtual void draw() {};
	protected:
		std::string name;
	};

	class Renderer
	{
	public:
		Renderer();
		virtual ~Renderer();

		void append(Drawable* drawable);
		Drawable* find(std::string name);

		void draw();
	private:
		std::vector<Drawable*> drawables;
	};
};

#endif//__GFX_RENDERER_HPP__
