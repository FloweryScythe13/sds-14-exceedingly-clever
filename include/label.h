#ifndef _LABEL_H
#define _LABEL_H

#include <string>
#include "color.h"
#include "widget.h"

class Font;
class Label : public Widget {
public:
	Label(std::string text, int background, Color tc, const Font* font, const Rect& pos,
		float z = 0.0f, Widget* parent = 0);
	~Label();

	virtual void draw();

	std::string getText() const {return text;}
	void setText(std::string t) {text = t;}

	Color getColor() const {return textColor;}
	void setColor(Color c) {textColor = c;}
	
	int getTexture() const {return texture;}
	void setTexture(int t) {texture = t;}

protected:
	std::string text;
	int texture;
	Color textColor;
	const Font* font;

private:

};

#endif
