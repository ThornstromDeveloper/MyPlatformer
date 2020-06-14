#include "Game.hpp"
#include "Background.hpp"
#include "Input.hpp"

Game::Game(Window* window): 
	window(window)
{
	quit = false;
	state = GameState::RUN;
}

Game::~Game() 
{
}

void Game::update()
{
	Input* input = Input::getInstance();

	this->state = GameState::RUN;
}

void Game::run()
{
	quit = false;

	while (!quit) {
		this->update();

		switch (this->state) 
		{
			case Game::GameState::RUN:
				Background* bg = new Background(this->window);
				this->window->draw();
				break;
		}

		SDL_Delay(3000);
		quit = true;
	}
}