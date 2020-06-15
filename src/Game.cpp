#include "Game.hpp"
#include "Background.hpp"
#include "Input.hpp"
#include "Text.hpp"
#include <iostream>
#include <SDL_ttf.h>

Game::Game(Window* window): 
	window(window),
	quit(false),
	state(GameState::INIT)
{
	Background* bg = nullptr;
	Text* text = nullptr;
	this->load();
}

Game::~Game() 
{
}

int Game::getFrameCount() const
{
	return frameCount;
}

void Game::load()
{
	Background* bg = new Background(this->window);
	Text* text = new Text(this->window, frameCount);

	this->state = GameState::RUN;
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
			case Game::GameState::RUN:
			{
				//this->window->clear();
				this->window->draw();
			}
			break;

			case Game::GameState::QUIT:
			{
				quit = true;
			}
			break;
		}

		frameCount++;
	}
}