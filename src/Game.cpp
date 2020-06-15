#include "Game.hpp"
#include "Input.hpp"
#include "GameState.hpp"
#include <iostream>
#include <SDL_ttf.h>

Game::Game(Window* window): 
	window(window),
	state(nullptr),
	frameCount(0)
{
	this->state = new GameState(this->window);
	this->state->load(frameCount);
}

Game::~Game() 
{
}

void Game::run()
{
	quit = false;

	while (!quit) {
		GameState::State action;

		action = this->state->update();

		switch (action) 
		{
			case GameState::State::RUN:
			{
				this->window->clear();
				this->state->render(frameCount);
				this->window->draw();
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