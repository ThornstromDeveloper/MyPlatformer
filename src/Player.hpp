#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "FallingObject.hpp"
#include "Window.hpp"

class Player : public FallingObject
{
public:
	Player(Window* window, float x, float y, int w, int h, int hp, float acceleration);
	virtual ~Player();

private:
	Window* window;
	float acceleration;
};

#endif //PLAYER_HPP