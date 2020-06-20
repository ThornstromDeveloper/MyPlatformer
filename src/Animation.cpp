#include "Animation.hpp"

Animation::Animation(Window* window, std::string filename, int ammount, int framerate, int loops):
	Sprite(window, filename)
{
}

void Animation::start()
{
    this->curFrame = 0;
    this->running = true;
}