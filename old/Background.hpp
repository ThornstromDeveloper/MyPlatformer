#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Window.hpp"

class Background
{
public:
	Background(Window* window);
	void load();

private:
	Window* window;

};

#endif //BACKGROUND_HPP