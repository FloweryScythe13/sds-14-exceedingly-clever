#ifndef _MENUSCREEN_H
#define _MENUSCREEN_H

#include <vector>
#include "direction.h"
#include "menumode.h"
#include "widget.h"

class Button;
class InputSystem;
class MenuScreen : public Widget {
public:
	MenuScreen(const Rect& pos = Rect(0, 0, 640, 480), float z = 0.0f, Widget* parent = 0);
	virtual ~MenuScreen();

	virtual void draw();
	virtual void move(Direction d);

	virtual void handleInput(InputSystem& input) = 0;

	virtual void resetMode() {nextMode = mode;}
	void setNextMode(MenuMode next) {nextMode = next;}
	MenuMode getNextMode() const {return nextMode;}

protected:
	Button* activeButton;
	std::vector<Button*> button;

	MenuMode mode;
	MenuMode nextMode;

private:

};

#endif
