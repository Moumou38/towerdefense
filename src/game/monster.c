#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <time.h> 

#include "game/monster.h"
#include "sdl_tools.h"

void init_tab_monster(SDL_Surface** tab_sprite_monster){

	tab_sprite_monster[0] = IMG_Load("./images/monster/m0_N_100.png");
	tab_sprite_monster[1] = IMG_Load("./images/monster/m0_N_75.png");
	tab_sprite_monster[2] = IMG_Load("./images/monster/m0_N_50.png");
	tab_sprite_monster[3] = IMG_Load("./images/monster/m0_N_25.png");
	
	tab_sprite_monster[4] = IMG_Load("./images/monster/m0_E_100.png");
	tab_sprite_monster[5] = IMG_Load("./images/monster/m0_E_75.png");
	tab_sprite_monster[6] = IMG_Load("./images/monster/m0_E_50.png");
	tab_sprite_monster[7] = IMG_Load("./images/monster/m0_E_25.png");
	
	tab_sprite_monster[8] = IMG_Load("./images/monster/m0_S_100.png");
	tab_sprite_monster[9] = IMG_Load("./images/monster/m0_S_75.png");
	tab_sprite_monster[10] = IMG_Load("./images/monster/m0_S_50.png");
	tab_sprite_monster[11] = IMG_Load("./images/monster/m0_S_25.png");
	
	tab_sprite_monster[12] = IMG_Load("./images/monster/m0_W_100.png");
	tab_sprite_monster[13] = IMG_Load("./images/monster/m0_W_75.png");
	tab_sprite_monster[14] = IMG_Load("./images/monster/m0_W_50.png");
	tab_sprite_monster[15] = IMG_Load("./images/monster/m0_W_25.png");
	
	
	
	tab_sprite_monster[16] = IMG_Load("./images/monster/m1_N_100.png");
	tab_sprite_monster[17] = IMG_Load("./images/monster/m1_N_75.png");
	tab_sprite_monster[18] = IMG_Load("./images/monster/m1_N_50.png");
	tab_sprite_monster[19] = IMG_Load("./images/monster/m1_N_25.png");
	
	tab_sprite_monster[20] = IMG_Load("./images/monster/m1_E_100.png");
	tab_sprite_monster[21] = IMG_Load("./images/monster/m1_E_75.png");
	tab_sprite_monster[22] = IMG_Load("./images/monster/m1_E_50.png");
	tab_sprite_monster[23] = IMG_Load("./images/monster/m1_E_25.png");
	
	tab_sprite_monster[24] = IMG_Load("./images/monster/m1_S_100.png");
	tab_sprite_monster[25] = IMG_Load("./images/monster/m1_S_75.png");
	tab_sprite_monster[26] = IMG_Load("./images/monster/m1_S_50.png");
	tab_sprite_monster[27] = IMG_Load("./images/monster/m1_S_25.png");
	
	tab_sprite_monster[28] = IMG_Load("./images/monster/m1_W_100.png");
	tab_sprite_monster[29] = IMG_Load("./images/monster/m1_W_75.png");
	tab_sprite_monster[30] = IMG_Load("./images/monster/m1_W_50.png");
	tab_sprite_monster[31] = IMG_Load("./images/monster/m1_W_25.png");
	
	
	tab_sprite_monster[32] = IMG_Load("./images/monster/m2_N_100.png");
	tab_sprite_monster[33] = IMG_Load("./images/monster/m2_N_75.png");
	tab_sprite_monster[34] = IMG_Load("./images/monster/m2_N_50.png");
	tab_sprite_monster[35] = IMG_Load("./images/monster/m2_N_25.png");
	
	tab_sprite_monster[36] = IMG_Load("./images/monster/m2_E_100.png");
	tab_sprite_monster[37] = IMG_Load("./images/monster/m2_E_75.png");
	tab_sprite_monster[38] = IMG_Load("./images/monster/m2_E_50.png");
	tab_sprite_monster[39] = IMG_Load("./images/monster/m2_E_25.png");
	
	tab_sprite_monster[40] = IMG_Load("./images/monster/m2_S_100.png");
	tab_sprite_monster[41] = IMG_Load("./images/monster/m2_S_75.png");
	tab_sprite_monster[42] = IMG_Load("./images/monster/m2_S_50.png");
	tab_sprite_monster[43] = IMG_Load("./images/monster/m2_S_25.png");
	
	tab_sprite_monster[44] = IMG_Load("./images/monster/m2_W_100.png");
	tab_sprite_monster[45] = IMG_Load("./images/monster/m2_W_75.png");
	tab_sprite_monster[46] = IMG_Load("./images/monster/m2_W_50.png");
	tab_sprite_monster[47] = IMG_Load("./images/monster/m2_W_25.png");
	
	
	tab_sprite_monster[48] = IMG_Load("./images/monster/m3_N_100.png");
	tab_sprite_monster[49] = IMG_Load("./images/monster/m3_N_75.png");
	tab_sprite_monster[50] = IMG_Load("./images/monster/m3_N_50.png");
	tab_sprite_monster[51] = IMG_Load("./images/monster/m3_N_25.png");

	tab_sprite_monster[52] = IMG_Load("./images/monster/m3_E_100.png");
	tab_sprite_monster[53] = IMG_Load("./images/monster/m3_E_75.png");
	tab_sprite_monster[54] = IMG_Load("./images/monster/m3_E_50.png");
	tab_sprite_monster[55] = IMG_Load("./images/monster/m3_E_25.png");
	
	tab_sprite_monster[56] = IMG_Load("./images/monster/m3_S_100.png");
	tab_sprite_monster[57] = IMG_Load("./images/monster/m3_S_75.png");
	tab_sprite_monster[58] = IMG_Load("./images/monster/m3_S_50.png");
	tab_sprite_monster[59] = IMG_Load("./images/monster/m3_S_25.png");
	
	tab_sprite_monster[60] = IMG_Load("./images/monster/m3_W_100.png");
	tab_sprite_monster[61] = IMG_Load("./images/monster/m3_W_75.png");
	tab_sprite_monster[62] = IMG_Load("./images/monster/m3_W_50.png");
	tab_sprite_monster[63] = IMG_Load("./images/monster/m3_W_25.png");
	

	*(tab_sprite_monster+64) = IMG_Load("./images/monster/grave.png");

}


