//SDL Usage Testing By Ashe A. Astra. This file is not for general use, and should not be copied, altered, or reused except with written permission.

// need sdl to do sdl
#include "SDL.h"

//stdio for general console use
#include <stdio.h>

//window class file
#include "Window.h"

//establish a window
Window* window = nullptr;

// hacky C back-compat argument passing becuase we just HAD to have arguments for MAIN... buncha dorks
int main(int argc, char* argv[])
{
	//get relevant values. currently mostly set temps, will be stored in an options file later
	bool Vulkan = false;
	bool Fullscreen = false;
	bool borderlessWindow = false;
	bool VSync = true;
	bool HWAccel = true;

	//create the window and initialize. 
	window = new Window();
	window->init("test engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, Vulkan, Fullscreen, borderlessWindow, VSync, HWAccel);


	//while loop
	while (window->isRunning())
	{
		window->handleEvents();
		window->update();
		window->render();
	}

	//exit
	window->clean();

	//bye bye beh beh
	return 0;
}












/*///////////////////////////////////////////// INITIAL TEST CODE, KEPT FOR POSTERITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*\
-------------------------------------------------------------------------------------------------------------------------------------

// hacky C back-compat argument passing becuase we just HAD to have arguments for MAIN... buncha dorks
int main(int argc, char* argv[])
{

	// Initialize everything because I'm lazy and modern PCs aren't exactly low on space/power for it
	SDL_Init(SDL_INIT_EVERYTHING);



	// make a window and create the window seperately. Because we're not barbarians, y'all. We can seperate ATOMS we can seperate our declarations.
	SDL_Window* window;
	
	window = SDL_CreateWindow("Testing Stuff", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN);

	// error catching. SDL_GetError pushes the last error given as a string, so IF window is still null then there must be an error, so grab it
	if (window == NULL)
		printf("Window Failed, Error: %s", SDL_GetError() );



	// same with renderer
	SDL_Renderer* renderer;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	// error catching again
	if (renderer == NULL)
		printf("Renderer Failed, Error: %s", SDL_GetError());



	// give that renderer some colors. renderers love colors. just a low level grey with full alpha
	SDL_SetRenderDrawColor(renderer, 0x35, 0x35, 0x35, 0xFF);



	// clear the screen. As I understand it, this is good practice but not actually necessary here
	SDL_RenderClear(renderer);

	// draw that shiz
	SDL_RenderPresent(renderer);



	// and becuase I'm a dumb ho we stop and wait here for a few seconds to admire our colored box
	SDL_Delay(3000);



	// cleanup
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// quit
	SDL_Quit();


	//exit
	return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------
\*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______________________________________/////////////////////////////////////////////*/