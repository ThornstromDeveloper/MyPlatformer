#include <iostream>
#include "SDL.hpp"
#include "window.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	SDL::init();
	Window* win = new Window();

	std::cout << "Stopped\n";
}