#include "Game.hpp"
#include "GameState.hpp"

//Game constructor
Game::Game(Window* window): 
	window(window),
	state(nullptr)
{
	this->state = new GameState(this->window);
	this->state->load(0);
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
	int frameCount = 0;
	GameState::State action;

	while (!quit) {
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