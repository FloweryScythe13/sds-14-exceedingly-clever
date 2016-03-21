#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <GL/gl.h>

//Should only use const Font* to store fonts
class Font;

extern void initFont();
extern const Font* loadFont(std::string path, unsigned int size);

//Don't touch
class Font {
public:
	Font(std::string name, unsigned int size);
	~Font();

	GLuint getTexture() const {return _texture;}
	unsigned int getSize() const {return _size;}
	unsigned int getMaxHeight() const {return _height;}
	unsigned int getMaxWidth() const {return _width;}
	std::string getFilename() const {return _filename;}

	void getGlyphMetrics(char c, float* advx, float* advy, float* bitmapw, 		float* bitmaph, float* bitmapleft,
		  float* bitmaptop, float* texOffsetX) const;

protected:
private:
	GLuint _texture;
	unsigned int _size, _height, _width;
	std::string _filename;

	struct {
		float advx, advy;
		float bitmapw, bitmaph;
		float bitmapleft, bitmaptop;
		float texOffsetX;
	} _metrics[256];
};

#endif