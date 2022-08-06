#ifndef PIXEL_OPERATRION_H
#define PIXEL_OPERATRION_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

void init_sdl();

SDL_Surface* load_image(char *path);

Uint32 get_pixel(SDL_Surface *surface, unsigned x, unsigned y);

void put_pixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel);

#endif /* ! PIXEL_OPERATRION_H */
