#include "Player.hpp"
#include "Window.hpp"

//Player constructor
Player::Player(Window* window):
	window(window),
	facingDirection(Player::FacingDirection::RIGHT)
{
	Animation* tmp = nullptr;

	this->animations.resize(static_cast<int>(Player::PossibleAnimation::ANIMATION_MAX));

	tmp = new Animation(this->window, "resource/gubbe.png");
	this->animations[static_cast<int>(Player::PossibleAnimation::STANDING_RIGHT)] = tmp;
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