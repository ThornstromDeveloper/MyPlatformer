#include "StateManager.hpp"
#include "GameStateGame.hpp"
#include "Window.hpp"

StateManager::StateManager(Window* window):
	window(window),
	currentState(nullptr)
{
	this->currentState = new GameStateGame(this->window);
	this->currentState->load();
}

StateManager::~StateManager()
{
	if (this->currentState)
	{
		this->currentState->unload();
		delete this->currentState;

		this->currentState = nullptr;
	}
}

//Main loop of the game
void StateManager::run()
{
	bool letsQuit = false;

	while (!letsQuit)
	{
		//How many milliseconds the last frame took
		unsigned int delta_ms = this->window->getDelta();

		//How many seconds have passed between last frame and this one?
		float delta = (float)(delta_ms) / 1000.0;

		GameState::StateCode whatToDoNow;

		whatToDoNow = this->currentState->update(delta);

		switch (whatToDoNow)
		{
			case GameState::CONTINUE:
				break;

			case GameState::QUIT:
				letsQuit = true;
				break;

			default:
				break;
		}

		if (this->window)
		{
			this->window->clear();
			this->currentState->render();
			this->window->refresh();
		}

		SDL_Delay(1000);

		letsQuit = true;
	}
}