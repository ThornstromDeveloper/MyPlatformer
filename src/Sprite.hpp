#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include "SDL.hpp"
#include "Window.hpp"
#include "Shapes.hpp"

class Sprite
{
public:
	Sprite(Window* window, std::string filename);
	virtual ~Sprite();

	void crop(Rectangle rect);
	virtual void render(int x, int y);
	int getWidth();
	int getHeight();
	void restore();

protected:
	Window* window;
	std::string filename;
	SDL_Texture* image;
	Rectangle* clipRect;

	int width;
	int height;
};

#endif //SPRITE_HPP