#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>
#include "Color.hpp"
#include "Shapes.hpp"
#include "Timer.hpp"

class Window
{
public:
	Window(uint32_t, uint32_t, std::string);
	virtual ~Window();

	void destroy();
	void renderImage(SDL_Texture* texture, Rectangle* source, Rectangle* destination);
	SDL_Texture* loadImage(std::string filename);
	void freeImage(SDL_Texture* image);
	void freeImage(SDL_Surface* image);
	void refresh();
	void create();
	void fill(Color color);
	void setTitle(std::string title);

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width;
	unsigned int height;

	unsigned int originalWidth;
	unsigned int originalHeight;
	bool isFullscreen;

	void clear();
	void delayFramerateIfNeeded();
	unsigned int getDelta();

private:
	std::string title;
	Color bg_color;
	Timer framerateTimer;
	unsigned int framerate;
	unsigned int frame_delay;
	unsigned int current_frame_delta;
};

#endif //WINDOW_HPP