#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Window.hpp"

class Animation
{
public:
	Animation(Window* window, std::string filepath);
	~Animation();
	void start();
	void update();
	void nextFrame();

private:
	bool running;
	int curFrame;
};

#endif //ANIMATION_HPP