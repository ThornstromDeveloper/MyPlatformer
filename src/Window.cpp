#include <iostream>
#include "Window.hpp"
#include "SDL.h"

Window::Window(uint32_t width, uint32_t height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr)
{
	this->init(width, height, title);
}

bool Window::init(uint32_t width, uint32_t height, std::string title)
{
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	if (!this->window || !this->renderer)
	{
		std::cout << "SDL Window or SDL Renderer could not be created\n" << SDL_GetError();
		return false;
	}

	SDL_SetWindowTitle(this->window, title.c_str());

	this->surface = SDL_GetWindowSurface(this->window);

	if (!(this->surface))
	{
		std::cout << "SDL Surface could not be created\n" << SDL_GetError();
		return false;
	}

	return true;
}

void Window::clear()
{
	SDL_RenderClear(this->renderer);
}

void Window::draw() {
	SDL_RenderPresent(this->renderer);
}