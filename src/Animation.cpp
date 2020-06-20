#include "Animation.hpp"

Animation::Animation(Window* window, std::string filename, int ammount, int framerate, int loops):
	Sprite(window, filename),
	framerate(framerate),
	running(false),
	curFrame(0),
	maxFrame(ammount),
	loops(loops),
	timesLooped(0)
{
    int frameW = this->getWidth() / ammount;
    int frameH = this->getHeight();

    this->crop(Rectangle(0, 0, frameW, frameH));
}

void Animation::update(float dt)
{
	int frames_passed = 3;

	for (int i = 0; i < frames_passed; i++)
	{
		this->nextFrame();
	}
}

void Animation::nextFrame()
{
	this->curFrame++;
	this->clipRect->x += this->clipRect->w;
}

void Animation::start()
{
    this->curFrame = 0;
    this->running = true;
}