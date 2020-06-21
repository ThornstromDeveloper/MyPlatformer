#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "SDL.h"
#include "Shapes.hpp"
#include "InputDefinitions.hpp"

class InputManager
{
public:
    static InputManager* getInstance();
    void update(float cameraX=0, float cameraY=0);

    bool isKeyDown(int key);
    bool isKeyUp(int key);
    bool shift();
	bool ctrl();
	bool alt();
    bool isMouseDown(MouseButton button);
    bool isMouseUp(MouseButton button);
    bool isKeyPressed(KeyboardKey key);
    bool isMousePressed(MouseButton button);
    bool quitRequested();
    int getMouseX();
    int getMouseY();
    void lock();
    void unlock();
	bool isMouseInside(Rectangle rectangle);
    static bool isPrintable(SDL_Keycode key);
    bool isPrintableKeyDown();
    InputManager();
    InputManager(InputManager const&) {};
    void operator=(InputManager const&) {};

private:
    static InputManager* instance;
    const uint8_t* keyboard;
    uint32_t mouse;
    int mouseX;
    int mouseY;
    bool keyDown[KEYBOARD_SIZE];
    bool keyUp[KEYBOARD_SIZE];
    bool mouseDown[MOUSE_MAX];
    bool mouseUp[MOUSE_MAX];
    bool will_quit;
    int curPrintableKey;
    bool isLocked;
};


#endif //INPUTMANAGER_HPP
