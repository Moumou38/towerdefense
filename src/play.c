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
#include "game/player.h"
#include "game/monster.h"
#include "game/button.h"
#include "play.h"


static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


int play_game(SDL_Surface* framebuffer, SDL_Surface* screen, char* map_itd, char* img_map) {
	/* Ouverture de la map */
	Map *map = (Map*)malloc( 1 * sizeof(Map));
	int ouverture = open_map(map, map_itd);

	if(ouverture == 0) return 0 ; 
			
	/*creation du joueur*/
	player* Player = (player*)malloc(1*sizeof(player));
	Player->score = 0 ; 
	Player->money = 500 ;



	/* Initialisation des surfaces SDL */
	SDL_Surface* imagedefond = NULL, *tour1 = NULL, *tour2 = NULL, *tour3 = NULL, *tour4 = NULL, *tour_NULL = NULL, *score = NULL, *score_text = NULL, *joueur = NULL, *selection = NULL, *quitter = NULL, *selection_NULL = NULL, *gun = NULL, *rocket = NULL, *laser = NULL, *hybrid = NULL, *target = NULL, *info = NULL, *money = NULL, *destruction = NULL, *vague_im = NULL,  *nb_vague = NULL, *upgrade = NULL, *upgrade_NULL = NULL, *tab_sprite_monster[65], *coin = NULL, *cheat_image = NULL, *cheat_image2 = NULL, *info_monster = NULL, *info_monster_NULL = NULL, *monster0 = NULL, *monster1 = NULL, *monster2 = NULL, *monster3 = NULL, *pause_im = NULL, *bg = NULL ;
	
	 

	SDL_Rect position, position_tour1 , position_tour2 , position_tour3 , position_tour4, position_joueur, position_score, position_score_text, position_selection, position_gun, position_rocket, position_laser, position_hybrid, position_target, position_info, position_money, position_money_text, position_destruction, position_quitter, position_info_monster, position_vague, position_vague_nb, position_upgrade,position_cheat, position_pause ; 
	
	/* Implémentation des fonts */
	SDL_Color White = {255, 255, 255};
	SDL_Color Red = {255, 0, 0};  
	SDL_Color Black = {0, 0, 0}; 
	TTF_Font *police1 = NULL, *police2 = NULL, *police3 = NULL;
	TTF_Init();    
	police1 = TTF_OpenFont("images/Triforce.ttf", 36); 
	police2 = TTF_OpenFont("images/Triforce.ttf", 20); 
	police3 = TTF_OpenFont("images/Triforce.ttf", 16);    
	vague_im = TTF_RenderText_Blended(police2, "Vagues restantes : ", White); 
	joueur = TTF_RenderText_Blended(police1, "Joueur", White);
	score_text = TTF_RenderText_Blended(police2, "Score : ", White); 
	selection = TTF_RenderText_Blended(police2, "Selectionnez votre tour : ", Black); 
	selection_NULL = TTF_RenderText_Blended(police2, "Cliquez sur une zone constructible ", Black); 
	gun = TTF_RenderText_Blended(police3, "Gun", Black);
	rocket = TTF_RenderText_Blended(police3, "Rocket", Black);
	laser = TTF_RenderText_Blended(police3, "Laser", Black);
	hybrid = TTF_RenderText_Blended(police3, "Hybrid", Black);
	coin = TTF_RenderText_Blended(police1, "$  ", Red);
	
	/* Chargement des sprites */
	
	init_tab_monster(tab_sprite_monster);
	
	imagedefond = IMG_Load(img_map);
	 
	tour1 = IMG_Load("./images/tower/tour1.png");
	tour2 = IMG_Load("./images/tower/tour2.png");
	tour3 = IMG_Load("./images/tower/tour3.png");
	tour4 = IMG_Load("./images/tower/tour4.png"); 
	tour_NULL = IMG_Load("./images/tower/tour_NULL.png");
	
	target = IMG_Load("./images/target.png");
	bg = IMG_Load("./images/bg.png");
	
	info = IMG_Load("./images/info2.png");
	destruction = IMG_Load("./images/button/destruction.jpg") ;  
	quitter = IMG_Load("./images/button/quitter.jpg") ;        
	pause_im = IMG_Load("./images/button/pause.jpg") ;  
	 
	cheat_image = IMG_Load("./images/button/cheat.jpg") ;	 
	cheat_image2 = IMG_Load("./images/button/cheat_2.jpg") ;
	
	upgrade = IMG_Load("./images/button/achat.jpg") ;	
	upgrade_NULL = IMG_Load("./images/button/achat_NULL.jpg") ;
	
	info_monster = IMG_Load("./images/info_monstre.png"); 
	info_monster_NULL = IMG_Load("./images/info_monstre_NULL.png"); 
	monster0 = IMG_Load("./images/monster/monster0.png"); 
	monster1 = IMG_Load("./images/monster/monster1.png"); 
	monster2 = IMG_Load("./images/monster/monster2.png"); 
	monster3 = IMG_Load("./images/monster/monster3.png");  
	
	

	
	/* Initialisation des variables */  
	char tmp[10], tmp2[10], tmp3[4];
	int loop = 1, dead = 0, konami = 0, cheat = 0, build1 = 0, quit = 0, tempsActuelMonster = 0, tempsActuel = 0, xClicked = 0, yClicked =0, nb_monster = 10, vague = 0, monsterQuit; 
	point X;

	
	
	
	/* Initialisation des tours */
	tower* head = (tower*)malloc(1*sizeof(tower)); 
	tower* selected = NULL ; 
	head->next = NULL ; 
	head->previous = NULL ;
	head->num = 0;		
	
	/* Initialisation des monstres */    
   
	Monster *monster = NULL, *monster_tmp, *monster_selected = NULL;

	/* Initialisation des positions */
	
	position_info_monster.x = 600 ;
	position_info_monster.y = 500 ;

	position.x = 0 ;
	position.y = 0 ; 

	position_destruction.x = 815 ; 
	position_destruction.y = 540 ; 

	position_tour1.x = 50 ;
	position_tour1.y = 548 ; 

	position_selection.x = 50 ; 
	position_selection.y = 490+40 ;

	position_tour2.x = position_tour1.x + 50 + 35 ;
	position_tour2.y = position_tour1.y ;

	position_tour3.x = position_tour2.x + 50 + 35 ;
	position_tour3.y = position_tour1.y ;

	position_tour4.x = position_tour3.x + 50 + 35 ;
	position_tour4.y = position_tour1.y ;


	position_gun.x = position_tour1.x + 10;
	position_gun.y = 595+40 ; 

	position_rocket.x = position_tour2.x + 5;
	position_rocket.y = position_gun.y ; 

	position_laser.x = position_tour3.x +5;
	position_laser.y = position_gun.y ; 

	position_hybrid.x = position_tour4.x+5;
	position_hybrid.y = position_gun.y ; 

	position_quitter.x = map->image->width + 70 ;
	position_quitter.y = 620 ;	

	position_cheat.x = 450-27 ;
	position_cheat.y = 602 ; 
	
	position_pause.x = 450-27 ;
	position_pause.y = 602 - 50 ;

	position_joueur.x = map->image->width + 80 ;
	position_joueur.y = 10 ;

	position_money_text.x = map->image->width + 50 ;
	position_money_text.y = 45 ;

	position_money.x = position_money_text.x + 50 ;
	position_money.y = 53 ;

	position_vague.x = 800 ; 
	position_vague.y = 115 ; 

	position_vague_nb.x = 955 ; 
	position_vague_nb.y = 115 ;

	position_score_text.x = map->image->width + 50 ;
	position_score_text.y = position_money.y + 30 ;

	position_score.x = position_score_text.x + 110 ;
	position_score.y = position_money.y + 30 ;

	position_info.x = 775 ;
	position_info.y = position_money.y + 100 ; 

	position_upgrade.x = 825 ; 
	position_upgrade.y = 485 ;
	
	/* Implémentation des boutons */

	Button *gun_tower_button;
	Button *rocket_tower_button;
	Button *laser_tower_button;
	Button *hybrid_tower_button;
	Button *upgrade_tower_button;
	Button *delete_tower_button;
	Button *cheat_button;
	Button *quit_button;
	Button *pause_button ;

	point button; // On utilise la même variable pour créer chaque bouton

	button.x = 820;
	button.y = 620;
	quit_button = addButton("Quitter",button,142,42);

	button.x = 450;
	button.y = 602;
	cheat_button = addButton("Cheat",button,142,42);
	
	button.x = position_destruction.x ; 
	button.y = position_destruction.y ;	
	delete_tower_button = addButton("Delete",button,142,42);
	
	button.x = position_upgrade.x ; 
	button.y = position_upgrade.y ;	
	upgrade_tower_button = addButton("Upgrade",button,142,42);
	
	button.x = position_tour1.x ; 
	button.y = position_tour1.y ;	
	gun_tower_button = addButton("Gun",button,50,90);
		
	button.x = position_tour2.x ; 
	button.y = position_tour2.y ;	
	rocket_tower_button = addButton("Rocket",button,50,90);
	
	button.x = position_tour3.x ; 
	button.y = position_tour3.y ;	
	laser_tower_button = addButton("Laser",button,50,90);
	
	button.x = position_tour4.x ; 
	button.y = position_tour4.y ;	
	hybrid_tower_button = addButton("Hybrid",button,50,90);
	
	button.x = position_pause.x ; 
	button.y = position_pause.y ;	
	pause_button = addButton("pause",button,142,42);
	
	
	
    while(loop) {
    
    
    
    if(SDL_GetTicks() - tempsActuelMonster > 50){
		if(SDL_GetTicks() - tempsActuel > 3000){
			if(nb_monster > 0) {
				addMonster(&monster,map, vague);
				nb_monster -- ;
									
			}
			//printf(" secoooonde \n") ; 
			
		
		tempsActuel = SDL_GetTicks() ;
		}
			
			moveMonsters(&monster,map);
			monster_tmp = monster;

					while (monster_tmp != NULL){
						if(monster_tmp->PV > 0) can_attack_list(head, monster_tmp, Player) ;
						monster_tmp = monster_tmp->next;
					}
		dead = is_dead(&monster, 10, Player)	;
			if(dead == 1 && vague !=20) { //tous les monstres sont morts, c'est la fin de la vague
				vague++;
				Player->money += 50 ;
				nb_monster = 10 ; 
				clean_list_monster(&monster);		
				monster_selected = NULL ; 
			}	
			else if(dead == 1 && vague == 20) quit = 1 ;
			
		
		
		monsterQuit = gameOver(monster, map);	
		tempsActuelMonster = SDL_GetTicks();
		}

		
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
						
					
						if ( xClicked < map->image->width && yClicked < map->image->height ) {
							X.x = xClicked ; 
							X.y = yClicked ; 
							position_target.x = X.x-15 ;
							position_target.y = X.y-15 ;
							build1 = buildable(X, map) ;
							monster_selected = select_monster(&monster, X);
							//printf("build : %d \n", build1);
							if(head->num !=0) { 
							selected = select_tower(head, X) ;
							if(monster_selected != NULL) {
								//printf("num %d \n PV %f \n\n", monster_selected->num, monster_selected->PV);
							} 
							  }
								
						}
						else {
													 
						 /* Evènements liés aux boutons */
							if(selected != NULL && isButtonSelected(upgrade_tower_button,xClicked,yClicked) && Player->money >= 30 && selected->level < 3) {						 	
							upgrade_tower(selected, Player);						 
							 }
						
							//printf("xclicked et yclicked : %d  %d  \n", xClicked, yClicked);
						 if(selected != NULL && isButtonSelected(delete_tower_button,xClicked,yClicked)) {						 	
						 	Player->money += selected->cost/2 ;
							head = delete_tower(selected, head) ;
							selected = NULL ; 
						 
						 }


						/* Activer le Konami code */
						if(isButtonSelected(cheat_button,xClicked,yClicked) && cheat ==1) {
						  		vague++;
								if(vague >= 20) quit = 1 ;	
								clean_list_monster(&monster);		
								nb_monster = 10 ;
								monster_selected = NULL ; 
								cheat = -1 ;					  
						  
						  } 
						if (isButtonSelected(quit_button,xClicked,yClicked)) quit = 1 ;
						if (isButtonSelected(pause_button,xClicked,yClicked)) pause() ;

						/* Activer le konami code */

						 if (build1 == 1 && selected == NULL ) {
							/* //printf("donc le build = 1 et  %d  %d  \n", X.x, X.y);
							printf("xclicked et yclicked : %d  %d  \n", xClicked, yClicked); */
							
							
							if(isButtonSelected(gun_tower_button,xClicked,yClicked)) {
									//printf("%d  %d  \n", X.x, X.y);
									build(head,X,map,1,Player);
									head = next(head);
									//Player->money -= head->cost ;						  
								}
							else if(isButtonSelected(rocket_tower_button,xClicked,yClicked)) {
									//printf("%d  %d  \n", X.x, X.y);
									build(head,X,map,2,Player);
									head = next(head);
									//Player->money -= head->cost ;						  
								}
							else if(isButtonSelected(laser_tower_button,xClicked,yClicked)) {
									//printf("%d  %d  \n", X.x, X.y);
									build(head,X,map,3,Player);
									head = next(head);
									//Player->money -= head->cost ;						  
								}
							else if(isButtonSelected(hybrid_tower_button,xClicked,yClicked)) {
									//printf("%d  %d  \n", X.x, X.y);
									build(head,X,map,4,Player);
									head = next(head);
									//Player->money -= head->cost ;					  
								}				
						
						build1 = 0 ;
						
							}
							
							
						}
					break;
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym){
						case SDLK_ESCAPE : 
							quit = 1 ; 
						break;
		
						case SDLK_UP : 	
							if(konami == 0 || konami == 1) konami++ ; 
							else konami = 0 ; 
							
						break ; 
						case SDLK_DOWN : 	
							if(konami == 2 || konami == 3) konami++ ; 
							else konami = 0 ; 							
						break ; 
						case SDLK_LEFT : 	
							if(konami == 4 || konami == 6) konami++ ; 
							else konami = 0 ; 							
						break ; 
						case SDLK_RIGHT : 	
							if(konami == 5 || konami == 7) konami++ ; 
							else konami = 0 ; 							
						break ;
						case 'b' : 	
							if(konami == 8) konami++ ; 
							else konami = 0 ; 							
						break ;
						case 'a' : 	
							if(konami == 9 && cheat != -1) { printf("CHEAT ! \n"); 
								cheat = 1 ;
								konami = 0 ;
							}
							else konami = 0 ; 							
						break ;
							
						
						default : break;
					}
				break; 	

				}		


			}
			
			  /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));

        
        /* Placer ici le code de dessin */
        SDL_BlitSurface(imagedefond, NULL, framebuffer, &position);
       SDL_BlitSurface(bg, NULL, framebuffer, &position);
        if(selected != NULL) select_tower_trace(selected->center, selected->range, framebuffer) ;
        
        SDL_BlitSurface(joueur, NULL, framebuffer, &position_joueur);
        
        SDL_BlitSurface(vague_im, NULL, framebuffer, &position_vague);
        sprintf(tmp3,"%d",20-vague);
        nb_vague = TTF_RenderText_Blended(police2, tmp3 , Red); 
        SDL_BlitSurface(nb_vague, NULL, framebuffer, &position_vague_nb);
        
        
        SDL_BlitSurface(coin, NULL, framebuffer, &position_money_text);  
		  sprintf(tmp,"%d",Player->money);
        money = TTF_RenderText_Blended(police2, tmp , Red); 
        SDL_BlitSurface(money, NULL, framebuffer, &position_money);
        
        SDL_BlitSurface(score_text, NULL, framebuffer, &position_score_text);  
		  sprintf(tmp2,"%d",Player->score);
        score = TTF_RenderText_Blended(police2, tmp2 , Red); 
        SDL_BlitSurface(score, NULL, framebuffer, &position_score);            
       
       SDL_BlitSurface(gun, NULL, framebuffer, &position_gun);
		 SDL_BlitSurface(rocket, NULL, framebuffer, &position_rocket);
       SDL_BlitSurface(laser, NULL, framebuffer, &position_laser);
		 SDL_BlitSurface(hybrid, NULL, framebuffer, &position_hybrid);
			
			
			if(build1 == 1 && selected == NULL) { 
				SDL_BlitSurface(selection, NULL, framebuffer, &position_selection);			
				SDL_BlitSurface(tour1, NULL, framebuffer, &position_tour1);
				SDL_BlitSurface(tour2, NULL, framebuffer, &position_tour2);
				SDL_BlitSurface(tour3, NULL, framebuffer, &position_tour3);
				SDL_BlitSurface(tour4, NULL, framebuffer, &position_tour4);
				SDL_BlitSurface(target, NULL, framebuffer, &position_target);				
							
			}
			else if(build1 == 0 || selected != NULL) {
				SDL_BlitSurface(selection_NULL, NULL, framebuffer, &position_selection);
				SDL_BlitSurface(tour_NULL, NULL, framebuffer, &position_tour1);
				SDL_BlitSurface(tour_NULL, NULL, framebuffer, &position_tour2);
				SDL_BlitSurface(tour_NULL, NULL, framebuffer, &position_tour3);
				SDL_BlitSurface(tour_NULL, NULL, framebuffer, &position_tour4);
			
			
			
			}
		
			SDL_BlitSurface(info, NULL, framebuffer, &position_info);
			SDL_BlitSurface(quitter, NULL, framebuffer, &position_quitter);
			
			if (selected == NULL){ 
				info_tower(selected, tour_NULL, framebuffer);
				SDL_BlitSurface(upgrade_NULL, NULL, framebuffer, &position_upgrade);
			}
			else { 
				if(selected->type == 1) info_tower(selected, tour1, framebuffer); 
				else if(selected->type == 2) info_tower(selected, tour2, framebuffer); 
				else if(selected->type == 3) info_tower(selected, tour3, framebuffer); 	
				else if(selected->type == 4) info_tower(selected, tour4, framebuffer); 
			
				if(Player->money >= 30 && selected->level < 3)SDL_BlitSurface(upgrade, NULL, framebuffer, &position_upgrade);
				else SDL_BlitSurface(upgrade_NULL, NULL, framebuffer, &position_upgrade);
				SDL_BlitSurface(destruction, NULL, framebuffer, &position_destruction);
			}
			if(monster_selected != NULL) { 
				select_tower_trace(monster_selected->position, 20, framebuffer);
				SDL_BlitSurface(info_monster, NULL, framebuffer, &position_info_monster);  
			
				switch(monster_selected->type){

					case Vermine:
						print_info_monster(monster_selected, framebuffer, monster0);
					break;

					case Grouillant:
						print_info_monster(monster_selected, framebuffer, monster1);
					break;

					case Mastoc:
						print_info_monster(monster_selected, framebuffer, monster2);
					break;

					case Rampant:
						print_info_monster(monster_selected, framebuffer, monster3);
					break;
				} 
				
				
				

			}
			else SDL_BlitSurface(info_monster_NULL, NULL, framebuffer, &position_info_monster);  
			
			if(cheat == 1) { 
				SDL_BlitSurface(cheat_image, NULL, framebuffer, &position_cheat);  
			}
			else if (cheat == -1) { //konami code utilisé
				SDL_BlitSurface(cheat_image2, NULL, framebuffer, &position_cheat);
			}
			
			
			print_tower(head,tour1, tour2, tour3, tour4, framebuffer, screen);
			print_monsters(monster, tab_sprite_monster, framebuffer);
			
			
			if(quit == 1 || monsterQuit == 1) { 
				SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));
				loop = game_over(framebuffer, screen, Player->score, vague, monsterQuit);						
			}
			
		SDL_BlitSurface(pause_im, NULL, framebuffer, &position_pause);	
		tower_cost(map,framebuffer);
				
		  
				
     
        
			
        /* On copie le framebuffer à l'écran */
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        SDL_Flip(screen);
        
			
			
			
			
   	//printf("%d \n", SDL_GetTicks()) ;
    
        }
        
	TTF_CloseFont(police1);
	TTF_CloseFont(police2);
	TTF_CloseFont(police3);
	free(map->image->tabPixel);  
	free(map->image);
	free(map); 
	head = clean_tower_list(head);
	selected = NULL ;
	free(head);
	monster_selected = NULL ;
	clean_list_monster(&monster);		
	int i ;
	for(i=0;i<=64;i++) SDL_FreeSurface(tab_sprite_monster[i]);

	SDL_FreeSurface(imagedefond);
	SDL_FreeSurface(tour1);
	SDL_FreeSurface(tour2);
	SDL_FreeSurface(tour3);
	SDL_FreeSurface(tour4);
	SDL_FreeSurface(tour_NULL);
	SDL_FreeSurface(score);
	SDL_FreeSurface(score_text);
	SDL_FreeSurface(gun);
	SDL_FreeSurface(rocket);
	SDL_FreeSurface(laser);
	SDL_FreeSurface(hybrid);
	SDL_FreeSurface(joueur);
	SDL_FreeSurface(selection);
	SDL_FreeSurface(selection_NULL); 
	SDL_FreeSurface(bg);
	SDL_FreeSurface(quitter);
	SDL_FreeSurface(target);
	SDL_FreeSurface(info);
	SDL_FreeSurface(money);
	SDL_FreeSurface(destruction);
	SDL_FreeSurface(vague_im);
	SDL_FreeSurface(nb_vague);
	SDL_FreeSurface(upgrade);
	SDL_FreeSurface(upgrade_NULL);
	SDL_FreeSurface(coin);
	SDL_FreeSurface(cheat_image);
	SDL_FreeSurface(cheat_image2);
	SDL_FreeSurface(pause_im);
	
	deleteButton(gun_tower_button);
	deleteButton(rocket_tower_button);
	deleteButton(laser_tower_button);
	deleteButton(hybrid_tower_button);
	deleteButton(upgrade_tower_button);
	deleteButton(delete_tower_button);
	deleteButton(cheat_button);
	deleteButton(quit_button);
	deleteButton(pause_button);
    
    
    
    
    return 0;
}



