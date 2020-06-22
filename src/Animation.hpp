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
    void goTo(int frame);
    void setFramerate(int framerate);
    void start();
    void stop();
    void restart();
    bool isRunning();
    void setLoopAmount(int times = -1);

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