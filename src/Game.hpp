#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"

class Game
{
public:
	enum class GameState
	{
		QUIT, RUN
	};

	Game(Window* window);
	~Game();
	GameState getState();
	void run();

private:
	Window* window;
};

#endif //GAME_HPP