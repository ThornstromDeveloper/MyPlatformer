#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"

class Game
{
public:
	enum class GameState
	{
		INIT, RUN, QUIT
	};

	Game(Window* window);
	~Game();
	int getFrameCount() const;
	void load();
	void update();
	void run();	

private:
	Window* window;
	GameState state;
	int frameCount;
	bool quit;
};

#endif //GAME_HPP