#include "GameObject.hpp"

GameObject::GameObject(float x, float y, int w, int h):
	position(nullptr),
	box(nullptr),
	boundary(-1, -1, -1, -1),
	boundaryStatus(INSIDE_LIMITS)
{
	this->position = new Point(x, y);
	this->box = new Rectangle(x, y, w, h);
}

GameObject::~GameObject()
{
	delete this->position;
	delete this->box;
}

BoundaryStatus GameObject::actOnBoundaries()
{
	if (this->boundary.leftmost != -1)
	{
		if (this->box->leftmost < this->boundary.leftmost)
		{
			this->position->x = this->boundary.leftmost;
			this->box->x = this->boundary.leftmost;
			this->box->update();

			return BoundaryStatus::OFF_LEFT;
		}
	}

	if (this->boundary.rightmost != -1)
	{
		if (this->box->rightmost > this->boundary.rightmost)
		{
			this->position->x = this->boundary.rightmost - this->box->w;
			this->box->x = this->boundary.rightmost - this->box->w;
			this->box->update();

			return BoundaryStatus::OFF_RIGHT;
		}
	}

	if (this->boundary.top != -1)
	{
		if (this->box->top < this->boundary.top)
		{
			this->position->y = this->boundary.top;
			this->box->y = this->boundary.top;
			this->box->update();

			return BoundaryStatus::OFF_TOP;
		}
	}

	if (this->boundary.bottom != -1)
	{
		if (this->box->bottom > this->boundary.bottom)
		{
			this->position->y = this->boundary.bottom - this->box->h;
			this->box->y = this->boundary.bottom - this->box->h;
			this->box->update();

			return BoundaryStatus::OFF_BOTTOM;
		}
	}

	return BoundaryStatus::INSIDE_LIMITS;
}