#ifndef __UI_UI_EDITOR_HPP__
#define __UI_UI_EDITOR_HPP__

#include <string>

#include "../gfx/renderer.hpp"
#include "ui.hpp"

namespace ui
{
	class Editor: public Panel
	{
	public:
		Editor(gfx::FontRenderer* fr);
		~Editor();

		void update();
		void draw();
	
		int onmousepress(int button, double x, double y);
		int onmousemove(double x, double y);

		int onkeypress(unsigned int key, unsigned int modifiers);
		int onkeytyped(unsigned int key);
	private:
		std::string buffer;

		gfx::FontRenderer* fr;
		gfx::Quad quad;
	};
};

#endif//__UI_UI_EDITOR_HPP__
