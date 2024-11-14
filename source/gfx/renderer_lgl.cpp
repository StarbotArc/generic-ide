#include <GL/gl.h>

#include <iostream>

#include "renderer.hpp"

/**
 *	generic-ide - Legacy OpenGL Renderer.
**/

using namespace gfx;

// WARNING: Use this function for pointers.
template<typename T> static void purge(std::vector<T> &v)
{
	for (auto i : v) delete i;
	v.clear();
}

Renderer::Renderer()
{
}
Renderer::~Renderer()
{
	purge(this->drawables);
}
void Renderer::append(Drawable* drawable)
{
	this->drawables.push_back(drawable);
}
// TODO: This method should probably be finished later.
Drawable* Renderer::find(std::string drawable)
{
	return NULL;
}
void Renderer::draw()
{
	glPushMatrix();
	glScalef(2.0f, -2.0f, 0.0f);
	glTranslatef(-0.5f, -0.5f, 0.0f);

	for (Drawable* d : this->drawables)
	{
		d->draw();
	}
	glPopMatrix();
}

FontRenderer::FontRenderer(std::string font)
{
	this->font = font;	
}
FontRenderer::~FontRenderer()
{
	for (unsigned char c = 0; c < 128; c++)
	{
		glDeleteTextures(1, &this->font_glyphs[c].texture);
	}
}
void FontRenderer::init()
{
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
	{
		std::cout << "Uh oh, FreeType doesn't work." << std::endl;
		return;
	}
	
	FT_Face face;
	if (FT_New_Face(ft, font.c_str(), 0, &face))
	{
		std::cout << "FreeType couldn't load " + font + "." << std::endl;
		return;
	}
	
	FT_Set_Pixel_Sizes(face, 0, 96);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (unsigned char c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "FreeType couldn't create glyph." << std::endl;
			continue;
		}

		Glyph glyph = {
			0,
			{ 0, 0 },
			{ 0, 0 },
			0
		};
		
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		unsigned char bitmap[face->glyph->bitmap.width * face->glyph->bitmap.rows << 2];
		for (int i = 0; i < face->glyph->bitmap.width * face->glyph->bitmap.rows; i++)
		{
			bitmap[i << 2] = 255;
			bitmap[(i << 2) + 1] = 255;
			bitmap[(i << 2) + 2] = 255;
			bitmap[(i << 2) + 3] = face->glyph->bitmap.buffer[i];
		}
		
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			bitmap
		);
		
		std::cout << "Created glyph for " << (char) c << "." << std::endl
			  << texture << std::endl;
		
		glyph.texture = texture;
		glyph.size[0] = face->glyph->bitmap.width;
		glyph.size[1] = face->glyph->bitmap.rows;
		glyph.offset[0] = face->glyph->bitmap_left;
		glyph.offset[1] = face->glyph->bitmap_top;
		glyph.shift = static_cast<unsigned int>(face->glyph->advance.x);

		this->font_glyphs[c] = glyph;
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}
void FontRenderer::print(std::string text, float x, float y, float scale, int width, int height)
{
	scale /= 96.0f;

	glPushMatrix();
	glScalef(2.0f, -2.0f, 0.0f);
	glTranslatef(-0.5f, -0.5f, 0.0f);

	std::string::const_iterator character;

	glEnable(GL_TEXTURE_2D);
	for (character = text.begin(); character != text.end(); character++)
	{
		Glyph glyph = this->font_glyphs[*character];
		
		float w = glyph.size[0] * scale;
		float h = glyph.size[1] * scale;

		float xpos = x + glyph.offset[0] * scale;
		float ypos = y + (-glyph.offset[1]) * scale;

		glBindTexture(GL_TEXTURE_2D, glyph.texture);

		glBegin(GL_QUADS);
		//glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(xpos + w, ypos);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(xpos + w, ypos + h);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(xpos, ypos + h);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(xpos, ypos);
		glTexCoord2f(1.0f, 0.0f);
		glEnd();

		x += (glyph.shift >> 6) * scale;
	}
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

Drawable::Drawable(std::string name)
{
	this->name = name;
}
