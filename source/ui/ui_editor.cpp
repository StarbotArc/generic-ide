#include <cstdio>

#include <GL/gl.h>
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
	float x = this->position.first;
	float y = this->position.second;

	float w = this->dimensions.first;
	float h = this->dimensions.second;

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y);
	glEnd();
}
