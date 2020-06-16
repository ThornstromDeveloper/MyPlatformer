#include <iostream>
#include "Window.hpp"
#include "SDL.h"

Window::Window(uint32_t width, uint32_t height, std::string title):
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	width(width),
	height(height)
{
	this->init(width, height, title);
}

Window::~Window()
{
	this->destroy();
}

void Window::destroy()
{
	if (this->renderer)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}

	if (this->window)
	{
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}
}

void Window::init(uint32_t width, uint32_t height, std::string title)
{
	this->destroy();

	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN_DESKTOP, &(this->window), &(this->renderer));

	if (!this->window || !this->renderer)
	{
		std::cout << "SDL Window or SDL Renderer could not be created\n" << SDL_GetError();
		return;
	}

	SDL_SetWindowTitle(this->window, title.c_str());

	this->surface = SDL_GetWindowSurface(this->window);

	if (!this->surface)
	{
		std::cout << "SDL Surface could not be created\n" << SDL_GetError();
		return;
	}

	this->width = width;
	this->height = height;
}

void Window::clear()
{
	SDL_RenderClear(this->renderer);
}

void Window::draw() 
{
	SDL_RenderPresent(this->renderer);
}