#ifndef _BUTTON_H
#define _BUTTON_H

#include <string>
#include "direction.h"
#include "label.h"

class Font;
class Button : public Label {
public:
	Button(int offTexture, int onTexture, std::string text, Color tc,
		const Font* font, const Rect& pos, float z = 0.0f,
		Widget* parent = 0);
	~Button();

	virtual void draw();

	bool getSelected() const {return selected;}
	void setSelected(bool on) {selected = on;}

	Button* getNext(Direction d) const {return next[d];}
	void setNext(Direction d, Button* b) {next[d] = b;}

	Button* move(Direction d);

	void enable(bool e) {enabled = e;}
	bool isEnabled() const {return enabled;}

protected:
	int offTex, onTex;
	bool selected;
	bool enabled;

	Button* next[DIR_MAX];

private:

};

#endif
