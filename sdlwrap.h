#ifndef __SDL_WRAP_H__
#define __SDL_WRAP_H__ 1


#include "types.h"

void sdl_init(void);
void sdl_flip(u_int32_t *addr, int w, int h);
void sdl_video_mode(int w, int h);

#endif /* __SDL_WRAP_H__ */
