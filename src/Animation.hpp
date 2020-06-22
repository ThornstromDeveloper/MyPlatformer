#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Sprite.hpp"
#include "Timer.hpp"

class Animation: public Sprite
{
public:
    Animation(Window* window, std::string filepath, int ammount = 1, int framerate = 0, int loops = -1);
    virtual void update(float dt = 0);
    void nextFrame();
    void prevFrame();
    void firstFrame();
    void lastFrame();
    void setFramerate(int framerate);
    void start();
    bool isRunning();

private:
    unsigned int framerate;
    bool running;
    int curFrame;
    int maxFrame;
    Timer timer;
    int loops;
    int timesLooped;
};

#endif //ANIMATION_HPP