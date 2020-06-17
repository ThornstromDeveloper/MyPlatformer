#include "Sprite.hpp"

//Sprite constructor
Sprite::Sprite(Window* window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr)
{
	this->image = window->loadImage(this->filename);
	int w, h;
	SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

	this->width = w;
	this->height = h;
}

//Sprite destructor
Sprite::~Sprite()
{
	if (this->image)
	{
		this->window->freeImage(this->image);
	}
}

//render Sprite
void Sprite::render()
{
	SDL_Rect src;
	src.x = 100;
	src.y = 100;
	src.w = width;
	src.h = height;

	SDL_Rect dest;
	dest.x = 100;
	dest.y = 100;
	dest.w = 100;
	dest.h = 100;

	this->window->renderImage(this->image, src, dest);
}