point pointStart(Map *map){

	Color3f c = map->in; // on stock la couleur de départ de référence
	int i, j, k;
	point start;
	int found = 0;
	orientation o;
	//char *nom_orientation;

	for (i=0 ; i < map->image->height ; i++){

		for (j=0 ; j < map->image->width ; j++){

			k = map->image->width*i*3+j*3;

			if (map->image->tabPixel[k] == c.r && map->image->tabPixel[k+1] == c.g && map->image->tabPixel[k+2] == c.b && found == 0){
			

				start.x = j;
				start.y = i;
				found = 1;
			}

		}

	}
	


	o = orientationStart(map,start);

	
	//nom_orientation = printOrientation(o);

	//printf("Orientation : %s \n",nom_orientation);

	
	if (o == N || o == S)
		start.x += 18;
	else
		start.y += 18;
		
	

	return start;

}


point pointEnd(Map *map){

	Color3f c = map->out; // on stock la couleur de départ de référence
	int i, j, k;
	point end;
	int found = 0;

	for (i=0 ; i < map->image->height ; i++){

		for (j=0 ; j < map->image->width ; j++){

			k = map->image->width*i*3+j*3;

			if (map->image->tabPixel[k] == c.r && map->image->tabPixel[k+1] == c.g && map->image->tabPixel[k+2] == c.b && found == 0){

				end.x = j;
				end.y = i;
				found = 1;
			}

		}

	}

	return end;

}


