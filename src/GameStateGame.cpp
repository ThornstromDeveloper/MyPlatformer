#include "GameStateGame.hpp"
#include "StateManager.hpp"

GameStateGame::GameStateGame(Window* window):
	window(window),
	player(nullptr)
{ 
}

GameStateGame::~GameStateGame()
{ 
}

void GameStateGame::load(int stack)
{
	int playerW = 14;
	int playerH = 27;

	int playerX = 0;
	int playerY = 0;

	this->player = new Player(this->window,	playerX, playerY, playerW, playerH,	100, 30);
}

int GameStateGame::unload()
{
	delete this->player;

	return 0;
}

GameState::StateCode GameStateGame::update(float dt)
{
	this->player->update(dt);

	return GameState::CONTINUE;
}

void GameStateGame::render()
{
	this->player->render();
}