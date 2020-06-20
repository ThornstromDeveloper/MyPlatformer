#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"
#include "GameState.hpp"

class Game
{
public:
	Game(Window* window);
	~Game();
	void run();	

private:
	Window* window;
	GameState* state;
};

#endif //GAME_HPP