orientation orientationStart(Map *map, point start){

	orientation o;
	Color3f c = map->in;

	if (start.x == 0){

		o = E;

		if (start.y == 0){
			if (map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3] == c.r && map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3+1] == c.g && map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3+2] == c.b){
				o = S;
			}

		}
		else if (start.y == map->image->height-1){

			if (map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3] == c.r && map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3+1] == c.g && map->image->tabPixel[map->image->width*start.y*3+(start.x+5)*3+2] == c.b){

				o = N;
			}

		}

	}
	else if (start.x == map->image->width-1){

		o = W;

		if (start.y == 0){
			if (map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3] == c.r && map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3+1] == c.g && map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3+2] == c.b){
				o = S;
			}

		}
		else if (start.y == map->image->height-1){
			if (map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3] == c.r && map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3+1] == c.g && map->image->tabPixel[map->image->width*start.y*3+(start.x-5)*3+2] == c.b){
				o = N;
			}

		}

	}
	else{ // start.x > 0 && start.x < map->image->width-1

		if (start.y == 0)
			o = S;
		else
			o = N;
	}

	
	return o;

}



void move(Monster **head, Map *map){

	Monster *monster = *head;

	int node_indice;
	//char *nom_orientation;
	
	if(monster->PV <= 0) {}
	else{
	node_indice = isNode(monster->position,map);

	if(monster->type == Rampant && monster->num == 0){
		//printf("monster->position : %d  %d \n", monster->position .x, monster->position .y);


	//nom_orientation = printOrientation(monster->o);

	//printf(" orientation : %s \n",nom_orientation);
	//printf("ok ok \n");
	}
	

	if (node_indice != -1 ){

		if(monster->num == 0){
			//printf("node_indice : %d\n", node_indice);
		}

		
		if (node_indice < map->nb_node-1){ // Il existe un node après celui-ci
			//printf("ok \n");
			monster->o = changeOrientation(map->node_array[node_indice], map->node_array[node_indice+1]);

		}

		else{ // On est sur le dernier node
			monster->o = changeOrientation(map->node_array[node_indice], pointEnd(map));
		}
	}
	
	
			
	
	switch(monster->o){

		case N:
			monster->position.y -= monster->vitesse;
		break;

		case S:
			monster->position.y += monster->vitesse;
		break;

		case E:
			monster->position.x += monster->vitesse;
		break;

		case W:
			monster->position.x -= monster->vitesse;
		break;
	}
}

}





void moveMonsters(Monster **head, Map *map){

	Monster *monster = *head;

	if(monster != NULL){
		while(monster != NULL){
			move(&monster,map);
			monster= monster->next;
		}
	}
}




int isNode(point pt, Map *map){

	int found = -1, i, range = 6; // range étant la distance minimal entre le monstre et le node
	Color3f c = map->node;

		if(map->image->tabPixel[map->image->width*pt.y*3+pt.x*3] == c.r && map->image->tabPixel[map->image->width*pt.y*3+pt.x*3+1] == c.g && map->image->tabPixel[map->image->width*pt.y*3+pt.x*3+2] == c.b){ 


			for (i=0;i<map->nb_node;i++){
				
				//printf("pt.x : %d pt.y : %d \n", pt.x, pt.y);
				//printf("node.x : %d node.y : %d \n", map->node_array[i].x, map->node_array[i].y);

				if ((map->node_array[i].x - pt.x <= range && map->node_array[i].x - pt.x >= - range) || (pt.x - map->node_array[i].x <= range && pt.x - map->node_array[i].x >=  - range)){
					
					if ((map->node_array[i].y - pt.y <= range && map->node_array[i].y - pt.y >=  - range)){
						//printf("node ! \n");
						//printf("i %d\n",i);

						found = i;
					}
				}


			}

		}
	//printf("%d \n",found);
	return found;
}



