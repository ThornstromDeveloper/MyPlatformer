#ifndef FALLINGOBJECT_HPP
#define FALLINGOBJECT_HPP

#include "GameObject.hpp"

class FallingObject: public GameObject
{
public:
	FallingObject(float x, float y, int w, int h);
	virtual ~FallingObject();

	void preUpdate(float dt);
	void commitMovement();

	Rectangle* desiredPosition;

protected:
	float vx;
	float vy;
	float ax;
	float ay;

	float targetVx;
	bool inAir;
};

#endif //FALLINGOBJECT_HPP