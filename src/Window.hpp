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
	void renderImage(SDL_Texture* texture);
	SDL_Texture* loadImage(std::string filename);
	void create();
	void refresh();
	void clear();
	void setTitle(std::string title);

	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	unsigned int width;
	unsigned int height;

private:
	std::string title;
};

#endif //WINDOW