int game_over(SDL_Surface* framebuffer, SDL_Surface* screen, int scorenb, int vague, int monster_quit) {


	
    /* Création d'une surface SDL */
    //printf("vague = %d \n \n", vague);
    SDL_Surface* gameover = NULL, *score = NULL, *text = NULL, *fin = NULL ;
    SDL_Rect position_gameover, position_score, position_text, position ;
    
    if(vague < 10) fin = IMG_Load("./images/end/endgame_bad.jpg");
    else if ((vague >= 10 && vague < 20) || (vague == 20 && monster_quit == 1)) fin = IMG_Load("./images/end/endgame_mid.jpg");
    else fin = IMG_Load("./images/end/endgame_good.jpg");
    
	position_gameover.x = 400 ;
	position_gameover.y = 50 ; 
	
	position_score.x = 530 ;      
	position_score.y = 300 ; 
	
	position_text.x = 200 ; 
	position_text.y = 300 ; 
	
	position.x = 150 ;
	position.y = 100 ; 
	
	
	
    SDL_Color White = {255, 255, 255};
    SDL_Color Red = {255, 0, 0};   
    SDL_Color Black = {0,0,0} ;
    TTF_Font *police1 = NULL, *police2 = NULL;
    TTF_Init();
    police1 = TTF_OpenFont("images/Triforce.ttf", 40); 
    police2 = TTF_OpenFont("images/Triforce.ttf", 20); 
    gameover = TTF_RenderText_Blended(police1, "Game Over", White);
    text = TTF_RenderText_Blended(police2, "Score : ", Black);
    char tmp[10] ;                            
    int loop = 1;
    
     sprintf(tmp,"%d",scorenb);
     score = TTF_RenderText_Blended(police1, tmp , Red); 

    
  
 

    
    

    
    while(loop) {
    
			SDL_Event e;
			while(SDL_PollEvent(&e)) {
				if(e.type == SDL_QUIT) {
					loop = 0;
				}
				switch(e.type) {
					case SDL_MOUSEBUTTONUP:
						loop = 0;
						//printf("%d  %d  \n", xClicked, yClicked);
						
						break;	

				}		


			}
			
			  /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));
			SDL_BlitSurface(fin, NULL, framebuffer, &position);
			SDL_BlitSurface(gameover, NULL, framebuffer, &position_gameover);
        SDL_BlitSurface(text, NULL, framebuffer, &position_text);
        SDL_BlitSurface(score, NULL, framebuffer, &position_score);
         
        /* Placer ici le code de dessin */
       	
			
			
        /* On copie le framebuffer à l'écran */
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        SDL_Flip(screen);
        
			
			
			
			
        
        
   
    
        }
        
        
        SDL_FreeSurface(gameover);
    SDL_FreeSurface(score);
    SDL_FreeSurface(text);
    SDL_FreeSurface(fin);
    TTF_CloseFont(police1);
    TTF_CloseFont(police2);
    
    return 0;
}




