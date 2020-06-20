#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include "SDL.hpp"
#include "Window.hpp"

class Sprite
{
public:
	Sprite(Window* window, std::string filename);
	virtual ~Sprite();

protected:
	Window* window;
	std::string filename;
	SDL_Texture* image;
};

#endif //SPRITE_HPP