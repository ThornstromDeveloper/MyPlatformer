#ifndef INPUT_HPP
#define INPUT_HPP

class Input
{
public:	
	Input();
	static Input* getInstance();
	void update();

private:
	static Input* instance;
};

#endif //INPUT_HPP