#include "Game.hpp"
#include "GameState.hpp"
#include "Background.hpp"
#include "Text.hpp"
#include "Input.hpp"

GameState::GameState(Window* window):
	window(window)
{
	Background* bg = nullptr;
	Text* text = nullptr;
	Input* input = nullptr;
}

GameState::~GameState()
{
}

GameState::State GameState::load(int frameCount)
{
	Background* bg = new Background(this->window);
	Text* text = new Text(this->window, frameCount);

	return GameState::State::RUN;
}

GameState::State GameState::update()
{
	Input* input = Input::getInstance();

	if (input->quit == true) {
		return GameState::State::QUIT;
	}

	return GameState::State::RUN;
}