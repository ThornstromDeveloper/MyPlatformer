#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>

class Window
{
public:
	Window(uint32_t, uint32_t, std::string);
	bool init(uint32_t, uint32_t, std::string);

private:
	SDL_Window* window;
};

#endif //WINDOW