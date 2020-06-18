#include "GameObject.hpp"

//GameObject constructor
GameObject::GameObject(float x, float y, int w, int h):
	position(nullptr)
{
	this->position = new Point(x, y);
}

//GameObject destructor
GameObject::~GameObject()
{
}