orientation changeOrientation(point a, point b){

	orientation o;
	//char *nom_orientation;
	
	//printf("a.x : %d, a.y : %d \n",a.x,a.y);
	//printf("b.x : %d, b.y : %d \n",b.x,b.y);

	if (a.x < b.x){
		if (a.y < b.y + 20 && a.y > b.y - 20)
			o = E;
		else if(a.y < b.y)
			o = S;
		else
			o = N;
	}
	else if(a.x > b.x){

		if (a.y < b.y + 20 && a.y > b.y - 20)
			o = W;
		else if (a.y < b.y)
			o = S;
		else
			o = N;
	}
	else{
		if (a.y < b.y)
			o = S;
		else
			o = N;
	}

	
	/*
	if (a.x < b.x && (a.y < b.y + 10 && a.y > b.y - 10 )  ){
		o = E;		
	}
	else if (a.x > b.x && (a.y < b.y + 10 && a.y > b.y - 10 ) ){
		o = W;		
	}
	else if (a.y > b.y && (a.x < b.x + 10 && a.x > b.x - 10 ) ){
		o = S;		
	}
	else if (a.y < b.y && (a.x < b.x + 10 && a.x > b.x - 10 )){
		o = N;		
	}
	*/
	//nom_orientation = printOrientation(o);

	//printf(" orientation : %s \n",nom_orientation);
	//printf("ok ok \n");

	return o;
}




char* displayImageMonster(Monster *monster){

	char *img = malloc(sizeof(char)*50);

	switch(monster->type){

		case Vermine:
			switch(monster->o){

				case N:
				img = "./images/monster/m1_N.png";
				break;

				case S:
				img = "./images/monster/m1_S.png";
				break;

				case E:
				img = "./images/monster/m1_E.png";
				break;

				case W:
				img = "./images/monster/m1_W.png";
				break;
			}

		break;

		case Grouillant:
			switch(monster->o){

				case N:
				img = "./images/monster/m2_N.png";
				break;

				case S:
				img = "./images/monster/m2_S.png";
				break;

				case E:
				img = "./images/monster/m2_E.png";
				break;

				case W:
				img = "./images/monster/m2_W.png";
				break;
			}
		break;

		case Mastoc:
			switch(monster->o){

				case N:
				img = "./images/monster/m3_N.png";
				break;

				case S:
				img = "./images/monster/m3_S.png";
				break;

				case E:
				img = "./images/monster/m3_E.png";
				break;

				case W:
				img = "./images/monster/m3_W.png";
				break;
			}
		break;

		case Rampant:
			switch(monster->o){

				case N:
				img = "./images/monster/m4_N.png";
				break;

				case S:
				img = "./images/monster/m4_S.png";
				break;

				case E:
				img = "./images/monster/m4_E.png";
				break;

				case W:
				img = "./images/monster/m4_W.png";
				break;
			}
		break;
	}

	return img;
}


int monsterEnd(Monster *monster, Map *map){

	if (monster->position.x < 0 || monster->position.x > map->image->width || monster->position.y < 0 || monster->position.y > map->image->height)
		return 1;
	else
		return 0;
}



int gameOver(Monster *monster, Map *map){

	int game_over = 0;

	Monster *tmp_monster = monster;

	while(tmp_monster != NULL && game_over == 0){

		game_over = monsterEnd(tmp_monster,map);
		tmp_monster = tmp_monster->next;
	}

	return game_over;
}



void print_monsters(Monster *monster, SDL_Surface *tab_sprite_monster[], SDL_Surface *framebuffer){
	int type, orientation, etat, indice;
	char * type_monster= NULL;
	SDL_Rect position ;
	Monster *tmp = monster;

	if(tmp != NULL){
		while(tmp != NULL){


			switch(tmp->type){

			    case Vermine :
				type = 0;
			    break;

			     case Grouillant :
				type = 1;
			    break;

			     case Mastoc :
				type = 2;
			    break;

			     case Rampant :
				type = 3;
			    break;

			}

			 switch(tmp->o){

			    case N :
				orientation = 0;
				position.x = tmp->position.x-15;
		    	position.y = tmp->position.y-25;
			    break;

			     case E :
				orientation = 1;
				position.x = tmp->position.x-15;
		    	position.y = tmp->position.y-25;
			    break;

			     case S :
				orientation = 2;
				position.x = tmp->position.x-15;
		   	 position.y = tmp->position.y-25;
			    break;

			     case W :
				orientation = 3;
				position.x = tmp->position.x-15;
		   	 position.y = tmp->position.y-25;
			    break;

			}

			
			if (tmp->PV > (75*tmp->nbPV)/100){
			    etat = 0;
			}
			else if (tmp->PV <= (75*tmp->nbPV)/100 && tmp->PV > (50*tmp->nbPV)/100){
			    etat = 1;
			}
			else if (tmp->PV <= (50*tmp->nbPV)/100 && tmp->PV > (25*tmp->nbPV)/100){
			    etat = 2;
			}
			else if (tmp->PV <= (25*tmp->nbPV)/100 && tmp->PV > 0){
			    etat = 3;
			}
			else{
			    etat = 4;
			}


			if (etat != 4) {
			    indice = type*16+orientation*4+etat;
			    //printf("indice : %d \n", indice);
			    }
			else
			    indice = 64;

			
			SDL_BlitSurface(tab_sprite_monster[indice], NULL, framebuffer, &position);
			
			type_monster = monsterType(tmp->type);
			//printf("monster->type : %s \n", type_monster);
			tmp = tmp->next;

		}

	}


}

