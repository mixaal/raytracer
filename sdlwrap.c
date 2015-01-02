#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "sdlwrap.h"

SDL_Surface *screen  = NULL;
static SDL_PixelFormat *fmt = NULL;

#define CLAMP(x,t) (((x)>(t))?(t):(x))
#define CLAMP_SCALE(x,s) (s)*CLAMP(x,1.0f)

static void sdl_quit(void)
{
  if(screen) 
    SDL_FreeSurface(screen);
  SDL_Quit();
}


void sdl_init(void)
{
  if( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    fprintf(stderr, "Couldn’t initialize SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);  
  }

  atexit(sdl_quit);
}

void sdl_flip(u_int32_t *addr, int w, int h)
{
#if 1
    if(SDL_MUSTLOCK(screen)) {
       if(SDL_LockSurface(screen) < 0) {
         fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
         exit(EXIT_FAILURE);
       }
    }
  
    memcpy(screen->pixels, addr, w*h*4); 
   
    if(SDL_MUSTLOCK(screen)) {
      SDL_UnlockSurface(screen);
    }
#endif  
    SDL_Flip(screen);

}

void sdl_video_mode(int w, int h)
{
  screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE|SDL_ASYNCBLIT|SDL_HWPALETTE|SDL_DOUBLEBUF);
  if(screen==NULL) {
    fprintf(stderr, "Can't set: %dx%d mode: %s\n", w, h, SDL_GetError()); 
    exit(EXIT_FAILURE);  
  }
  fmt = screen->format;
}

