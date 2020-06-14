#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"

class Game
{
public:
	Game(Window* window);
	~Game();
	void run();

private:
	Window* window;
};

#endif //GAME_HPP