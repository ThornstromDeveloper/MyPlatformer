#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"

class Animation: public Sprite
{
public:
    Animation(Window* window, std::string filepath, int ammount = 1, int framerate = 0, int loops = -1);
    void start();

private:
    bool running;
    int curFrame;
};

#endif //ANIMATION_HPP