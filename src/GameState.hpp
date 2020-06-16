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
	int unload();
	GameState::State update();
	void render(int);	

private:
	Window* window;
	GameState* state;
	void updateInput();
	bool quit;
};

#endif //GAMESTATE_HPP
