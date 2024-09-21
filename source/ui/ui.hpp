#ifndef __UI_UI_H__
#define __UI_UI_H__

#include "../gfx/renderer.hpp"

namespace ui
{
	class Panel: public gfx::Drawable
	{
	public:
		Panel();
		virtual ~Panel();

		virtual void update();
		virtual void draw();
	private:
		float width, height;
		float x, y;
	};
};

#endif//__UI_UI_H__
