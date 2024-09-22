#ifndef __UI_UI_EDITOR_HPP__
#define __UI_UI_EDITOR_HPP__

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
	};
};

#endif//__UI_UI_EDITOR_HPP__
