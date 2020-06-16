#include <iostream>
#include "SDL.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

bool SDL::init()
{
	//Initialize SDL Video
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Video could not initialize!" << SDL_GetError();
	}

	//Initialize SDL Image
	if (SDL_Init(IMG_INIT_PNG) < 0)
	{
		std::cout << "SDL Image could not initialize!" << IMG_GetError();
	}

	//Initialize SDL Font
	if (TTF_Init() < 0)
	{
		std::cout << "SDL Font could not initialize!" << TTF_GetError();
	}

	return true;
}

void SDL::exit()
{
	SDL_Quit();
}