#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <GL/gl.h>
#include "font.h"

//Globals
FT_Library ft;
std::map<const Font*, unsigned int> loadedFonts;

//Function definitions
void initFont() {
	if(FT_Init_FreeType(&ft)) {
		std::cout << "Could not initialize freetype.\n";
		return;
	}
};

const Font* loadFont(std::string path, unsigned int size) {
	std::string absolute = path;

	if(path.empty()) return 0;
	std::map<const Font*, unsigned int>::iterator iter;

	for(iter = loadedFonts.begin(); iter != loadedFonts.end(); ++iter) {
		if(iter->first) {
			if(!absolute.compare(iter->first->getFilename()) &&
				(iter->first->getSize() == size)) {
				++iter->second;
				return iter->first;
			}
		}
	}

	const Font* font = new Font(path, size);
	if(!font->getTexture()) {
		delete font;
		return 0;
	}

	loadedFonts[font] = 1;
	return font;
}

Font::Font(std::string name, unsigned int size) :
	_texture(0), _size(size), _height(0), _width(0),
	_filename(name) {

	FT_Face face = 0;
	int w = 0;
	int h = 0;
	int wpad = 0;
	int hpad = 0;
	
	std::cout << "Loading font " << name << " with a size of " << size << '\n';
	if(FT_New_Face(ft, _filename.c_str(), 0, &face)) {
		std::cout << "Error loading font face. Check if " <<
			name << " exists.\n";
		return;
	}

	if(FT_Set_Pixel_Sizes(face, 0, size)) {
		std::cout << "Error setting pixel size\n";
		return;
	}

	for(int i = 0; i < 256; ++i) {
		if(FT_Load_Char(face, i, FT_LOAD_RENDER)) {
			std::cout << "Error loading char " << i << '\n';
		} else {
			FT_GlyphSlot glyph = face->glyph;
			w += glyph->bitmap.width;
			h = std::max(h, glyph->bitmap.rows);
			_width = std::max(_width, (unsigned int)glyph->bitmap.width);
		}
	}

	_height = h;
	_width = w;
	//Round width and height to the next power of two
	wpad = w;
	--wpad;
	wpad |= wpad >> 1;
	wpad |= wpad >> 2;
	wpad |= wpad >> 4;
	wpad |= wpad >> 8;
	wpad |= wpad >> 16;
	++wpad;

	hpad = h;
	--hpad;
	hpad |= hpad >> 1;
	hpad |= hpad >> 2;
	hpad |= hpad >> 4;
	hpad |= hpad >> 8;
	hpad |= hpad >> 16;
	++hpad;
	GLubyte* pixels = new GLubyte[wpad * hpad];
	memset(pixels, 0, wpad * hpad);

	int x = 0;
	for(int i = 0; i < 256; ++i) {
		if(FT_Load_Char(face, i, FT_LOAD_RENDER)) {
			std::cout << "Error loading char " << i << '\n';
		} else {
			FT_GlyphSlot glyph = face->glyph;
			FT_Bitmap bitmap = glyph->bitmap;

			_metrics[i].advx = (float)(glyph->advance.x >> 6);
			_metrics[i].advy = (float)(glyph->advance.y >> 6);
			_metrics[i].bitmapw = (float)bitmap.width;
			_metrics[i].bitmaph = (float)bitmap.rows;
			_metrics[i].bitmapleft = (float)glyph->bitmap_left;
			_metrics[i].bitmaptop = (float)glyph->bitmap_top;
			_metrics[i].texOffsetX = (float)x;

			for(int j = 0; j < bitmap.width; ++j)
			for(int k = 0; k < bitmap.rows; ++k) {
				int index = k * wpad + x;
				pixels[index + j] = bitmap.buffer[j + k * bitmap.width];
			}

			x += (int)(glyph->advance.x >> 6);
		}
	}
	
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glActiveTexture(GL_TEXTURE0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, wpad, hpad, 0, GL_ALPHA, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete[] pixels;
	FT_Done_Face(face);
}

Font::~Font() {}

void Font::getGlyphMetrics(char c, float* advx, float* advy,
	float* bitmapw, float* bitmaph,
	float* bitmapleft, float* bitmaptop, float* texOffsetX) const {

	if(c < 32) return;
	if(advx) *advx = _metrics[(unsigned char)c].advx;
	if(advy) *advy = _metrics[(unsigned char)c].advy;
	if(bitmapw) *bitmapw = _metrics[(unsigned char)c].bitmapw;
	if(bitmaph) *bitmaph = _metrics[(unsigned char)c].bitmaph;
	if(bitmapleft) *bitmapleft = _metrics[(unsigned char)c].bitmapleft;
	if(bitmaptop) *bitmaptop = _metrics[(unsigned char)c].bitmaptop;
	if(texOffsetX) *texOffsetX = _metrics[(unsigned char)c].texOffsetX;
}
