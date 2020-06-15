#include "Background.hpp"

#include <SDL_image.h>
#include <iostream>

Background::Background(Window* window): 
	window(window)
{
}

void Background::load()
{
	SDL_Texture* texture = IMG_LoadTexture(window->renderer, "resource/BG.png");

	if (texture == NULL) {
		std::cout << "Error loading background" << IMG_GetError();
	}

	SDL_RenderCopy(window->renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}