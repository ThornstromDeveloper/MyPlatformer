#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>

class Window
{
public:
	Window(uint32_t, uint32_t, std::string);
	bool init(uint32_t, uint32_t, std::string);
	void draw();

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

private:

};

#endif //WINDOW