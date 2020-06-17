#include "Animation.hpp"

//Animation constructor
Animation::Animation(Window* window, std::string filename):
	running(false),
	curFrame(0)
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

//set next Animation frame
void Animation::nextFrame()
{
    this->curFrame++;
}