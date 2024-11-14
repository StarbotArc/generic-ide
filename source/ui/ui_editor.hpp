#ifndef __UI_UI_EDITOR_HPP__
#define __UI_UI_EDITOR_HPP__

#include "../gfx/renderer.hpp"
#include "ui.hpp"

namespace ui
{
	class Editor: public Panel
	{
	public:
		Editor();
		~Editor();

		void update();
		void draw();
	
		int onmousepress(int button, double x, double y);
		int onmousemove(double x, double y);

		int onkeypress(int button, int modifiers);
	private:
		gfx::Quad quad;
	};
};

#endif//__UI_UI_EDITOR_HPP__
