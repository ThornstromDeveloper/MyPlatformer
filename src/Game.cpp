#include "Game.hpp"
#include "GameState.hpp"

//Game constructor
Game::Game(Window* window): 
	window(window),
	state(nullptr),
	frameCount(0)
{
	this->state = new GameState(this->window);
	this->state->load(frameCount);
}

//Game destructor
Game::~Game() 
{
	if (this->state)
	{
		this->state->unload();
		delete this->state;

		this->state = nullptr;
	}
}

//run Game
void Game::run()
{
	bool quit = false;

	while (!quit) {
		GameState::State action;

		action = this->state->update();

		switch (action) 
		{
			case GameState::State::RUN:
			{
				this->window->clear();
				this->state->render(frameCount);
				this->window->refresh();
			}
			break;

			case GameState::State::QUIT:
			{
				quit = true;
			}
			break;
		}

		frameCount++;
	}
}