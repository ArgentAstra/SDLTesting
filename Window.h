#pragma once

//stdio and SDL
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

//other includes
#include <string>

class Window
{

	//public access functions
public:
	//create and destroy
	Window();
	~Window();

	//initialize
	void init(const char* title, int x, int y, int w, int h, bool Vulkan, bool Fullscreen, bool borderlessWindow, bool VSync, bool HWAccel);

	//events, update window, get an image for a given surface, draw window, clean garbage
	void handleEvents();
	void update();

	//any other functions
	void loadImage(int target, std::string filename);

	void render();
	void clean();

	//confirm the window is going
	bool isRunning();

	//things that are just our little secrets... the kind that could ruin us.
private:
	//we're running!
	bool running = false;

	//a county boi
	int counter = 0;

	//window and renderer with bits
	SDL_Window* window;
	int WindowW;
	int WindowH;
	SDL_Renderer* renderer;

	//some texture stuff, will be more fancy later
	SDL_Texture* PlrTex = NULL;
	SDL_Rect sourceR;
	SDL_Rect DestR;
	

	//testing BS
	bool moveLeft = false;
	bool moveUp = false;
};