#include "sdl_tools.h"

void PutPixel(SDL_Surface* surface, int x, int y, Uint32 pixel) {
    int bpp = surface->format->BytesPerPixel;
    
    if(y < 0 || x < 0 || y > 500 || x > 750 ) {}
    else {
    
    Uint8* p = (Uint8*) surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16*)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32*)p = pixel;
        break;
    }
    
    }
}



void Line(SDL_Surface* framebuffer,int x1,int y1, int x2,int y2)  // Bresenham
{
  int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;
  
  PutPixel(framebuffer, x1,y1,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
  
  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  if(x1<x2)
    xincr = 1;
  else
    xincr = -1;
  if(y1<y2)
    yincr = 1;
  else
    yincr = -1;

  x = x1;
  y = y1;
  if(Dx>Dy)
    {
      erreur = Dx/2;
      for(i=0;i<Dx;i++)
        {
          x += xincr;
          erreur += Dy;
          if(erreur>Dx)
            {
              erreur -= Dx;
              y += yincr;
            }
        PutPixel(framebuffer, x,y,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        }
    }
  else
    {
      erreur = Dy/2;
      for(i=0;i<Dy;i++)
        {
          y += yincr;
          erreur += Dx;
          if(erreur>Dy)
            {
              erreur -= Dy;
              x += xincr;
            }
        PutPixel(framebuffer, x,y,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        }
    }
}

