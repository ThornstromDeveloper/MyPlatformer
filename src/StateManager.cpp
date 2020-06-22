#include <ctime>
#include "StateManager.hpp"
#include "GameStateGame.hpp"
#include "Window.hpp"

StateManager::StateManager(Window* window):
	window(window),
	currentState(nullptr),
	sharedInfo(0)
{
	this->currentState = new GameStateGame(this->window);

	this->currentState->load();
	this->sharedInfo = 0;

	srand(time(nullptr));
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
	bool firstFrame = true;

	while (!letsQuit)
	{
		//How many milliseconds the last frame took
		unsigned int delta_ms = this->window->getDelta();

		//How many seconds have passed between last frame and this one?
		float delta = (float)(delta_ms) / 1000.0;

		if (firstFrame)
		{
			firstFrame = false;
		}

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

		this->window->delayFramerateIfNeeded();
	}
}