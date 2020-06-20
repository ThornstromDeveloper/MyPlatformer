#include "Game.hpp"
#include "GameState.hpp"
#include "Background.hpp"
#include "Text.hpp"
#include "Input.hpp"
#include "Player.hpp"

//GameState constructor
GameState::GameState(Window* window):
	window(window),
	quit(false),
	state(nullptr),
	player(nullptr)
{
	Background* bg = nullptr;
	Text* text = nullptr;
	Input* input = nullptr;
	GameState* state = nullptr;
}

//GameState destructor
GameState::~GameState()
{
}

//load GameState
void GameState::load(int frameCount)
{
	Background* bg = new Background(this->window);
	bg->load();

	Text* text = new Text(this->window, frameCount);

	int playerW = 14;
	int playerH = 27;

	int playerX = 100;
	int playerY = 100;

	this->player = new Player(this->window, playerX, playerY, playerW, playerH);
}

//unload GameState
int GameState::unload()
{
	delete this->player;

	return 0;
}

//update GameState
GameState::State GameState::update()
{
	if (this->quit) {
		return GameState::State::QUIT;
	}

	this->updateInput();
	this->player->update();

	return GameState::State::RUN;
}

//render GameState
void GameState::render(int frameCount)
{
	this->load(frameCount);
	this->player->render();
}

//check Input
void GameState::updateInput()
{
	Input* input = Input::getInstance();

	if (input->quit) {
		this->quit = true;
	}
}