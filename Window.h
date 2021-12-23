#pragma once

//stdio and SDL
#include <stdio.h>
#include "SDL.h"

class Window
{

	//public access functions
public:
	//create and destroy
	Window();
	~Window();

	//initialize
	void init(const char* title, int x, int y, int w, int h, bool Vulkan, bool Fullscreen, bool borderlessWindow, bool VSync, bool HWAccel);

	//events, update window, draw window, clean garbage
	void handleEvents();
	void update();
	void render();
	void clean();

	//confirm the window is going
	bool isRunning();

	//things that are just our little secrets... the kind that could ruin us.
private:
	//we're running!
	bool running;

	//a county boi
	int counter;

	//window and renderer
	SDL_Window* window;
	SDL_Renderer* renderer;
};