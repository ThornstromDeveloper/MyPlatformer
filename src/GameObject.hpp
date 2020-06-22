#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Shapes.hpp"

enum BoundaryStatus
{
    INSIDE_LIMITS,
    OFF_TOP, OFF_BOTTOM, OFF_LEFT, OFF_RIGHT
};

class GameObject
{
public:
    GameObject(float x = 0.0, float y = 0.0, int w = 0, int h = 0);
    ~GameObject();

    virtual void update(float dt) = 0;
    virtual void render(float cameraX, float cameraY) = 0;

    BoundaryStatus actOnBoundaries();

    Point* position;
    Rectangle* box;

    Rectangle boundary;
    BoundaryStatus boundaryStatus;
};

#endif //GAMEOBJECT_HPP