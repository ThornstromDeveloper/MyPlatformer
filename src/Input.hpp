#ifndef INPUT_HPP
#define INPUT_HPP

#include "SDL.h"

class Input
{
public:	
	//Returns the singleton instance of this class.
	//This assures that only a single instance of this class is created at any point on the game.
	static Input* getInstance();
	bool update();
	Input();
	bool quit;

private:
	static Input* instance;
	SDL_Event event;
};

#endif //INPUT_HPP