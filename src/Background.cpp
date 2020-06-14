#include "Background.hpp"

#include <SDL_image.h>
#include <iostream>

Background::Background(Window* window)
{
	SDL_Texture* texture = IMG_LoadTexture(window->renderer, "BG.png");

	if (texture == NULL) {
		std::cout << "Error loading background" << IMG_GetError();
	}

	SDL_RenderCopy(window->renderer, texture, NULL, NULL);
}