#include <cstdio>

#include "../gfx/renderer.hpp"
#include "ui.hpp"
#include "ui_editor.hpp"

using namespace ui;

Editor::Editor() : Panel("FileEditor", 0.0f, 0.0f, 0.5f, 0.5f)
{
	std::printf("Size: %f, %f\n", this->dimensions.first, this->dimensions.second);
	std::printf("Pos: %f, %f\n", this->position.first, this->position.second);
}
Editor::~Editor()
{
}

void Editor::update()
{
}
void Editor::draw()
{
	
}

int Editor::onmousepress(int button, double x, double y)
{
	return 0;
}
int Editor::onmousemove(double x, double y)
{
	return 0;
}

int Editor::onkeypress(int key, int modifier)
{
	return 0;
}
