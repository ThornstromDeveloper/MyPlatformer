#include "GameObject.hpp"

//GameObject constructor
GameObject::GameObject(float x, float y, int w, int h):
	position(nullptr),
	box(nullptr)
{
	this->position = new Point(x, y);
	this->box = new Rectangle(x, y, w, h);
}

//GameObject destructor
GameObject::~GameObject()
{
	delete this->position;
	delete this->box;
}

//get width of GameObject
int GameObject::getWidth()
{
	return this->box->w;
}

//get height of GameObject
int GameObject::getHeight()
{
	return this->box->h;
}