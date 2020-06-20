#include "Player.hpp"
#include "GameStateGame.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	FallingObject(x, y, w, h),
	window(window),
	acceleration(acceleration),
	currentAnimation(nullptr),
	facingDirection(RIGHT)
{ 
	Animation* tmp = nullptr;

	this->animations.resize(ANIMATION_MAX);

	int animationSpeed = 30;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[STANDING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 6, 2);
	this->animations[STANDING_RIGHT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[RUNNING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[RUNNING_RIGHT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[JUMPING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[JUMPING_RIGHT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[FALLING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed);
	this->animations[FALLING_RIGHT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed, 1);
	this->animations[DAMAGING_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed, 1);
	this->animations[DAMAGING_RIGHT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed, 1);
	this->animations[DEATH_LEFT] = tmp;

	tmp = new Animation(this->window, "resource/smb3_mario_sheet.png", 1, animationSpeed, 1);
	this->animations[DEATH_RIGHT] = tmp;

	this->currentAnimation = this->animations[STANDING_RIGHT];
	this->currentAnimation->start();
}

Player::~Player()
{
}

void Player::render(float cameraX, float cameraY)
{
}