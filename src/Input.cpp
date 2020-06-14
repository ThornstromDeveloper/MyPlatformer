#include "Input.hpp"
#include "SDL.h"

Input* Input::instance = nullptr;

Input::Input()
{ 
}

Input* Input::getInstance()
{
	if (!instance)
	{
		instance = new Input();
	}

	return instance;
}

void Input::update()
{
	//to be polled
	SDL_Event event;
}