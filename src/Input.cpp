#include "Input.hpp"
#include "SDL.h"

Input* Input::instance = nullptr;

Input::Input():
	quit(false)
{ 	
}

Input* Input::getInstance()
{
	if (!instance)
	{
		instance = new Input();
	}

	instance->update();

	return instance;
}

bool Input::update()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				{
					this->quit = true;
				}
					break;
			}
		}
	}

	return true;
}