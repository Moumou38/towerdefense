#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>

#include "game/tower.h"

#include "sdl_tools.h"


void print_tower(tower* head, SDL_Surface* tour1, SDL_Surface* tour2, SDL_Surface* tour3, SDL_Surface* tour4, SDL_Surface* framebuffer, SDL_Surface* screen) {

	SDL_Rect position ; 
	tower* tmp = head ; 
	//print_info_tower(head) ;
		
	if(head->num != 0) { 
	//print_info_tower(tmp);
		while(tmp->num != 0) {
			position.x = (int)tmp->center.x-25 ; 
			position.y = (int)tmp->center.y-60 ; 
				if(tmp->type == gun) SDL_BlitSurface(tour1, NULL, framebuffer, &position);
				else if (tmp->type == rocket) SDL_BlitSurface(tour2, NULL, framebuffer, &position);
				else if (tmp->type == laser) SDL_BlitSurface(tour3, NULL, framebuffer, &position);
				else SDL_BlitSurface(tour4, NULL, framebuffer, &position); 
			tmp = tmp -> previous ;
		}
	
	}
	
	
}



void info_tower(tower* selected, SDL_Surface* tour, SDL_Surface* framebuffer) {
	SDL_Surface* text ; 
	SDL_Rect position ;
	SDL_Color Black = {0, 0, 0};
    SDL_Color Red = {255, 0, 0};   	
   TTF_Font *police = NULL;
   police = TTF_OpenFont("images/Triforce.ttf", 20); 
   char tmp[10] ;
	
	
	position.x = 850 ; 
	position.y = 200 ; 
	
	if(selected == NULL) { 
		SDL_BlitSurface(tour, NULL, framebuffer, &position);
		position.x = position.x - 35 ;
		position.y = position.y + 95 ; 
		text = TTF_RenderText_Blended(police, "Type : XXXX ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		position.x = position.x ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Power : XXXX ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		position.x = position.x ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Rate : XXXX ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		position.x = position.x ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Range : XXXX ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		
	}
	
	else {
	
		SDL_BlitSurface(tour, NULL, framebuffer, &position);
		position.x = position.x - 35 ;
		position.y = position.y + 95 ; 
		
		text = TTF_RenderText_Blended(police, "Type : ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		
		position.x = position.x + 70;
		position.y = position.y ;
		if(selected->type == 1 ) {
			text = TTF_RenderText_Blended(police, "Gun", Red);
			SDL_BlitSurface(text, NULL, framebuffer, &position);
		}
		else if(selected->type == 2 ) {
			text = TTF_RenderText_Blended(police, "Rocket", Red);
			SDL_BlitSurface(text, NULL, framebuffer, &position);
		}
		else if(selected->type == 3 ) {
			text = TTF_RenderText_Blended(police, "Laser", Red);
			SDL_BlitSurface(text, NULL, framebuffer, &position);
		}
		else if(selected->type == 4 ) {
			text = TTF_RenderText_Blended(police, "Hybrid", Red);
			SDL_BlitSurface(text, NULL, framebuffer, &position);
		}
		
		
		
		position.x = position.x - 70 ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Power : ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		
		position.x = position.x + 80;
		position.y = position.y ;
		sprintf(tmp,"%d",selected->power);
		text = TTF_RenderText_Blended(police, tmp, Red);
		SDL_BlitSurface(text, NULL, framebuffer, &position);		
		
		position.x = position.x - 80 ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Rate : ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
		
		position.x = position.x + 80;
		position.y = position.y ;
		sprintf(tmp,"%d",selected->rate);
		text = TTF_RenderText_Blended(police, tmp, Red);
		SDL_BlitSurface(text, NULL, framebuffer, &position);	
		
		position.x = position.x - 80 ;
		position.y = position.y + 30 ; 
		text = TTF_RenderText_Blended(police, "Range : ", Black);
		SDL_BlitSurface(text, NULL, framebuffer, &position);
	
	
		position.x = position.x + 80;
		position.y = position.y ;
		sprintf(tmp,"%d",selected->range);
		text = TTF_RenderText_Blended(police, tmp, Red);
		SDL_BlitSurface(text, NULL, framebuffer, &position);	
	
	
	}
	
	    SDL_FreeSurface(text);
	    TTF_CloseFont(police);
	 
}




int buildable(point X, Map* M) {
		
	
	if(X.x+15 > M->image->width || X.y+15 >  M->image->height ) {
		return 0;
	}
	else {
		if(M->image->tabPixel[M->image->width*(X.y)*3+(X.x)*3] == M->buildable.r &&
				M->image->tabPixel[M->image->width*(X.y)*3+(X.x)*3+1] == M->buildable.g &&
				M->image->tabPixel[M->image->width*(X.y)*3+(X.x)*3+2] == M->buildable.b) return 1 ;
				else return 0;
		
	}
	
}


void build (tower* head, point x, Map* M, int type, player* Player) {
	
	
	tower* t = (tower*)malloc(1*sizeof(tower));
	int i ; 
	
	t->level = 0;
	
	if(M->version == 1) { 
			
		switch(type) { 
			case 1 : 
				t->type = gun ; 
				t->range = 80 ; 
				t->cost = 50 ;
				t->power = 20 ; 
				t-> rate = 5 ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
		
			break;
			case 2 : 
				t->type = rocket ;
				t->range = 90 ; 
				t->cost = 100 ;
				t->power = 55 ; 
				t-> rate = 15 ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
			
			break;
			case 3 : 
				t->type = laser ;
				t->range = 70 ; 
				t->cost = 150 ;
				t->power = 20 ; 
				t-> rate = 3 ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ;   
		
			break; 
			case 4 : 
				t->type = hybrid ;
				t->range = 140 ; 
				t->cost = 200 ;
				t->power = 18 ; 
				t-> rate = 7 ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
		
			break ; 
		
		}
	}
	else { 
		switch(type) { 
			case 1 : 
				t->type = gun ; 
				t->range = M->rangeM ; 
				t->cost = M->costM ;
				t->power = M->powerM ; 
				t-> rate = M->rateM ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
		
			break;
			case 2 : 
				t->type = rocket ;
				t->range = M->rangeR ; 
				t->cost = M->costR ;
				t->power = M->powerR ; 
				t-> rate = M->rateR ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
			
			break;
			case 3 : 
				t->type = laser ;
				t->range = M->rangeL ; 
				t->cost = M->costL ;
				t->power = M->powerL ; 
				t-> rate = M->rateL ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ;  
		
			break; 
			case 4 : 
				t->type = hybrid ;
				t->range = M->rangeH ; 
				t->cost = M->costH ;
				t->power = M->powerH ; 
				t-> rate = M->rateH ;
				for(i=0 ; i<10;i++) t->timer[i] = 0 ; 
		
			break ; 
		
		}
		
	
	}
	if(t->cost > Player->money) {
		printf("C'est la ruine ! \n");
		free(t);
	}
	else { 

	Player->money -= t->cost;
	t->center = x ;

	t->num = head->num+1;

	t->next = head->next;

	t->previous = head;			

	
	if(head->next != NULL){
		head->next->previous = t;			
	}
	

	head->next = t;
}
//printf("success \n");

}


tower* next(tower* head) { 
	
	if (head->next == NULL ) {
		//printf("impossible d'aller plus loin \n");
		return head ; 
	}
	else { 
		
		return head->next  ; 
	}
}

tower* previous(tower* head) { 
	
	if (head->previous == NULL ) {
		//printf("impossible d'aller plus loin \n");
		return head ; 
	}
	else { 

		return head->previous ; 
	}
}

void print_info_tower(tower* head) { 

		printf("tour n° %d , coordonnee (%d , %d ) \n \n ", head->num, head->center.x, head->center.y );
		 
}


int can_attack(tower* head, Monster* M){

	float norme = (float)(sqrt((head->center.x-M->position.x)*(head->center.x-M->position.x) + (head->center.y-M->position.y)*(head->center.y-M->position.y)));
	
	if(norme > head->range) return 0 ;//le monstre est trop loin
	else return 1 ; //attaque possible

}

void can_attack_list(tower* head, Monster* M, player* Player) { 

	tower* tmp = head ; 
	int att ;
	if(M == NULL) printf("pas de monstres \n");
	else {
	

		
		if(tmp->num != 0) { 
	
			while(tmp->num != 0) {
				att = can_attack(tmp,M);
				if(att == 1) { 
					 if(tmp->timer[M->num] == tmp->rate) {
						//printf("tour n° %d = ", tmp->num);
						attack(head,M, Player);
						tmp->timer[M->num] = 0 ;
					}	
					else {
						tmp->timer[M->num] ++ ;
						
					}
								
				} 
				tmp = tmp -> previous ;
			}
	
		}
		
	}

}



void attack(tower* head, Monster* M, player* Player) {	

	printf("pew pew pew \n");
	Player->score += 5 ;
	if(M->PV > 0) { 

	    	switch(head->type){
				 case gun :
					M->PV -= head->power / M->def[0] ;					
				 break;

				  case rocket :
					M->PV -= head->power / M->def[1] ;
				 break;

				  case laser :
					M->PV -= head->power / M->def[2] ;
				 break;

				  case hybrid :
					M->PV -= head->power / M->def[3] ;
				 break;

			}
			Player->score += 2 ;
			if(M->PV <= 0) {
				Player->score += 5 ;
				Player->money += 10 ;							
				}		
		}
		
				
		
	}	
	
	


void select_tower_trace(point center, int range, SDL_Surface* framebuffer) {

int radius = range ;
double x, y;

x = center.x; 
y = center.y; 

	 int discriminant = (5 - (radius<<2))>>2 ;
    int i = 0, j = radius ;
     
    while (i<=j) {
    	
    
    	
        PutPixel(framebuffer, x+i,y-j,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x+j,y-i,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x+i,y+j,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x+j,y+i,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x-i,y-j,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x-j,y-i,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x-i,y+j,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        PutPixel(framebuffer, x-j,y+i,SDL_MapRGB(framebuffer->format, 255, 255, 255)) ;
        
       
        i++ ;
        if (discriminant<0) {                
            discriminant += (i<<1) + 1 ;
        } else {
            j-- ;
            discriminant += (1 + i - j)<<1 ;
        }
    

	}

}


tower* select_tower(tower* head, point X) {

	tower* tmp = head ; 
	int p = 0 ; 
	
	if(tmp->num != 0) { 
	
		while(tmp->num != 0 && p == 0) {
			p = is_tower(X, tmp->center) ;
			if(p==1)return tmp ; 
			//printf("Point center : %f  %f \n num %d \n range %d \n\n", tmp->center.x, tmp->center.y, tmp->num, tmp->range);
			//printf("p = %d \n", p);
			tmp = tmp -> previous ;
		}
	
	}
	
	//printf("num %d \n range %d \n\n", tmp->num, tmp->range);
	
return NULL ;

}


int is_tower(point X, point center) {
	
	//printf("Point X : %f  %f - Point center : %f  %f \n", X.x, X.y, center.x, center.y);
	
	if(X.x < center.x + 25 && X.x > center.x - 25 && X.y < center.y + 25 && X.y > center.y - 40) return 1;
	else return 0 ;  
}


tower* delete_tower(tower* selected, tower* head) {

	tower* tmp = head ;
		
	if(selected->previous->num == 0 && selected->next == NULL) { //s'il n'y a qu'une seule tour 
		//printf("début unique \n") ;
		head = head->previous ;
		head->next = NULL ; 
		tmp->previous = NULL;
		tmp->next = NULL ; 
		free(tmp) ;
		return head ;
		
	}
	else if(selected->previous->num == 0 && selected->next != NULL) { //tour en début de liste
		//printf("début \n") ;
		while(tmp->num != selected->num) {
			tmp=tmp->previous ; 
		}
		selected = selected->previous ;
		selected->next = tmp->next ; 
		tmp->next->previous = selected ; 
		tmp->previous = NULL;
		tmp->next = NULL ; 
		free(tmp) ;
		return head ;
		
	}
	else if(selected->previous->num != 0 && selected->next != NULL)  { //tour milieu de liste
		//printf("milieu \n") ;
		while(tmp->num != selected->num) {
			tmp=tmp->previous ; 
		}
	
		//print_info_tower(tmp);
		selected = tmp->previous ;  
		selected->next = tmp->next ;
		if(tmp->next != NULL){
			tmp->next->previous = selected ;
		}

		tmp->next = NULL;
		tmp->previous = NULL;
		
		
		return head ;
			
	}
	else { //tour en bout de liste
		//printf("fin \n") ;
		head = head->previous ;
		head->next = NULL ; 
		tmp->previous = NULL;
		tmp->next = NULL ; 
		free(tmp) ;
		return head ;
			
	}


}

tower* clean_tower_list(tower* head) {

	tower* tmp = head ; 
	//print_info_tower(head) ;
		
	if(head->num != 0) { 
	//print_info_tower(tmp);
		while(tmp->num != 0) {
			head = delete_tower(tmp, head);
			tmp = head ;
			
		}
	}	
return head ;

}

void tower_cost(Map* M, SDL_Surface* framebuffer) { 

int cost[4] ; 
char tmp[4] ; 
int i ; 

SDL_Surface* text, *text2 ; 
SDL_Rect position ;
SDL_Color Black = {0, 0, 0};   
SDL_Color Red = {255, 0, 0};   		
TTF_Font *police = NULL;
police = TTF_OpenFont("images/Triforce.ttf", 15); 



position.x = 60 ; 
position.y = 610+40 ; 
	

if(M->version == 1) { 
	cost[0] = 50 ; 
	cost[1] = 100 ; 
	cost[2] = 150 ; 
	cost[3] = 200 ; 			
		
	}
else { 
	
	cost[0] = M->costM ; 
	cost[1] = M->costR ; 
	cost[2] = M->costL ; 
	cost[3] = M->costH ; 

}

for(i=0;i<4;i++) {


sprintf(tmp,"%d",cost[i]);
text = TTF_RenderText_Blended(police, tmp , Black); 
text2 = TTF_RenderText_Blended(police, "$" , Red); 
SDL_BlitSurface(text, NULL, framebuffer, &position);

position.x += 30 ; 
SDL_BlitSurface(text2, NULL, framebuffer, &position);
position.x += 55 ; 

}
	
	    SDL_FreeSurface(text);
	    SDL_FreeSurface(text2);
	    TTF_CloseFont(police);


}


void upgrade_tower(tower* selected, player* Player){

	Player->money -= 30 ; 

	selected->level ++;

	switch(selected->type){
			 case gun :
			 	selected->power += 5;
			   selected->range += 8 ;
			   selected->cost += 30 ;
			   if(selected->rate != 1) selected->rate -= 1 ; 
			 					
			 break;

			  case rocket :
			  	selected->power += 10;
			   selected->range += 5 ;
			   selected->cost += 30 ;
			   if(selected->rate != 1) selected->rate -= 1 ;
			  
			 break;

			  case laser :
			  	selected->power += 5;
			   selected->range += 5 ;
			   selected->cost += 30 ;
			   if(selected->rate != 1) selected->rate -= 1 ;
			  
			 break;

			  case hybrid :
			  	selected->power += 3;
			   selected->range += 10 ;
			   selected->cost += 30 ;
			   if(selected->rate != 1) selected->rate -= 1 ;
			  
			 break;

			}



}


