#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"

class Game
{
public:
	enum class GameState
	{
		INIT, RUN, QUIT
	};

	Game(Window* window);
	~Game();
	void update();
	void run();

private:
	Window* window;
	GameState state;
	bool quit;
};

#endif //GAME_HPP