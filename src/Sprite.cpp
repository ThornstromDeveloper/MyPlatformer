#include "Sprite.hpp"

Sprite::Sprite(Window* window, std::string filename):
	window(window),
	filename(filename),
	image(nullptr)
{
}

Sprite::~Sprite()
{
}

void Sprite::render(int x, int y)
{
}