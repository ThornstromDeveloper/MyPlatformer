#include <iostream>
#include <math.h>
#include "Window.hpp"
#include "SDL.h"
#include "SDL_image.h"

//Window constructor
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

//update Window
void Window::refresh()
{
	SDL_RenderPresent(this->renderer);
}

//load image to Window renderer
SDL_Texture* Window::loadImage(std::string filename)
{
	SDL_Texture* texture = IMG_LoadTexture(this->renderer, filename.c_str());

	return texture;
}

//free texture image from Window
void Window::freeImage(SDL_Texture* image)
{
	if (image)
	{
		SDL_DestroyTexture(image);
	}
}

//free surface image from Window
void Window::freeImage(SDL_Surface* image)
{
	if (image)
	{
		SDL_FreeSurface(image);
	}
}

//render image in Window
void Window::renderImage(SDL_Texture* texture, Rectangle* source, Rectangle* destination)
{
	if (!texture || !source || !destination)
	{
		std::cout << "Window::render: Tried to show a nullptr image\n";
		return;
	}

	SDL_Rect sdl_source = { (int)source->x, (int)source->y, source->w, source->h };
	SDL_Rect sdl_destination = { (int)destination->x, (int)destination->y, destination->w, destination->h };

	SDL_RenderCopy(this->renderer, texture, &sdl_source, &sdl_destination);
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