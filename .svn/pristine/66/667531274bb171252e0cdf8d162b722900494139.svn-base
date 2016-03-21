#include <iostream>
#include "button.h"
#include "menuscreen.h"
#include "render.h"

MenuScreen::MenuScreen(const Rect& pos, float z, Widget* parent) :
	Widget(pos, z, parent), activeButton(0), nextMode(MENU_HOME) {}

MenuScreen::~MenuScreen() {}

void MenuScreen::draw() {
	if(!visible) return;
	drawChildren();
}

void MenuScreen::move(Direction d) {
	if(!activeButton) return;
	if(!activeButton->getNext(d)) return;
	activeButton = activeButton->move(d);
}
