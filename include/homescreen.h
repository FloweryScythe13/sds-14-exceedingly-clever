#ifndef _HOMESCREEN_H
#define _HOMESCREEN_H

#include "direction.h"
#include "menuscreen.h"

enum HomeScreenMode {
	HS_STATUS,
	HS_ABILITY,
	HS_EQUIPMENT,
	HS_FORMATION,
	HS_ITEM,
	HS_BESTIARY,
	HS_MAP,
	HS_SYSTEM,
	HS_MAX
};

class Party;
class HomeScreen : public MenuScreen {
public:
	HomeScreen(Party& party, const Rect& pos = Rect(0, 0, 640, 480), float z = 0.0f,
		Widget* parent = 0);
	virtual ~HomeScreen();

	virtual void draw();
	virtual void handleInput(InputSystem& input);

	void select(HomeScreenMode mode);
	int getMode() const;

protected:
private:
	Party& party;

};

#endif