#include <iostream>
#include "Window.hpp"
#include "SDL.h"

Window::Window(uint32_t width, uint32_t height, std::string title)
{
	this->window = nullptr;
	this->init(width, height, title);
}

bool Window::init(uint32_t width, uint32_t height, std::string title)
{
	this->window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);

	if (!this->window)
	{
		std::cout << "SDL Window could not be created\n" << SDL_GetError();
	}

	return true;
}