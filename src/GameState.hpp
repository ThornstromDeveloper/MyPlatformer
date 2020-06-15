#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Window.hpp"
#include "Game.hpp"
#include "Background.hpp"

class GameState
{
public:
	enum class State
	{
		INIT, RUN, QUIT
	};

	GameState(Window* window);
	~GameState();
	void load(int);
	GameState::State update();
	void render(int);

private:
	Window* window;
	GameState* state;
};

#endif //GAMESTATE_HPP
