#include <GL/gl.h>

#include <cstdio>

#include "../gfx/renderer.hpp"
#include "ui.hpp"
#include "ui_editor.hpp"

using namespace ui;

Editor::Editor(gfx::FontRenderer* fr) : Panel("FileEditor", 0.1f, 0.05f, 0.8f, 0.75f)
{
	std::printf("Size: %f, %f\n", this->dimensions.first, this->dimensions.second);
	std::printf("Pos: %f, %f\n", this->position.first, this->position.second);

	this->fr = fr;
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

	glLineWidth(1.0f);
	glBegin(GL_LINE_LOOP);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(x + 0.0f, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y + 0.0f);
	glVertex2f(x + 0.0f, y + 0.0f);
	glEnd();

	this->fr->print(this->buffer, x + 0.0f, y + 0.002f, 1.0f / 2.0f);
}

int Editor::onmousepress(int button, double x, double y)
{
	return 0;
}
int Editor::onmousemove(double x, double y)
{
	return 0;
}

/* Handles all special keys that cannot be used by CharCallback in GLFW. */
int Editor::onkeypress(unsigned int key, unsigned int modifiers)
{
	std::printf("Key: %u\n", key);
	switch (key)
	{
		case 259: {
			if (!this->buffer.length()) return 0;

			size_t end = this->buffer.length() - 1;
			this->buffer.erase(end, 1);
		}
	}
	return 0;
}
/* Handles all keys that has a visible character */
int Editor::onkeytyped(unsigned int key)
{
	this->buffer += static_cast<char>(key);
	return 0;
}
