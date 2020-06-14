#include <iostream>
#include "SDL.hpp"
#include "window.hpp"
#include "Game.hpp"
#include "Background.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	//initialize SDL
	SDL::init();

	//create window
	Window* window = new Window(100, 100, "My Platformer");

	//create game, and run
	Game* game = new Game(window);
	game->run();

	SDL_Delay(3000);

	std::cout << "Stopped\n";

	return 0;
}