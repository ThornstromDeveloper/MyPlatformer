#include <iostream>
#include "SDL.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "Background.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	//initialize SDL
	SDL::init();

	//create window
	Window window(100, 100, "My Platformer");

	//create game, and run
	Game* game = new Game(&window);
	game->run();

	std::cout << "Stopped\n";

	return 0;
}