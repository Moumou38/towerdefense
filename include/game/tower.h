#ifndef LDR_TOWER___
#define LDR_TOWER___
#include "game/map.h"
#include "game/point.h"
#include "game/monster.h"
#include "game/player.h"


enum type_tower {rocket = 2, laser = 3, hybrid = 4, gun = 1};

typedef struct tower_s {
	int num ; //son numero
	int level;
	enum type_tower type ;
	point center;
	int range ; //portée
	int rate ; //cadence 
	int power ; //puissance
	int cost ; //prix
	int timer[10] ;
	
	struct tower_s* next ; 
	struct tower_s* previous ;
}tower;


void build (tower* head, point x, Map* M, int type, player* Player);
int buildable(point x, Map* M); //vérifie si le point x et ses environs sont constructibles (=1 )
tower* previous(tower* head);
tower* next(tower* head);
void print_info_tower(tower* head);
int can_attack(tower* head, Monster* M);
void print_tower(tower* head, SDL_Surface* tour1, SDL_Surface* tour2, SDL_Surface* tour3, SDL_Surface* tour4, SDL_Surface* framebuffer, SDL_Surface* screen);
void can_attack_list(tower* head, Monster* M, player* Player) ;
void select_tower_trace(point center, int range, SDL_Surface* framebuffer); //trace un cercle autour de la tour selectionnée
int is_tower(point X, point center) ; //vérifie s'il y a une tor à proximité du point X
tower* select_tower(tower* head, point X);
tower* delete_tower(tower* selected, tower* head) ; 
void attack(tower* head, Monster* M, player* Player) ;
void info_tower(tower* selected, SDL_Surface* tour, SDL_Surface* framebuffer) ;
tower* clean_tower_list(tower* head);
void print_cheat(int cheat, SDL_Surface* framebuffer);
void tower_cost(Map* M, SDL_Surface* framebuffer);
void upgrade_tower(tower* selected, player* Player) ;
#endif

