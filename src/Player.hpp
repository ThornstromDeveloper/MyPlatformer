#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Window.hpp"

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
	void updateAnimation();

private:
	Window* window;
	FacingDirection facingDirection;
};

#endif //PLAYER_HPP