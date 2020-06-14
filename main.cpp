#include <iostream>
#include "SDL.hpp"

//program entry point
int main(int argc, char** argv)
{
	std::cout << "Start\n";

	SDL::init();

	std::cout << "Stopped\n";
}