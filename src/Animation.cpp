#include "Animation.hpp"

Animation::Animation(Window* window, std::string filename, int amount, int framerate, int loops):
	Sprite(window, filename),
	framerate(framerate),
	running(false),
	curFrame(0),
	maxFrame(amount),
	loops(loops),
	timesLooped(0)
{
    int frameW = this->getWidth() / amount;
    int frameH = this->getHeight();

    this->crop(Rectangle(0, 0, frameW, frameH));
}

bool Animation::isRunning()
{
	return this->running;
}

void Animation::update(float dt)
{
	UNUSED(dt);

	if (this->framerate == 0)
	{
		return;
	}

	if (!this->isRunning())
	{
		return;
	}

	this->timer.pause();

	int time_between_frames = (1000 / this->framerate);
	int frames_passed = this->timer.delta() / time_between_frames;

	if (frames_passed == 0)
	{
		timer.unpause();
		return;
	}

	for (int i = 0; i < frames_passed; i++)
	{
		this->nextFrame();
	}

	this->crop(Rectangle(this->clipRect->x, this->clipRect->y, this->clipRect->w, this->clipRect->h));

	this->timer.restart();
}

void Animation::nextFrame()
{
	if (this->framerate == 0)
	{
		return;
	}

	if (!this->running)
	{
		return;
	}

	this->curFrame++;
	this->clipRect->x += this->clipRect->w;

	if (this->curFrame >= this->maxFrame)
	{
		this->firstFrame();
	}
}

void Animation::prevFrame()
{
	if (this->framerate == 0)
	{
		return;
	}

	this->curFrame--;
	this->clipRect->x -= this->clipRect->w;

	if (this->curFrame < 0)
	{
		this->lastFrame();
	}
}

void Animation::firstFrame()
{
	this->curFrame = 0;
	this->clipRect->x = 0;

	if (this->loops != -1)
	{
		this->timesLooped++;

		if ((this->timesLooped) >= (this->loops))
		{
			this->running = false;
		}
	}
}

void Animation::lastFrame()
{
	this->curFrame = this->maxFrame;
	this->clipRect->x = this->clipRect->w * this->maxFrame;
}

void Animation::goTo(int frame)
{
	if ((frame >= 0) && (frame <= (this->maxFrame)))
	{
		this->curFrame = frame;
		this->clipRect->x = (this->clipRect->w * frame);
	}
}

void Animation::setFramerate(int framerate)
{
	this->framerate = framerate;
}

void Animation::start()
{
	if (this->framerate == 0)
	{
		return;
	}

	if (this->running)
	{
		return;
	}

	this->curFrame = 0;
	this->clipRect->x = 0;
	this->timesLooped = 0;
	this->running = true;
	this->timer.start();
}

void Animation::stop()
{
	if (this->framerate == 0) return;
	if (!(this->running))     return;

	this->running = false;
	this->timer.stop();
}

void Animation::restart()
{
	this->stop();
	this->start();
}

void Animation::setLoopAmount(int times)
{
	this->loops = times;
	this->timesLooped = 0;
}