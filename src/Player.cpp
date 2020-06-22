#include "Player.hpp"
#include "InputManager.hpp"
#include "GameStateGame.hpp"

Player::Player(Window* window, float x, float y, int w, int h, int hp, float acceleration):
	FallingObject(x, y, w, h),
	DamageableObject(hp),
	window(window),
	acceleration(acceleration),
	currentAnimation(nullptr),
	facingDirection(RIGHT),
	isJumping(false),
	isDoubleJumping(false),
	win(false),
	thrust(33),
	damaging(false)
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

void Player::update(float dt)
{
	this->preUpdate(dt);

	if (this->boundaryStatus == OFF_BOTTOM)
	{
		this->jump(false);
	}

	this->updateInput();

	float a = 0.2612312321;

	this->vx = (a * this->targetVx) + ((1 - a) * this->vx) * dt;

	if (fabs(this->vx) < this->stoppedThreshold)
	{
		this->vx = 0;
	}

	if (this->damaging)
	{
		if (this->facingDirection == RIGHT)
		{
			this->vx = -10;
		}
		else
		{
			this->vx = 10;
		}
	}

	if (this->isAlive)
	{
		this->desiredPosition->addX(this->vx);
		this->desiredPosition->addY(this->vy);
	}

	if (this->isAlive)
	{
		this->desiredPosition->update();
	}

	this->updateAnimation();
}

void Player::render(float cameraX, float cameraY)
{
	this->currentAnimation->render(this->position->x - cameraX, this->position->y - cameraY);
}

void Player::updateInput()
{
	InputManager* input = InputManager::getInstance();

	float turbo = 1.7;

	if (input->isKeyPressed(KEY_A) || input->isKeyPressed(KEY_LEFT))
	{
		this->targetVx = (-1 * this->acceleration);
		this->facingDirection = LEFT;

		if (input->shift())
		{
			this->targetVx *= turbo;
		}
	}

	if (input->isKeyPressed(KEY_D) || input->isKeyPressed(KEY_RIGHT))
	{
		this->targetVx = (this->acceleration);
		this->facingDirection = RIGHT;

		if (input->shift())
		{
			this->targetVx *= turbo;
		}
	}
}

void Player::updateAnimation()
{
	this->currentAnimation->update();
}

void Player::jump(bool willJump)
{
	if (willJump)
	{
		if (this->isDoubleJumping)
		{
			return;
		}

		if (this->isJumping)
		{
			this->isDoubleJumping = true;
		}

		this->inAir = true;
		this->isJumping = true;

		this->vy = (-1 * this->thrust);
	}
	else
	{
		this->inAir = false;
		this->vy = 0;
		this->isJumping = false;
		this->isDoubleJumping = false;
	}
}