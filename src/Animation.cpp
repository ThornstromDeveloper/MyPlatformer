#include "Animation.hpp"

//Animation constructor
Animation::Animation(Window* window, std::string filename):
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