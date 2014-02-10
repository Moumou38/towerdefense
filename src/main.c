#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "sdl_tools.h"
#include "choice.h"
#include "play.h"


static unsigned int WINDOW_WIDTH = 1010;
static unsigned int WINDOW_HEIGHT = 700;
static const unsigned int BIT_PER_PIXEL = 32;

int xClicked = 0, yClicked=0, xMotion = 0, yMotion=0;


int main(int argc, char** argv) {

    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    SDL_Surface* screen = NULL, *text = NULL, *text_menu1 = NULL, *text_menu2 = NULL, *text_menu3 = NULL, *text_menu1c = NULL, *text_menu2c = NULL, *text_menu3c = NULL ;
    
    if(NULL == (screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, 
        SDL_DOUBLEBUF))) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    
    SDL_WM_SetCaption("Le plus Bô Tower Defense du monde", NULL);
    
    /* Création d'une surface SDL */
    SDL_Surface* framebuffer = NULL ;
    SDL_Color White = {255, 255, 255};
    SDL_Color Yellow = {255, 255, 0};
    TTF_Font *police_title = NULL, *police_menu = NULL;
    TTF_Init();
    police_title = TTF_OpenFont("images/Triforce.ttf", 36);
    police_menu = TTF_OpenFont("images/Triforce.ttf", 26);
    text = TTF_RenderText_Blended(police_title, "Ze Legend of IMAC - Les deux Tours", White);
    text_menu1 = TTF_RenderText_Blended(police_menu, "Jouer", White);
    text_menu1c = TTF_RenderText_Blended(police_menu, "Jouer", Yellow);
    text_menu2 = TTF_RenderText_Blended(police_menu, "Aide", White);
    text_menu2c = TTF_RenderText_Blended(police_menu, "Aide", Yellow);
    text_menu3 = TTF_RenderText_Blended(police_menu, "Quitter", White);
    text_menu3c = TTF_RenderText_Blended(police_menu, "Quitter", Yellow);
    
    
    SDL_Rect position_title; 
    SDL_Rect position_menu1;
    SDL_Rect position_menu2;
    SDL_Rect position_menu3; 
    position_title.x = WINDOW_WIDTH/3.9 ;
    position_title.y = WINDOW_HEIGHT/4 ; 
    position_menu1.x = WINDOW_WIDTH/2.25 ;
    position_menu1.y = WINDOW_HEIGHT/2.8 ;
    position_menu2.x = position_menu1.x ;
    position_menu2.y = position_menu1.y + 50 ; 
    position_menu3.x = position_menu2.x ;
    position_menu3.y = position_menu2.y + 50 ;
    int hover = 0 ;
    int game ;


    
    if(NULL == (framebuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, WINDOW_WIDTH, 
        WINDOW_HEIGHT, BIT_PER_PIXEL, 0, 0, 0, 0))) {
        fprintf(stderr, "Erreur d'allocation pour le framebuffer. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    int loop = 1;
    
    
    

    
    while(loop) {
        /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 50));

        
        /* Placer ici le code de dessin */
       	SDL_BlitSurface(text, NULL, framebuffer, &position_title);
       	if(hover == 0) {
       	SDL_BlitSurface(text_menu1, NULL, framebuffer, &position_menu1);
       	SDL_BlitSurface(text_menu2, NULL, framebuffer, &position_menu2);
       	SDL_BlitSurface(text_menu3, NULL, framebuffer, &position_menu3);
       	}
       	else { 
       		if(xMotion > position_menu1.x && xMotion < position_menu1.x + 150 && yMotion > position_menu1.y && yMotion < position_menu1.y + 40) {
		    		SDL_BlitSurface(text_menu1c, NULL, framebuffer, &position_menu1);
		    		SDL_BlitSurface(text_menu3, NULL, framebuffer, &position_menu3);
		    		SDL_BlitSurface(text_menu2, NULL, framebuffer, &position_menu2);
       		}      
				else if(xMotion > position_menu2.x && xMotion < position_menu2.x + 150 && yMotion > position_menu2.y && yMotion < position_menu2.y + 40) {
       		SDL_BlitSurface(text_menu2c, NULL, framebuffer, &position_menu2);
       		SDL_BlitSurface(text_menu1, NULL, framebuffer, &position_menu1);
       		SDL_BlitSurface(text_menu3, NULL, framebuffer, &position_menu3);
       		
       		}
       		
       		else if(xMotion > position_menu3.x && xMotion < position_menu3.x + 150 && yMotion > position_menu3.y && yMotion < position_menu3.y + 40) {
       		SDL_BlitSurface(text_menu1, NULL, framebuffer, &position_menu1);
       		SDL_BlitSurface(text_menu2, NULL, framebuffer, &position_menu2);
       		SDL_BlitSurface(text_menu3c, NULL, framebuffer, &position_menu3);
       		
       		}
       		else {
       			SDL_BlitSurface(text_menu1, NULL, framebuffer, &position_menu1);
       			SDL_BlitSurface(text_menu2, NULL, framebuffer, &position_menu2);
       			SDL_BlitSurface(text_menu3, NULL, framebuffer, &position_menu3);
       		
       		
       		
       		}
       		
       		
			}
			
        /* On copie le framebuffer à l'écran */
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        SDL_Flip(screen);
    
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
            loop = 0;
				}
		switch(e.type) {
            
	      case SDL_MOUSEBUTTONUP:
		  xClicked = e.button.x;
		  yClicked = e.button.y;
		  
		  //printf("%d  %d  \n", xClicked, yClicked);
		  
		  if(xClicked > position_menu1.x && xClicked < position_menu1.x + 150 && yClicked > position_menu1.y && yClicked < position_menu1.y + 40) game = choice(framebuffer, screen);
		  else if(xMotion > position_menu2.x && xMotion < position_menu2.x + 150 && yMotion > position_menu2.y && yMotion < position_menu2.y + 40) {
		  	game = help(framebuffer, screen);
		  }
		  else if (xClicked > position_menu3.x && xClicked < position_menu3.x + 150 && yClicked > position_menu3.y && yClicked < position_menu3.y + 40) loop = 0 ;
    		
	  			break;
	  			
	  			
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym){
						case SDLK_ESCAPE : 
							loop = 0;
						break;
						
						default : break;
					}
				break; 
				
				
				 case SDL_MOUSEMOTION: 
				
				  xMotion = e.motion.x;
	 			  yMotion = e.motion.y;
					
				  if(xMotion > position_menu1.x && xMotion < position_menu1.x + 150 && yMotion > position_menu1.y && yMotion < position_menu3.y + 40 ) hover = 1;
				  else hover = 0 ; 
        
       		 break;	
	  				
	  		}		
            
            
        }
  }
    
    SDL_FreeSurface(framebuffer);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(text);
    SDL_FreeSurface(text_menu1);
    SDL_FreeSurface(text_menu2);
    SDL_FreeSurface(text_menu3);
    SDL_FreeSurface(text_menu1c);
    SDL_FreeSurface(text_menu2c);
    SDL_FreeSurface(text_menu3c);
    TTF_CloseFont(police_title);
  	TTF_CloseFont(police_menu);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
