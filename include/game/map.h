#ifndef LDR_MAP___
#define LDR_MAP___

#include "image.h"
#include "point.h"
#include "color3f.h"

typedef struct map_s {
	int version; //1 ou 2
	Img* image; //Carte image.ppm
	
	Color3f path; //Couleur clé des chemins dans l'image
	Color3f node; //Couleur clé des noeuds
	Color3f buildable; //Couleur clé des zones 'constructibles'
	Color3f in; //Couleur clé de la zone d'entrée
	Color3f out; //Couleur clé de la zone de sortie
	
	unsigned int powerR; //Puissance pour les tours de type X (X à remplacer par R (rocket) L (laser), M (mitraillette) et H (hybride))
	unsigned int powerL;
	unsigned int powerM;
	unsigned int powerH;
	
	unsigned int rateR; //Cadence pour les tours de type X (R,L,M,H)
	unsigned int rateL;
	unsigned int rateM;
	unsigned int rateH;
	
	unsigned int rangeR; //Portée pour les tours de type X (R,L,M,H)
	unsigned int rangeL;
	unsigned int rangeM;
	unsigned int rangeH;
	
	unsigned int costR; //Coût d’achat des tours de type X (R,L,M,H)
	unsigned int costL;
	unsigned int costM;
	unsigned int costH;
	
	int nb_node; //Nombre de noeuds
	point* node_array; //Tableau des noeuds
} Map;

int open_map(Map* map, char* filename); //Ouvre une carte

void print_info_map(Map* map); //Affiche les infos d'une carte

int count_lines(char* filename); //Compte le nombre de lignes d'un fichier

#endif

