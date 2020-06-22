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

void Window::setTitle(std::string title)
{
	if (this->window) {
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}

void Window::refresh()
{
	SDL_RenderPresent(this->renderer);
}

SDL_Texture* Window::loadImage(std::string filename)
{
	SDL_Texture* texture = IMG_LoadTexture(this->renderer, filename.c_str());

	return texture;
}

void Window::freeImage(SDL_Texture* image)
{
	if (image)
	{
		SDL_DestroyTexture(image);
	}
}

void Window::freeImage(SDL_Surface* image)
{
	if (image)
	{
		SDL_FreeSurface(image);
	}
}

void Window::renderImage(SDL_Texture* texture, Rectangle* source, Rectangle* destination)
{
	if (!texture || !source || !destination)
	{
		return;
	}

	SDL_Rect sdl_source = { (int)source->x, (int)source->y,	source->w, source->h };
	SDL_Rect sdl_destination = { (int)destination->x, (int)destination->y, destination->w, destination->h };

	SDL_RenderCopy(this->renderer, texture, &sdl_source, &sdl_destination);
}

//clear Window
void Window::clear()
{
}

//How many milliseconds the last frame took
unsigned int Window::getDelta()
{
	return this->current_frame_delta;
}