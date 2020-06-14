#include "Game.hpp"
#include "Background.hpp"

Game::Game(Window* window): 
	window(window)
{
}

Game::~Game() 
{
}

Game::GameState Game::getState()
{
	return GameState::RUN;
}

void Game::run()
{
	GameState state = this->getState();

	if (state == Game::GameState::RUN) 
	{
		Background* bg = new Background(this->window);
		this->window->draw();
	}
}