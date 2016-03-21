#ifndef _ENGINE_H
#define _ENGINE_H

#include <SDL.h>
#include "inputsystem.h"

class GameState;
class Engine {
public:
	Engine(const char* wname, unsigned int width, unsigned int height);
	~Engine();

	void run(GameState& state);
	void start();

protected:
private:
	unsigned int width, height;
	
	InputSystem input;

	const char* windowName;
	SDL_Window* window;
	SDL_GLContext context;
	
	bool finished;
	
};

#endif
