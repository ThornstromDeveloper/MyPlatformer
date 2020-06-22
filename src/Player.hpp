#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "FallingObject.hpp"
#include "DamageableObject.hpp"
#include "Animation.hpp"
#include "Window.hpp"

class Player : public FallingObject,
			   public DamageableObject
{
public:
	enum FacingDirection { LEFT, RIGHT };
	enum PossibleAnimation
	{
		JUMPING_LEFT = 0, JUMPING_RIGHT,
		FALLING_LEFT, FALLING_RIGHT,
		STANDING_LEFT, STANDING_RIGHT,
		RUNNING_LEFT, RUNNING_RIGHT,
		DASHING_LEFT, DASHING_RIGHT,
		DAMAGING_LEFT, DAMAGING_RIGHT,
		DEATH_LEFT, DEATH_RIGHT,
		ANIMATION_MAX
	};

	Player(Window* window, float x, float y, int w, int h, int hp, float acceleration);
	virtual ~Player();

	void update(float dt);
	void render(float cameraX = 0, float cameraY = 0);
	void updateInput();
	void updateAnimation();

private:
	Window* window;
	float acceleration;
	Animation* currentAnimation;
	std::vector<Animation*> animations;
	FacingDirection facingDirection;
};

#endif //PLAYER_HPP