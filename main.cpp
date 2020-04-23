// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[])
{

  bool quit = false;
  SDL_Event event;
  int dx = 1, dy = 1; 

  // init SDL
 
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window * window = SDL_CreateWindow("SDL2 line drawing",
					 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
 
  // handle events
 
  while (!quit)
    {
      SDL_Delay(10);
      SDL_PollEvent(&event);
 
      switch (event.type)
        {
	case SDL_KEYDOWN:
	  if(event.key.keysym.sym == SDLK_ESCAPE){
	    quit = true;
	    break;
	  } else {
	    dx++;
	    dy++;
	  }
	  // TODO input handling code goes here
        }
 
      // clear window
 
      SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
      SDL_RenderClear(renderer);
 
      // TODO rendering code goes here
      SDL_SetRenderDrawColor(renderer, 0, 240, 0, 255);
      SDL_RenderDrawLine(renderer, 10+dx, 10+dy, 100, 150);

	
      // render window
 
      SDL_RenderPresent(renderer);
    }
 
  // cleanup SDL
 
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
 
  return 0;
}
