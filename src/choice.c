#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "sdl_tools.h"
#include "game/map.h"
#include "game/tower.h"
#include "play.h"


static unsigned int WINDOW_WIDTH = 1000;
static unsigned int WINDOW_HEIGHT = 670;
static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


int choice(SDL_Surface* framebuffer, SDL_Surface* screen) {

	
    /* Création d'une surface SDL */
    SDL_Surface* itd1 = NULL, *itd2 = NULL, *itd1c = NULL, *itd2c = NULL, *map = NULL, *map1 = NULL, *map2 = NULL, *map3 = NULL, *map4 = NULL, *choix_map = NULL, *choix_jeu = NULL ;
    SDL_Rect position_itd1, position_itd2, position_map , position_map1 , position_map2 , position_map3, position_map4, position_choix; 
    position_itd1.x = WINDOW_WIDTH  / 2 ;
    position_itd1.y = WINDOW_HEIGHT / 2 ; 
    
    position_map.x = WINDOW_WIDTH  / 2.2 ;
    position_map.y = 20 ;
    
    position_map1.x = 100 ;
    position_map1.y = 60 ;
    
    position_map2.x = WINDOW_WIDTH - 400 ;
    position_map2.y = 60 ;
    
    position_map3.x = 100 ;
    position_map3.y = 320 ;
    
    position_map4.x = WINDOW_WIDTH - 400 ;
    position_map4.y = 320 ;
    
    position_choix.x = 100 ; 
    position_choix.y = WINDOW_HEIGHT - 80 ;
    
    position_itd1.x = position_choix.x + 300 ; 
    position_itd1.y = position_choix.y ; 
    
    position_itd2.x = position_itd1.x + 200 ; 
    position_itd2.y = position_choix.y ;
    
    
    map1 = IMG_Load("./images/mini/map1_m.jpg");
    map2 = IMG_Load("./images/mini/map2_m.jpg");
    map3 = IMG_Load("./images/mini/map3_m.jpg");
    map4 = IMG_Load("./images/mini/map4_m.jpg");
    

    SDL_Color White = {255, 255, 255};
    SDL_Color Yellow = {255, 255, 0};   
    TTF_Font *police1 = NULL, *police2 = NULL;
    TTF_Init();
    police1 = TTF_OpenFont("images/Triforce.ttf", 40); 
    police2 = TTF_OpenFont("images/Triforce.ttf", 20); 
    map = TTF_RenderText_Blended(police1, "Cartes", White);
    choix_map = TTF_RenderText_Blended(police2, "Veuillez selectionner une carte", White);
    choix_jeu = TTF_RenderText_Blended(police2, "Choisissez votre type de jeu : ", White); 
    itd1 = TTF_RenderText_Blended(police2, "Type 1 ", White);
    itd2 = TTF_RenderText_Blended(police2, "Type 2 ", White);
    itd1c = TTF_RenderText_Blended(police2, "Type 1 ", Yellow);
    itd2c = TTF_RenderText_Blended(police2, "Type 2 ", Yellow);                           
    int loop = 1;
    int xClicked = 0, yClicked=0, xMotion = 0, yMotion=0;
    int selection = 0 ; 
    int choix = 0 ;
    int hover = 0 ; 
  
 

    
    

    
    while(loop) {
    
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
						
						if(selection == 0) {
						
							if(xClicked > 100 && xClicked < 400 && yClicked > 60 && yClicked < 260) {
								selection = 1 ; 
								choix = 1 ;
						
							}
							else if(xClicked > 600 && xClicked < 900 && yClicked > 60 && yClicked < 260) {
								selection = 1 ; 
								choix = 2 ;
						
							}
							else if(xClicked > 100 && xClicked < 400 && yClicked > 320 && yClicked < 520) {
								selection = 1 ; 
								choix = 3 ;
						
							}
							else if(xClicked > 600 && xClicked < 900 && yClicked > 320 && yClicked < 620) {
								selection = 1 ; 
								choix = 4 ;
						
							}
							else {
								selection = 0 ;
								choix = 0 ;
						
							}
						
						}
						else {
							if(xClicked > position_itd1.x && xClicked < position_itd1.x + 50 && yClicked > position_itd1.y && yClicked < position_itd1.y + 50) {
							
							switch(choix) { 
								case 1 : 
									loop = play_game(framebuffer, screen, "data/map1.itd", "images/map1.jpg" );
		
								break;
								case 2 : 
									loop = play_game(framebuffer, screen, "data/map2.itd", "images/map2.jpg");
			
								break;
								case 3 : 
									loop = play_game(framebuffer, screen, "data/map3.itd", "images/map3.jpg");
		
								break; 
								case 4 : 
									loop = play_game(framebuffer, screen, "data/map4.itd", "images/map4.jpg");
		
								break ; 
		
							}
						
							
					
					}
					else if (xClicked > position_itd2.x && xClicked < position_itd2.x + 50 && yClicked > position_itd2.y && yClicked < position_itd2.y + 50)  {	
					
						switch(choix) { 
								case 1 : 
									loop = play_game(framebuffer, screen, "data/map1type2.itd", "images/map1.jpg" );
		
								break;
								case 2 : 
									loop = play_game(framebuffer, screen, "data/map2type2.itd", "images/map2.jpg");
			
								break;
								case 3 : 
									loop = play_game(framebuffer, screen, "data/map3type2.itd", "images/map3.jpg");
		
								break; 
								case 4 : 
									loop = play_game(framebuffer, screen, "data/map4type2.itd", "images/map4.jpg");
		
								break ; 
		
							}
						
					
					
				}
				else {
					selection = 0 ;
					choix = 0 ; 	
				
				
				
				}					
						
						
						}
						
						
					
					break;
					
					case SDL_MOUSEMOTION: 
				
				  xMotion = e.motion.x;
	 			  yMotion = e.motion.y;
					
				  if(xMotion > position_itd1.x && xMotion < position_itd2.x + 100 && yMotion > position_itd1.y && yMotion < position_itd1.y + 40 ) hover = 1;
				  else hover = 0 ; 
        
       		 break;	
					
					
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym){
						case SDLK_ESCAPE : 
							loop = 0;
						break;
		 
							
						default : break;
					}
				break; 	

				}		


			}
			
			  /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));

        
        /* Placer ici le code de dessin */
       	SDL_BlitSurface(map, NULL, framebuffer, &position_map);   
       	SDL_BlitSurface(map1, NULL, framebuffer, &position_map1);
       	SDL_BlitSurface(map2, NULL, framebuffer, &position_map2);     
			SDL_BlitSurface(map3, NULL, framebuffer, &position_map3);
			SDL_BlitSurface(map4, NULL, framebuffer, &position_map4);
			
			
			if(selection == 0) { 
			
				SDL_BlitSurface(choix_map, NULL, framebuffer, &position_choix);
						
			}
			else {
				
				SDL_BlitSurface(choix_jeu, NULL, framebuffer, &position_choix);
				
				if(hover == 0) { 
					SDL_BlitSurface(itd1, NULL, framebuffer, &position_itd1);
					SDL_BlitSurface(itd2, NULL, framebuffer, &position_itd2);			
				}
				
				else {
					if(xMotion > position_itd1.x && xMotion < position_itd1.x + 50 && yMotion > position_itd1.y && yMotion < position_itd1.y + 50) {
					SDL_BlitSurface(itd1c, NULL, framebuffer, &position_itd1);
					SDL_BlitSurface(itd2, NULL, framebuffer, &position_itd2);
					}
					else if (xMotion > position_itd2.x && xMotion < position_itd2.x + 50 && yMotion > position_itd2.y && yMotion < position_itd2.y + 50)  {
					SDL_BlitSurface(itd1, NULL, framebuffer, &position_itd1);
					SDL_BlitSurface(itd2c, NULL, framebuffer, &position_itd2);
					
				}
				else {

					SDL_BlitSurface(itd1, NULL, framebuffer, &position_itd1);
					SDL_BlitSurface(itd2, NULL, framebuffer, &position_itd2);	
				
				
				
				}
				
				} 
						
			}
			
			
        /* On copie le framebuffer à l'écran */
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        SDL_Flip(screen);
    
        }
        
        
        
          SDL_FreeSurface(itd1); 
          SDL_FreeSurface(itd2) ;
          SDL_FreeSurface(itd1c);  
          SDL_FreeSurface(itd2c);  
          SDL_FreeSurface(map);  
          SDL_FreeSurface(map1); 
          SDL_FreeSurface(map2); 
          SDL_FreeSurface(map3); 
          SDL_FreeSurface(map4); 
          SDL_FreeSurface(choix_map); 
          SDL_FreeSurface(choix_jeu);
    
    
    return 0;
}
