#ifndef __GFX_RENDERER_HPP__
#define __GFX_RENDERER_HPP__

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <vector>

namespace gfx
{
	void load_renderer();

	class Quad {
	
	};

	class Drawable
	{
	public:
		Drawable(std::string name);
		virtual ~Drawable() {};

		virtual void update() {};
		virtual void draw() {};

		std::string getName();
	protected:
		std::string name;
	};

	struct Glyph {
		unsigned int texture;
		int size[2];
		int offset[2];
		unsigned int shift;
	};

	class FontRenderer
	{
	public:
		FontRenderer(std::string font);
		virtual ~FontRenderer();

		void init();

		void resize(unsigned int width, unsigned int height);

		void print(std::string text, float x, float y, float scale);
	private:
		unsigned int window_width, window_height;

		std::string font;
		Glyph font_glyphs[128];
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
