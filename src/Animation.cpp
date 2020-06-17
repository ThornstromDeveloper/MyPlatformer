#include "Animation.hpp"

//Animation constructor
Animation::Animation(Window* window, std::string filename, int amount):
	Sprite(window, filename),
	running(false),
	curFrame(0),
	maxFrame(amount)
{
}

//Animation destructor
Animation::~Animation()
{
}

//start Animation
void Animation::start()
{
	this->curFrame = 0;
	this->running = true;
}

//update Animation
void Animation::update()
{
	this->nextFrame();
}

//next frame of Animation
void Animation::nextFrame()
{
    this->curFrame++;

	if (this->curFrame >= this->maxFrame)
	{
		this->firstFrame();
	}
}

//first frame of Animation
void Animation::firstFrame()
{
    this->curFrame = 0;
}