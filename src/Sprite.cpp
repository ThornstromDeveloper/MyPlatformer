#include "Sprite.hpp"

Sprite::Sprite(Window* window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr),
	clipRect(nullptr),
	width(0),
	height(0)
{
	this->image = window->loadImage(this->filename);

	int w, h;
	SDL_QueryTexture(image, nullptr, nullptr, &w, &h);

	this->width = w;
	this->height = h;

	this->crop(Rectangle(0, 0, this->width, this->height));
}

Sprite::~Sprite()
{
	if (this->image)
	{
		this->window->freeImage(this->image);
	}

	if (this->clipRect)
	{
		delete this->clipRect;
	}
}

void Sprite::crop(Rectangle rect)
{
	if (!this->clipRect)
	{
		this->clipRect = new Rectangle;
	}

	this->clipRect->copy(&rect);
}

void Sprite::render(int x, int y)
{
	Rectangle destination(x, y, this->clipRect->w, this->clipRect->h);

	this->window->renderImage(this->image, this->clipRect, &destination);
}

int Sprite::getWidth()
{
	return this->clipRect->w;
}

int Sprite::getHeight()
{
	return this->clipRect->h;
}

void Sprite::restore()
{
	this->crop(Rectangle(0, 0, this->width, this->height));
}