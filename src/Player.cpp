#include "Player.hpp"
#include "GameStateGame.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	FallingObject(x, y, w, h),
	window(window),
	acceleration(acceleration)
{ 
}

Player::~Player()
{
}