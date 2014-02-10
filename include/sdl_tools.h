#ifndef SDL_TOOLS_H_
#define SDL_TOOLS_H_

#include <SDL/SDL.h>

void PutPixel(SDL_Surface* surface, int x, int y, Uint32 pixel);
/* Dessiner un pixel de coordonnées x, y et de couleur pixel */

void Line(SDL_Surface* framebuffer,int x1,int y1, int x2,int y2) ;

#endif
