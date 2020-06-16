#include <iostream>
#include "Window.hpp"
#include "SDL.h"

//Window constructor
Window::Window(uint32_t width, uint32_t height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height),
	title(title)
{
	this->create(width, height, title);
}

//Window destructor
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
void Window::create(uint32_t width, uint32_t height, std::string title)
{
	this->destroy();

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	if (!this->window || !this->renderer)
	{
		std::cout << "SDL Window or SDL Renderer could not be created\n" << SDL_GetError();
		return;
	}

	this->setTitle(title);

	this->surface = SDL_GetWindowSurface(this->window);

	if (!this->surface)
	{
		std::cout << "SDL Surface could not be created\n" << SDL_GetError();
		return;
	}

	this->width = width;
	this->height = height;
}

//update Window
void Window::refresh()
{
	SDL_RenderPresent(this->renderer);
}

//clear Window
void Window::clear()
{
	SDL_RenderClear(this->renderer);
}

//set Window title
void Window::setTitle(std::string title)
{
	if (this->window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}

