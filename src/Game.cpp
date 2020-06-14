#include "Game.hpp"
#include "Background.hpp"

Game::Game(Window* window): window(window)
{
}

Game::~Game() 
{
}

void Game::run()
{
	Background* bg = new Background(this->window);
	this->window->draw();
}