int help(SDL_Surface* framebuffer, SDL_Surface* screen) {

	
    /* Création d'une surface SDL */
    SDL_Surface* page1 = NULL, *page2 = NULL, *next = NULL, *previous = NULL, *quitter = NULL ;
    SDL_Rect position_page, position_next, position_quitter ; 
    
	position_page.x = 150 ;
	position_page.y = 100 ; 
	
	position_quitter.x = 750 + 70 ;
    position_quitter.y = 620 ;	
    
    position_next.x = 715 ; 
    position_next.y = 530 ;  
	
	 page1 = IMG_Load("./images/button/page1.jpg") ;  
	 page2 = IMG_Load("./images/button/page2.jpg") ;  
    next = IMG_Load("./images/button/next.jpg") ;  
    previous = IMG_Load("./images/button/previous.jpg") ;     
    quitter = IMG_Load("./images/button/quitter.jpg") ;                             
    int loop = 1;
    int page = 1 ; 
    int xClicked = 0, yClicked = 0 ;
    
    
  
 

    
    

    
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
					if( xClicked >= position_quitter.x && yClicked >= 620) loop = 0;
					else if (xClicked >= position_next.x && xClicked < position_next.x + 100 && yClicked >= position_next.y && position_next.y < position_next.y + 50 && page == 1) page = 2 ;
					else if (xClicked >= position_next.x && xClicked < position_next.x + 100 && yClicked >= position_next.y && position_next.y < position_next.y + 50 && page == 2) page = 1 ; 
						//printf("%d  %d  \n", xClicked, yClicked);
						
						break ;	

				}		


			}
			
			  /* Nettoyage du framebuffer */
        SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));
        if (page == 1) { 
			SDL_BlitSurface(page1, NULL, framebuffer, &position_page);
			SDL_BlitSurface(next, NULL, framebuffer, &position_next);			
			
			}
			else { 
			SDL_BlitSurface(page2, NULL, framebuffer, &position_page);	
			SDL_BlitSurface(previous, NULL, framebuffer, &position_next);	
			
			}
			
			SDL_BlitSurface(quitter, NULL, framebuffer, &position_quitter);       
        /* Placer ici le code de dessin */
       	
			
			
        /* On copie le framebuffer à l'écran */
        SDL_BlitSurface(framebuffer, NULL, screen, NULL);
        
        SDL_Flip(screen);
        
			
			
			
			
        
        
   
    
        }
    
    SDL_FreeSurface(page1);
    SDL_FreeSurface(page2);
    SDL_FreeSurface(next);
    SDL_FreeSurface(previous);
    SDL_FreeSurface(quitter);

    
    return 0;
}





int pause() {

	
    int xClicked = 0, yClicked = 0 ;                     
    int loop = 1;
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
					if( xClicked >= 450 && xClicked <= 592 && yClicked >= 552 && yClicked <= 594 ) loop = 0;
					
						break ;	

				}		


			}
			
			  /* Nettoyage du framebuffer */
       
    
        }
        
	return 0 ;
}








