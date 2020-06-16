#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>

class Window
{
public:
	Window(uint32_t, uint32_t, std::string);
	virtual ~Window();
	void destroy();
	void init(uint32_t, uint32_t, std::string);
	void clear();
	void draw();

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width;
	unsigned int height;

private:

};

#endif //WINDOW