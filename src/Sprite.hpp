#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Window.hpp"

class Sprite
{
public:
	Sprite(Window* window, std::string filename);
	virtual ~Sprite();
	virtual void render();

protected:
	Window* window;
	std::string filename;
	SDL_Texture* image;
};

#endif //SPRITE_HPP