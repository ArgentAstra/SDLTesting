#include "Window.h"


Window::Window()
{
	//generic counter is 0
	counter = 0;
}

Window::~Window()
{
}

//initialize the window, because we care. And becuase nothing happens elsewise
void Window::init(const char* title, int x, int y, int w, int h, bool Vulkan, bool Fullscreen, bool borderlessWindow, bool VSync, bool HWAccel)
{
	//checking for various window options

	//initial value: shown isn't optional
	int wflags = SDL_WINDOW_SHOWN;
	
	//fullscreen and borderless aren't compatable, so if/else them
	if (Fullscreen)
		wflags = wflags | SDL_WINDOW_FULLSCREEN;
	else if (borderlessWindow)
		wflags = wflags | SDL_WINDOW_BORDERLESS;

	//same for vulkan, otherwise use openGL
	if (Vulkan)
		wflags = wflags | SDL_WINDOW_VULKAN;
	else
		wflags = wflags | SDL_WINDOW_OPENGL;




	//do the same with the Renderer options

	//initial value
	int rflags = 0;

	//HWaccel if/else
	if (HWAccel)
		rflags = SDL_RENDERER_ACCELERATED;
	else
		rflags = SDL_RENDERER_SOFTWARE;

	//VSYNC if/else
	if (VSync)
		rflags = rflags | SDL_RENDERER_PRESENTVSYNC;




	// Initialize everything because I'm lazy and modern PCs aren't exactly low on space/power for it. Confirms initialization and, if successful, establishes a window
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//failure. be sad and don't run
		printf("Init Failed, Error: %s\n", SDL_GetError());
		running = false;
	}
	else
	{
		//success! Do the thing! Using Running as a fail flag for ease of use
		printf("Init Succeeded\n");
		running = true;

		//make the window a real boy
		if (running)
			window = SDL_CreateWindow(title, x, y, w, h, wflags);

		// error catching. SDL_GetError pushes the last error given as a string, so IF window is still null then there must be an error, so grab it
		if (window == NULL)
		{
			printf("Window Failed, Error: %s\n", SDL_GetError());
			running = false;
		}

		//renderer creation
		if (running)
			renderer = SDL_CreateRenderer(window, -1, rflags);

		//error catching
		if (renderer == NULL)
		{
			printf("Renderer Failed, Error: %s\n", SDL_GetError());
			running = false;
		}



		//do some basics so she can be seen
		SDL_SetRenderDrawColor(renderer, 0x33, 0x33, 0x88, 0xFF);
	}
}

//the magic of stuff happening, managed by checking a million things
void Window::handleEvents()
{
	//take an event object
	SDL_Event event;

	//pass by reference to get the event
	SDL_PollEvent(&event);

	//event type switch. currently just	QUIT
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}

//update engine states
void Window::update()
{
	//counter for confirming it works
	counter++;
	printf("%i\n", counter);
	//todo
}

//iterate on the renderer
void Window::render()
{
	//clear up our renderer then do stuff
	SDL_RenderClear(renderer);

	//eventually we'll have stuff here

	//actually do the thing
	SDL_RenderPresent(renderer);


}

//clean up our mess and quit
void Window::clean()
{
	// cleanup
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// quit
	SDL_Quit();

	//little message
	printf("All cleaned up!");
}


//just return if we're running. used to manage when to clean up and ship out
bool Window::isRunning()
{
	return running;
}
