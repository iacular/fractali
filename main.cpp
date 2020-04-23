// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define PI 3.14156592


using namespace std;


SDL_Renderer * renderer; 

int tree(float x0, float y0, float alpha, float d){

float x1, y1; 

x1 = x0 + d*cos(alpha); 
y1 = y0 + d*sin(alpha);  
cout << x1 << " " << y1 << endl;
SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
if(d > 4 && x1 > 0 && y1 > 0 && x1 < SCREEN_WIDTH && y1 < SCREEN_HEIGHT){ 
	tree(x1, y1, alpha + PI/16, d*0.6); 
	tree(x1, y1, alpha - PI/5, d*0.8); 
}
}

void fulgu(float x0, float y0, float alpha, float d){

	if(d < 14){ 
		SDL_RenderDrawLine(renderer, x0, y0, x0 + d*cos(alpha), y0 + d*sin(alpha));
		return;
	}
	fulgu(x0, y0, alpha, d/3);
	fulgu(x0 + d*cos(alpha)/3, y0 + d*sin(alpha)/3, alpha + PI/3, d/3);
	fulgu(x0 + d*cos(alpha)/3 + d*cos(alpha +PI/3)/3, y0 + d*sin(alpha)/3 + d*sin(alpha+PI/3)/3, - PI/3 + alpha, d/3); 
	fulgu(x0 + 2*d*cos(alpha)/3, y0 + 2*d*sin(alpha)/3, alpha, d/3);


}


int main(int argc, char* args[])
{

  bool quit = false;
  SDL_Event event;
  int dx = 1, dy = 1; 

  // init SDL
 
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window * window = SDL_CreateWindow("SDL2 line drawing",
					 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
 
  // handle events
 
  while (!quit){
      SDL_Delay(10);
      SDL_PollEvent(&event);
 
      switch (event.type){
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

      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      
      //tree(10, 10, PI/3, 150); 
      fulgu(1,1, 0, 600);
	
      // render window
 
      SDL_RenderPresent(renderer);
      cout << dx << " " << dy << endl; 
    }
 
  // cleanup SDL
 
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
 
  return 0;
}
