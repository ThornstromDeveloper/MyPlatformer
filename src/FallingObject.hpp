#ifndef FALLINGOBJECT_H_DEFINED
#define FALLINGOBJECT_H_DEFINED

#include "GameObject.hpp"

class FallingObject : public GameObject
{
public:
	FallingObject(float x, float y, int w, int h);
	virtual ~FallingObject();

	Rectangle* desiredPosition;
};

#endif //PLAYER_HPP