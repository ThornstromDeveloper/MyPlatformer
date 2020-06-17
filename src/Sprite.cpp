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
	this->window->renderImage(this->image);
}