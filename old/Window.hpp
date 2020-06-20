#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL.h>
#include "Shapes.hpp"

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
	void create();
	void refresh();
	void clear();
	void setTitle(std::string title);

	void drawBox(Rectangle rect);

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width;
	unsigned int height;

private:
	std::string title;
};

#endif //WINDOW