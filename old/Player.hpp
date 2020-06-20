#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "FallingObject.hpp"
#include "Animation.hpp"
#include "Window.hpp"

class Player: public FallingObject
{
public:
	enum class FacingDirection { LEFT, RIGHT };
	enum class PossibleAnimation
	{
		STANDING_LEFT, 
		STANDING_RIGHT,
		ANIMATION_MAX
	};

	Player(Window* window, float x, float y, int w, int h);
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