#include <iostream>
#include "SDL.hpp"
#include "Window.hpp"
#include "StateManager.hpp"

//Program entry point
int main(int argc, char** argv)
{
	SDL::init();

	//The window on which the game is displayed
	Window window(100, 100, "My Platformer");

	StateManager manager(&window);
	manager.run(); 

	SDL::exit();

	return 0;
}