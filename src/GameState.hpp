#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Window.hpp"
#include "Game.hpp"

class GameState
{
public:
	enum class State
	{
		INIT, RUN, QUIT
	};

	GameState(Window* window);
	~GameState();
	GameState::State load(int);
	GameState::State update();

private:
	Window* window;
	GameState* state;
};

#endif //GAMESTATE_HPP
