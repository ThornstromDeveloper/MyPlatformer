#include "Game.hpp"
#include "Background.hpp"
#include "Input.hpp"
#include <iostream>

Game::Game(Window* window): 
	window(window),
	quit(false),
	state(GameState::INIT)
{
	Background* bg = nullptr;
}

Game::~Game() 
{
}

void Game::update()
{
	Input* input = Input::getInstance();

	if (input->quit == true) {
		this->state = GameState::QUIT;
	}
}

void Game::run()
{
	quit = false;

	while (!quit) {
		this->update();

		switch (this->state) 
		{
			case Game::GameState::INIT:
			{
				Background* bg = new Background(this->window);
				this->state = GameState::RUN;
			}
			break;

			case Game::GameState::RUN:
			{
				this->window->draw();
			}
			break;

			case Game::GameState::QUIT:
			{
				quit = true;
			}
			break;
		}
	}
}