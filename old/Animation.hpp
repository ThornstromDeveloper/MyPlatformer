#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"

class Animation : public Sprite
{
public:
	Animation(Window* window, std::string filepath, int amount);
	~Animation();
	void start();
	void update();
	void nextFrame();
	void firstFrame();

private:
	bool running;
	int curFrame;
	int maxFrame;
};

#endif //ANIMATION_HPP