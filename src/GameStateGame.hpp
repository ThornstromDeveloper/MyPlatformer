#ifndef GAMESTATEGAME_HPP
#define GAMESTATEGAME_HPP

#include "GameState.hpp"
#include "Window.hpp"
#include "Player.hpp"

class GameStateGame : public GameState
{
public:
	GameStateGame(Window* window);
	virtual ~GameStateGame();

	void load(int stack = 0);
	int unload();
	GameState::StateCode update(float dt);
	void render();

private:
	void updateInput();
	void checkCollisions();
	Window* window;
	bool will_quit;
	Sprite* bg;
	Rectangle* gameArea;
	Player* player;
};

#endif //GAMESTATEGAME_HPP