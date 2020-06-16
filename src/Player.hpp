#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Window.hpp"

class Player
{
public:
	Player(Window* window);
	virtual ~Player();
	void update();
	void updateAnimation();

private:
	Window* window;
};

#endif //PLAYER_HPP