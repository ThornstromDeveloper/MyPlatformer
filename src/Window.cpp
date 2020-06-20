#include <iostream>
#include <math.h>
#include "Window.hpp"
#include "SDL.h"
#include "SDL_image.h"

Window::Window(uint32_t width, uint32_t height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr)
{
	this->setTitle(title);
	this->width = width;
	this->height = height;

	this->create();
}

Window::~Window()
{
	this->destroy();
}

//destroy Window
void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->surface)
	{
		SDL_FreeSurface(this->surface);
		this->surface = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

//create Window
void Window::create()
{
	this->destroy();

	SDL_CreateWindowAndRenderer(this->width, this->height, SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	if (!this->window || !this->renderer)
	{
		std::cout << "SDL Window or SDL Renderer could not be created\n" << SDL_GetError();
		return;
	}

	this->setTitle(this->title);

	this->surface = SDL_GetWindowSurface(this->window);

	if (!this->surface)
	{
		std::cout << "SDL Surface could not be created\n" << SDL_GetError();
		return;
	}
}

//set Window title
void Window::setTitle(std::string title)
{
	if (this->window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}