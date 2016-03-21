#ifndef _GAMESTATE_H
#define _GAMESTATE_H

class InputSystem;
class GameState {
public:
	GameState(InputSystem& input);
	virtual ~GameState();
	
	virtual void onOpen();
	virtual void onClose();
	virtual void onFrame();
	
	GameState* getNextState() {return nextState;}
	
	bool isRunning() const {return running;}
	bool isFinished() const {return finished;}
	
protected:
	InputSystem& input;
	
	GameState* nextState;
	bool running;
	bool finished;

private:

};

#endif