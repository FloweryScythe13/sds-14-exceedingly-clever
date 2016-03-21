#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <map>
#include <string>

enum KeyState {
	KEYSTATE_UP	= 0x0,
	KEYSTATE_DOWN	= 0x1,
	KEYSTATE_TAP	= 0x2,
	KEYSTATE_UNTAP	= 0x4,
	KEYSTATE_MAX	= 0x8
};

class InputSystem {
public:
	InputSystem();
	~InputSystem();

	int update();

	KeyState getKeyState(std::string key);
	bool checkKeyState(std::string key, int state = KEYSTATE_TAP);
	
	void enableKeyRepeat() {_keyRepeat = true;}
	void disableKeyRepeat() {_keyRepeat = false;}

protected:
private:
	std::map<std::string, unsigned int> _keymap;
	std::map<unsigned int, KeyState> _states;

	int _mousex, _mousey;
	bool _keyRepeat;

};

#endif
