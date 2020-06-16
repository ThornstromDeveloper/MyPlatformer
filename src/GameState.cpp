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

	this->player = new Player(this->window);
}

//unload GameState
int GameState::unload()
{
	return 0;
}

//update GameState
GameState::State GameState::update()
{
	this->updateInput();

	if (this->quit) {
		return GameState::State::QUIT;
	}

	return GameState::State::RUN;
}

//render GameState
void GameState::render(int frameCount)
{
	this->load(frameCount);
}

//check Input
void GameState::updateInput()
{
	Input* input = Input::getInstance();

	if (input->quit) {
		this->quit = true;
	}
}