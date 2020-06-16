#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Window.hpp"

class Player
{
public:
	enum FacingDirection { LEFT, RIGHT };
	enum PossibleAnimation
	{
		STANDING_LEFT, 
		STANDING_RIGHT,
		ANIMATION_MAX
	};

	Player(Window* window);
	virtual ~Player();
	void update();
	void updateAnimation();

private:
	Window* window;
	FacingDirection facingDirection;
};

#endif //PLAYER_HPP