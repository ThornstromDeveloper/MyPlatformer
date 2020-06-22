#include "FallingObject.hpp"
#include "PhysicsManager.hpp"

FallingObject::FallingObject(float x, float y, int w, int h):
	GameObject(x, y, w, h),
	desiredPosition(nullptr),
	vx(0), vy(0),
	ax(0), ay(0),
	inAir(false)
{
	this->desiredPosition = new Rectangle();
}

FallingObject::~FallingObject()
{
	delete this->desiredPosition;
}

void FallingObject::preUpdate(float dt)
{
	this->desiredPosition->copy(this->box);

	this->ay = 0;
	this->targetVx = 0;
	this->vy += (PhysicsManager::gravityAcceleration * dt);
}

void FallingObject::commitMovement()
{
	this->position->x -= (this->box->x - this->desiredPosition->x);
	this->position->y -= (this->box->y - this->desiredPosition->y);

	this->box->copy(this->desiredPosition);

	this->boundaryStatus = this->actOnBoundaries();
}