#include "label.h"
#include "render.h"

Label::Label(std::string text, int background, Color tc, const Font* font,
	const Rect& pos, float z, Widget* parent) :
	Widget(pos, z, parent), text(text), texture(background), textColor(tc), font(font) {}

Label::~Label() {}

void Label::draw() {
	if(!visible) return;
	drawChildren();

	if(texture) {
		drawTexture(texture, getAbsPos(), z + .0001);
	}
	
	drawText(font, text.c_str(), textColor,
		getAbsPos().x, getAbsPos().y, z);
}
