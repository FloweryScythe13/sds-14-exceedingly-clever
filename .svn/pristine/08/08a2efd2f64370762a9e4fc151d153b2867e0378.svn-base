#ifndef _MAINMENUSTATE_H
#define _MAINMENUSTATE_H

#include "gamestate.h"
#include "menumode.h"
#include "party.h"

class InputSystem;
class MenuScreen;
class MainMenuState : public GameState {
public:
	MainMenuState(InputSystem& input, Party& party);
	~MainMenuState();
	
	void onOpen();
	void onClose();
	void onFrame();
	
protected:
private:
	int background;
	MenuMode currentMode;
	MenuScreen* screen[MENU_MAX];

	Party& party;

};

#endif
