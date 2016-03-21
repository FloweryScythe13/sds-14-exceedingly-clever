#include "button.h"
#include "render.h"

Button::Button(int offTexture, int onTexture, std::string text, Color tc,
	const Font* font, const Rect& pos, float z, Widget* parent) :
	Label(text, 0, tc, font, pos, z, parent),
	offTex(offTexture), onTex(onTexture), selected(0), enabled(true) {

	for(int i = 0; i < DIR_MAX; ++i) {
		next[i] = 0;
	}
}

Button::~Button() {}

void Button::draw() {
	if(!visible) return;
	drawChildren();

	if(selected) {
		texture = onTex;
	} else {
		texture = offTex;
	}

	Label::draw();
}

Button* Button::move(Direction d) {
	if(!selected) return this;
	if(!next[d]) return this;
	if(!next[d]->isEnabled()) return this;
	setSelected(0);
	next[d]->setSelected(1);
	return next[d];
}