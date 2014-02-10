#ifndef LDR_MONSTER___
#define LDR_MONSTER___

#include "game/map.h"
#include "game/point.h"
#include "game/player.h"



typedef enum type_monster {
	Vermine,
	Grouillant,
	Mastoc,
	Rampant
}type_monster;

typedef enum orientation {
	N,
	S,
	E,
	W
}orientation;

typedef struct monster_s {
	int num;
	type_monster type ;
	int def[4]; //tableau des resistance en fonction du type de tour
	point position;
	orientation o ;
	int vitesse;
	float nbPV;
	float PV ;

	struct monster_s* next ;
	struct monster_s* previous ;
}Monster;

void init_tab_monster(SDL_Surface** tab_sprite_monster);
point pointStart(Map *map); //Point de départ des monstres
point pointEnd(Map *map); //Point d'arrivé des monstres
orientation orientationStart(Map *map, point start); //Point de départ des monstres
void move(Monster **head, Map *map); //Déplacement d'un monstre
void moveMonsters(Monster **head, Map *map); //Déplacement des monstres
int isNode(point pt, Map *map); // renvoie l'indice du noeud trouvé, -1 sinon
orientation changeOrientation(point a, point b); // Redéfini l'orientation d'un monstre en fonction de deux points
char* displayImageMonster(Monster *monster);// OLD
int monsterEnd(Monster *monster, Map *map); //Renvoie 0 si le monstre est toujours sur la map, 1 sinon
int gameOver(Monster *monster, Map *map); //Renvoie 1 si la partie est finie, 0 sinon
void print_monsters(Monster *monster, SDL_Surface *tab_sprite_monster[], SDL_Surface *framebuffer); //Affiche les monstres
Monster* createMonster(Map *map, int vague, int num); // Crée un monstre
void createMonsters(Monster **head, Map *map, int nb_monster, int vague); // Crée une liste de monstres
void addMonster(Monster **head, Map *map, int vague); //Insère un monstre en queue
Monster* lastMonster(Monster *monster);
int rand_bornes(int a, int b);
char* monsterType(type_monster type); //Renvoie un char à partir du type enuméré
int is_dead(Monster** head, int nb_monstre, player* Player);
int is_monster(point X, point center) ;
Monster* select_monster(Monster** head, point X);
void clean_list_monster(Monster** head) ;
void print_info_monster(Monster* M, SDL_Surface *framebuffer, SDL_Surface *Monster);

#endif

