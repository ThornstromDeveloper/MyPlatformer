#include <iostream>
#include "SDL.hpp"
#include "window.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	//initialize SDL
	SDL::init();

	//create window
	Window window(100, 100, "My Platformer");

	std::cout << "Stopped\n";

	return 0;
}