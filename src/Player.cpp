#include "Player.hpp"
#include "GameStateGame.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	FallingObject(x, y, w, h),
	window(window),
	acceleration(acceleration)
{ 
	Animation* tmp = nullptr;

	this->animations.resize(ANIMATION_MAX);
}

Player::~Player()
{
}

void Player::render(float cameraX, float cameraY)
{
}