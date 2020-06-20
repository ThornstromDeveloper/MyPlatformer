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

//load everything
void GameStateGame::load(int stack)
{
	int playerW = 14;
	int playerH = 27;

	int playerX = 0;
	int playerY = 0;

	this->player = new Player(this->window,	playerX, playerY, playerW, playerH,	100, 30);
}

//unload everything
int GameStateGame::unload()
{
	return 0;
}

//update game state
GameState::StateCode GameStateGame::update(float dt)
{
	return GameState::CONTINUE;
}

//render game state
void GameStateGame::render()
{
}