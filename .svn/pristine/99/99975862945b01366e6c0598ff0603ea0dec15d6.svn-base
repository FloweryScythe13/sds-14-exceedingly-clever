#ifndef _WIDGET_H
#define _WIDGET_H

#include <vector>
#include "rect.h"

class Widget {
public:
	Widget(const Rect& pos, float z = 0.0f, Widget* parent = 0);
	virtual ~Widget();
	
	void setPos(const Rect& rect) {pos = rect;}
	Rect getPos() const {return pos;}

	void setAbsPos(const Rect& rect);
	Rect getAbsPos() const;
	
	void addChild(Widget* child);
	void removeChild(Widget* child);
	void setParent(Widget* w) {parent = w;}
	Widget* getParent() {return parent;}
	
	void drawChildren();
	virtual void draw();

	void show() {visible = true;}
	void hide() {visible = false;}
	void toggleVisible() {visible = !visible;}

protected:
	Widget* parent;
	std::vector<Widget*> children;
	
	Rect pos;
	float z;
	bool visible;

private:

};

#endif
