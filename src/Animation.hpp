#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"

class Animation: public Sprite
{
public:
    Animation(Window* window, std::string filepath, int ammount = 1, int framerate = 0, int loops = -1);
    virtual void update(float dt = 0);
    void nextFrame();
    void start();

private:
    unsigned int framerate;
    bool running;
    int curFrame;
    int maxFrame;
    int loops;
    int timesLooped;
};

#endif //ANIMATION_HPP