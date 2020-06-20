#include "GameStateGame.hpp"
#include "StateManager.hpp"

GameStateGame::GameStateGame(Window* window):
	window(window)
{ 
}

GameStateGame::~GameStateGame()
{ 
}

//unload everything
int GameStateGame::unload()
{
	return 0;
}