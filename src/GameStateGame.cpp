#include "GameStateGame.hpp"
#include "StateManager.hpp"
#include "InputManager.hpp"

enum GameStateGameCommands
{
	COMMAND_QUIT, COMMAND_ADD_PLATFORM, COMMAND_INVERT_GRAVITY,
	COMMAND_FLY, COMMAND_ADD_CLOUD, COMMAND_HELP,
	COMMAND_CONTROLS, COMMAND_GIVE_UP
};

GameStateGame::GameStateGame(Window* window):
	window(window),
	will_quit(false),
	gameArea(nullptr),
	player(nullptr)
{ 
}

GameStateGame::~GameStateGame()
{ 
}

void GameStateGame::load(int stack)
{
	UNUSED(stack);

	this->gameArea = new Rectangle(0, 0, this->window->width, this->window->height);

	int playerW = 14;
	int playerH = 27;

	int playerX = 0;
	int playerY = 0;

	this->player = new Player(this->window,	playerX, playerY, playerW, playerH,	100, 30);

	this->player->setBoundary(this->gameArea);
}

int GameStateGame::unload()
{
	delete this->player;

	return 0;
}

GameState::StateCode GameStateGame::update(float dt)
{
	if (this->will_quit)
	{
		return GameState::QUIT;
	}

	this->updateInput();

	this->player->update(dt);

	this->checkCollisions();

	return GameState::CONTINUE;
}

void GameStateGame::render()
{
	this->player->render();
}

void GameStateGame::checkCollisions()
{
	this->player->commitMovement();
}

void GameStateGame::updateInput()
{
	InputManager* input = InputManager::getInstance();

	input->update();

	this->will_quit = input->quitRequested();

	if ((input->isKeyDown(KEY_ESCAPE)) || (input->isKeyDown(KEY_Q)))
	{
		this->will_quit = true;
	}

	if (input->isKeyDown(KEY_A))
	{
		this->render();
		this->window->refresh();
	}

	if (input->isKeyDown(KEY_Z))
	{
		this->window->refresh();
	}
}