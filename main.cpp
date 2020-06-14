#include <iostream>
#include "SDL.hpp"
#include "window.hpp"
#include "background.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	//initialize SDL
	SDL::init();

	//create window
	Window* window = new Window(100, 100, "My Platformer");
	Background* bg = new Background(window);
	window->draw();

	SDL_Delay(5000);

	std::cout << "Stopped\n";

	return 0;
}