#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shapes.hpp"

class GameObject
{
public:
	GameObject(float x = 0.0, float y = 0.0, int w = 0, int h = 0);
	~GameObject();
	Point* position;
};

#endif //GAMEOBJECT_HPP