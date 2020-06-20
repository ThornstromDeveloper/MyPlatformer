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
	void create();
	void setTitle(std::string title);

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width;
	unsigned int height;

	void refresh();
	void clear();
	unsigned int getDelta();

private:
	std::string title;
	unsigned int current_frame_delta;
};

#endif //WINDOW_HPP