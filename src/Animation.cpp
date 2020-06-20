#include "Animation.hpp"

Animation::Animation(Window* window, std::string filename, int ammount, int framerate, int loops):
	Sprite(window, filename)
{
    int frameW = this->getWidth() / ammount;
    int frameH = this->getHeight();
}

void Animation::update(float dt)
{
}

void Animation::start()
{
    this->curFrame = 0;
    this->running = true;
}