Monster* createMonster(Map *map, int vague, int num){

	Monster *monster = (Monster*)malloc(sizeof(Monster));
	int type;

	srand(time(NULL)); 

	type = rand_bornes(0,4);

	if (monster !=  NULL){

		monster->num = num;



		if (type == 0){
			monster->type = Vermine;
			monster->def[0] = 1+vague;
			monster->def[1] = 5+vague;
			monster->def[2] = 1+vague;
			monster->def[3] = 3+vague;
			monster->vitesse = 1 + (int)(vague/10);
			monster->nbPV = 100 ;
			monster->PV = 100 ;
		}
		else if(type == 1){
			monster->type = Grouillant;
			monster->def[0] = 1+vague;
			monster->def[1] = 3+vague;
			monster->def[2] = 5+vague;
			monster->def[3] = 1+vague;
			monster->vitesse = 3 ; //+ (int)(vague/10)
			monster->nbPV = 150 ;
			monster->PV = 150 ;
		}
		else if (type == 2){
			monster->type = Mastoc;
			monster->def[0] = 5+vague;
			monster->def[1] = 1+vague;
			monster->def[2] = 3+vague;
			monster->def[3] = 1+vague;
			monster->vitesse = 1 + (int)(vague/10);
			monster->nbPV = 150 ;
			monster->PV = 150 ;
		}
		else{
			monster->type = Rampant;
			monster->def[0] = 3+vague;
			monster->def[1] = 5+vague;
			monster->def[2] = 1+vague;
			monster->def[3] = 1+vague;
			monster->vitesse = 2 + (int)(vague/10);
			monster->nbPV = 250 ;
			monster->PV = 250 ;
		}

		monster->position = pointStart(map); //+ réorientation
		monster->o = orientationStart(map,  monster->position);
		

		monster->previous = NULL;
		monster->next = NULL;


	}

	return monster;
}

void createMonsters(Monster **head, Map *map, int nb_monster, int vague){

	int i=0;
	Monster *monster = NULL, *tmp;

	monster = createMonster(map,vague,i);

	*head = monster;

	for (i=1;i<nb_monster;i++){


		tmp = createMonster(map,vague,i);
		tmp->next = NULL;
		monster->next = tmp;
		tmp->previous = monster;

		monster=tmp;


	}
}

void addMonster(Monster **head, Map *map, int vague){

    Monster *tmp, *monster;
    
    	if (head != NULL && *head != NULL){

		tmp = lastMonster(*head);
		monster = createMonster(map,vague,tmp->num+1);
	
		tmp->next = monster;
	    	monster->previous = tmp;
	}
	else{

		monster = createMonster(map,vague,0);
		*head = monster;
	}

}

Monster* lastMonster(Monster *monster){

        Monster *tmp = monster;

        while (tmp->next != NULL)
            tmp = tmp->next;

        return tmp;
}


int rand_bornes(int a, int b){

	// On suppose a<b
	return (a + (rand()%(b-a)));
}

