#include "Player.hpp"
#include "Window.hpp"

//Player constructor
Player::Player(Window* window):
	window(window),
	facingDirection(Player::FacingDirection::RIGHT)
{
}

//Player destructor
Player::~Player()
{
}

//update Player
void Player::update()
{
	this->updateAnimation();
}

//update Player animation
void Player::updateAnimation()
{
}