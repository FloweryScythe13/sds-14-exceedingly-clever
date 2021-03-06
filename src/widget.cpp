#include "render.h"
#include "widget.h"

Widget::Widget(const Rect& pos, float z, Widget* parent) :
	parent(parent), pos(pos), z(z), visible(true) {

	if(parent) {
		parent->addChild(this);
	}
}
	
Widget::~Widget() {
	for(unsigned int i = 0; i < children.size(); ++i) {
		delete children[i];
	}
	
	children.clear();
}

void Widget::setAbsPos(const Rect& rect) {
	if(parent) {
		pos.x = rect.x - parent->getAbsPos().x;
		pos.y = rect.y - parent->getAbsPos().y;
		pos.w = rect.w;
		pos.h = rect.h;
	} else {
		pos = rect;
	}
}

Rect Widget::getAbsPos() const {
	Rect abs(pos);
	if(parent) {
		abs.x += parent->getAbsPos().x;
		abs.y += parent->getAbsPos().y;
	}

	return abs;
}

void Widget::addChild(Widget* child) {
	for(unsigned int i = 0; i < children.size(); ++i) {
		if(child == children[i]) return;
	}
	
	children.push_back(child);
	child->setParent(this);
}

void Widget::removeChild(Widget* child) {
	for(unsigned int i = 0; i < children.size(); ++i) {
		if(child == children[i]) {
			children[i]->setParent(0);
			children.erase(children.begin() + i);
			return;
		}
	}
}

void Widget::drawChildren() {
	for(unsigned int i = 0; i < children.size(); ++i)
		children[i]->draw();
}

void Widget::draw() {
	if(!visible) return;
	drawChildren();
}
