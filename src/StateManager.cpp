#include "StateManager.hpp"
#include "GameStateGame.hpp"
#include "Window.hpp"

StateManager::StateManager(Window* window):
	window(window),
	currentState(nullptr)
{
	this->currentState = new GameStateGame(this->window);
}

StateManager::~StateManager()
{
	if (this->currentState)
	{
		this->currentState->unload();
		delete this->currentState;

		this->currentState = nullptr; // you never know
	}
}

//Main loop of the game
void StateManager::run()
{
}