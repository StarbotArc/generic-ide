#ifndef __UI_UI_HPP__
#define __UI_UI_HPP__

#include "../gfx/renderer.hpp"

namespace ui
{
	class Panel: public gfx::Drawable
	{
	public:
		Panel(std::string name, float x, float y, float width, float height) :
		gfx::Drawable(name)
		{
			this->dimensions = std::pair<float,float>(width,height);
			this->position = std::pair<float,float>(x, y);
		};
		virtual ~Panel() { }

		virtual int onmousepress(int button, double x, double y) { return 0; }
		virtual int onmousemove(double x, double y) { return 0; }
		
		virtual int onkeypress(unsigned int key, unsigned int modifiers) { return 0; }
		virtual int onkeytyped(unsigned int key) { return 0; }
	protected:
		std::pair<float,float> dimensions;
		std::pair<float,float> position;
	};
};

#endif//__UI_UI_HPP__
