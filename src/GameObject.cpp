#include "GameObject.hpp"

GameObject::GameObject(float x, float y, int w, int h):
	position(nullptr),
	box(nullptr)
{
	this->position = new Point(x, y);
	this->box = new Rectangle(x, y, w, h);
}

GameObject::~GameObject()
{
	delete this->position;
	delete this->box;
}