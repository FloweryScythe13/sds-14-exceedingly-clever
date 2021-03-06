#ifndef _STATUSSCREEN_H
#define _STATUSSCREEN_H

#include "direction.h"
#include "menuscreen.h"

class Font;
class ImageBox;
class Label;
class Party;
class StatusScreen : public MenuScreen {
public:
	StatusScreen(Party& party, const Rect& pos = Rect(0, 0, 640, 480), float z = 0.0f, Widget* parent = 0);
	virtual ~StatusScreen();

	void setCharacter(unsigned int id);
	
	virtual void draw();
	virtual void handleInput(InputSystem& input);
	virtual void resetMode();

protected:
private:
	Party& party;
	int characterID;
	
	const Font* font;
	int base;
	
	Label* charName;
	Label* level;
	Label* primStat;
	Label* secondStat;
	Label* equipment;
	ImageBox* portrait;

};

#endif
