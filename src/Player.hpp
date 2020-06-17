#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Window.hpp"
#include "Animation.hpp"

class Player
{
public:
	enum class FacingDirection { LEFT, RIGHT };
	enum class PossibleAnimation
	{
		STANDING_LEFT, 
		STANDING_RIGHT,
		ANIMATION_MAX
	};

	Player(Window* window);
	virtual ~Player();
	void update();
	void render();
	void updateAnimation();

private:
	Window* window;
	Animation* currentAnimation;
	std::vector<Animation*> animations;
	FacingDirection facingDirection;
};

#endif //PLAYER_HPP