char* monsterType(type_monster type){

	char *nom_type = malloc(sizeof(char)*15);

	switch(type){

		case Vermine:
		nom_type = "Vermine";
		break;

		case Grouillant:
		nom_type = "Grouillant";
		break;

		case Mastoc:
		nom_type = "Mastoc";
		break;

		case Rampant:
		nom_type = "Rampant";
		break;
	}

	return nom_type;
}


char* printOrientation(orientation o){

	char *nom_orientation = malloc(sizeof(char)*5);

	switch(o){

		case N:
		nom_orientation = "Nord";
		break;

		case E:
		nom_orientation = "Est";
		break;

		case S:
		nom_orientation = "Sud";
		break;

		case W:
		nom_orientation = "Ouest";
		break;
	}

	return nom_orientation;
}


int is_dead(Monster** head, int nb_monstre, player* Player) {
	int yes = 0 ; 
	Monster* tmp = *head ; 
	
	while(tmp != NULL) {
		if(tmp->PV <= 0) yes++;
	
		tmp = tmp->next ; 
	}
	
	
	if(yes == nb_monstre) { return 1 ;
		Player->money += 200 ;
	
	}
	else return 0 ;


}

void clean_list_monster(Monster** head) {

	if(*head != NULL ) {
	
		Monster* tmp = *head ; 
		while(tmp !=NULL) {
			Monster* del = tmp ; 
			tmp = tmp->next ; 
			free(del);
		
		}

	}
*head = NULL ;		
head = NULL ;	 


}



Monster* select_monster(Monster** head, point X) {

	Monster* tmp = *head ; 
	int p = 0 ; 
	
	
	
		while(tmp != NULL) {
			p = is_monster(X, tmp->position) ;
			if(p==1)return tmp ; 			
			//printf("Point center : %f  %f \n num %d \n range %d \n\n", tmp->center.x, tmp->center.y, tmp->num, tmp->range);
			//printf("p = %d \n", p);
			tmp = tmp -> next ;
		}
	
	return NULL ;
	//printf("num %d \n range %d \n\n", tmp->num, tmp->range);
	//printf("p = %d \n", p);
	

}


int is_monster(point X, point center) {
	
	//printf("Point X : %f  %f - Point center : %f  %f \n", X.x, X.y, center.x, center.y);
	
	if(X.x < center.x + 10 && X.x > center.x - 10 && X.y < center.y + 25 && X.y > center.y - 25) return 1;
	else return 0 ;  
}

void print_info_monster(Monster* M, SDL_Surface *framebuffer, SDL_Surface *Monster){

	SDL_Surface* text = NULL, *text2 = NULL ; 
	SDL_Rect position ;
   SDL_Color Red = {255, 0, 0};
   SDL_Color Black = {0, 0, 0};   	
   TTF_Font *police = NULL;
   police = TTF_OpenFont("images/Triforce.ttf", 16); 
   char tmp[10] ;
	position.x = 655 ; 
	position.y = 530 ; 
	SDL_BlitSurface(Monster, NULL, framebuffer, &position);	
	sprintf(tmp,"%d",(int)M->PV);
	text = TTF_RenderText_Blended(police, tmp, Red);
	position.x = 660 ; 
	position.y = 600 ; 
	
		 
	SDL_BlitSurface(text, NULL, framebuffer, &position);	
	position.y += 20 ;
	
		switch(M->type){

		case Vermine:
		text2 = TTF_RenderText_Blended(police, "Blop", Black);
		break;

		case Grouillant:
		text2 = TTF_RenderText_Blended(police, "Nonoss", Black);
		position.x = 650 ;
		break;

		case Mastoc:
		text2 = TTF_RenderText_Blended(police, "Jelly", Black);
		
		break;

		case Rampant:
		text2 = TTF_RenderText_Blended(police, "Neunoeil", Black);
		position.x = 650 ;
		break;
	}
	
	SDL_BlitSurface(text2, NULL, framebuffer, &position);	
	
    SDL_FreeSurface(text); SDL_FreeSurface(text2);
    TTF_CloseFont(police);

}


