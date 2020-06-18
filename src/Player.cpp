#include "Player.hpp"
#include "Window.hpp"

//Player constructor
Player::Player(Window* window, int x, int y, int w, int h):
	FallingObject(x, y, w, h),
	window(window),
	facingDirection(Player::FacingDirection::RIGHT)
{
	Animation* tmp = nullptr;

	this->animations.resize(static_cast<int>(Player::PossibleAnimation::ANIMATION_MAX));

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1);
	this->animations[static_cast<int>(Player::PossibleAnimation::STANDING_RIGHT)] = tmp;

	this->currentAnimation = this->animations[static_cast<int>(Player::PossibleAnimation::STANDING_RIGHT)];
	this->currentAnimation->start();
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

//render Player
void Player::render()
{
	this->currentAnimation->render(this->position->x, this->position->y);
}

//update Player animation
void Player::updateAnimation()
{
	this->currentAnimation->update();
	this->currentAnimation->start();
}