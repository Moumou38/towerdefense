#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "game/map.h"

int open_map(Map* map, char* filename) {
	if (map == NULL) {
		printf("La carte est vide\n");
		return 0;
	}
	
	FILE* file = NULL;
	file = fopen(filename, "r"); //droits de lecture
	if(file == NULL){
		printf("Le fichier .itd est vide\n");
		return 0;
	}
	else {
		const char* valid_type = "@ITD";
		char* actual_type = (char*)malloc(sizeof(char)*10);
		fscanf(file, "%s %d", actual_type, &(map->version)); //Type de la carte : ITD 1 ou ITD 2
		if (strcmp (actual_type, valid_type) !=  0) {
			printf("La carte n'est pas au format ITD\n");
			return 0;
		}
		
		if (map->version == 1 || map->version == 2) {
			int total_lines = count_lines(filename);
			if (total_lines < 10) {
				printf("Nombre de lignes du fichier .itd incorrect\n");
				return 0;
			}
			else if (total_lines < 26 && map->version == 2) {
				printf("Nombre de lignes du fichier .itd version 2 incorrect\n");
				return 0;
			}
			
			char* filename_image = (char*)malloc(sizeof(char)*20);
			fscanf(file, "%s", filename_image); //On récupère le nom de l'image image.ppm
			
			char path_image[40] = "././images/";
			strcat(path_image, filename_image); //On écrit le chemin complet vers l'image
		
			map->image = (Img*)malloc(sizeof(Img)); //On alloue l'image
			if (map->image == NULL) {
				printf("Impossible d'allouer l'image pour la map\n");
				return 0;
			}
			
			if (open(map->image, path_image) == 0) { //On ouvre l'image
				printf("Impossible d'ouvrir l'image\n");
				return 0;
			}
			
			char* keyword = (char*)malloc(sizeof(char)*20);
			
			fscanf(file, "%s %hhu %hhu %hhu", keyword, &(map->path.r), &(map->path.g), &(map->path.b)); //Couleur des chemins
			if (strcmp (keyword, "chemin") != 0) {
				printf("keyword : %s\n", keyword);
				printf("Carte .itd invalide (chemin)\n");
				return 0;
			}
			
			fscanf(file, "%s %hhu %hhu %hhu", keyword, &(map->node.r), &(map->node.g), &(map->node.b)); //Couleur des noeuds
			if (strcmp (keyword, "noeud") != 0) {
				printf("Carte .itd invalide\n");
				return 0;
			}
			
			fscanf(file, "%s %hhu %hhu %hhu", keyword, &(map->buildable.r), &(map->buildable.g), &(map->buildable.b)); //Couleur des zones constructibles
			if (strcmp (keyword, "construct") != 0) {
				printf("Carte .itd invalide\n");
				return 0;
			}
			
			fscanf(file, "%s %hhu %hhu %hhu", keyword, &(map->in.r), &(map->in.g), &(map->in.b)); //Couleur de l'entrée
			if (strcmp (keyword, "in") != 0) {
				printf("Carte .itd invalide\n");
				return 0;
			}
			
			fscanf(file, "%s %hhu %hhu %hhu", keyword, &(map->out.r), &(map->out.g), &(map->out.b)); //Couleur de la sortie
			if (strcmp (keyword, "out") != 0) {
				printf("Carte .itd invalide\n");
				return 0;
			}
						
			if (map->version == 2) {				
				//Puissance
				fscanf(file, "%s %u", keyword, &(map->powerR));
				if (strcmp (keyword, "powerR") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->powerL));
				if (strcmp (keyword, "powerL") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->powerM));
				if (strcmp (keyword, "powerM") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->powerH));
				if (strcmp (keyword, "powerH") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				
				//Cadence des tours
				fscanf(file, "%s %u", keyword, &(map->rateR));
				if (strcmp (keyword, "rateR") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rateL));
				if (strcmp (keyword, "rateL") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rateM));
				if (strcmp (keyword, "rateM") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rateH));
				if (strcmp (keyword, "rateH") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				
				//Portée des tours
				fscanf(file, "%s %u", keyword, &(map->rangeR));
				if (strcmp(keyword, "rangeR") != 0) {
					printf("Carte .itd version 2 invalide R\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rangeL));
				if (strcmp (keyword, "rangeL") != 0) {
					printf("Carte .itd version 2 invalide M\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rangeM));
				if (strcmp (keyword, "rangeM") != 0) {
					printf("Carte .itd version 2 invalide L\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->rangeH));
				if (strcmp (keyword, "rangeH") != 0) {
					printf("Carte .itd version 2 invalide H\n");
					return 0;
				}
				
				//Coût d'achat
				fscanf(file, "%s %u", keyword, &(map->costR));
				if (strcmp (keyword, "costR") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->costL));
				if (strcmp (keyword, "costL") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->costM));
				if (strcmp (keyword, "costM") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
				fscanf(file, "%s %u", keyword, &(map->costH));
				if (strcmp (keyword, "costH") != 0) {
					printf("Carte .itd version 2 invalide\n");
					return 0;
				}
			}
			
			fscanf(file, "%d", &(map->nb_node));
			
			if (map->version == 1 && total_lines - 8 != map->nb_node) {
				printf("Les coordonnées des noeuds sont incorrectes\n");
				return 0;
			}
			else if (map->version == 2 && total_lines - 24 != map->nb_node){
				printf("Les coordonnées des noeuds sont incorrectes\n");
				return 0;
			}
			
			map->node_array = (point*)malloc(map->nb_node * sizeof(point)); //Tableau de points qui contiendra les coordonnées des noeuds
			int i;
			for (i = 0; i < map->nb_node; i++) { //Récupère tous les points
				fscanf(file, "%d %d", &(map->node_array[i].x), &(map->node_array[i].y));
			}
			
			//On vérifie si les noeuds sont de la bonne couleur
			int largeur = map->image->width;
			int j;
			for (j = 0; j < map->nb_node; j++) {
				int x = (int)map->node_array[j].x;
				int y = (int)map->node_array[j].y;
				if (map->image->tabPixel[3 * (largeur * y + x) + 0] != map->node.r ||
					map->image->tabPixel[3 * (largeur * y + x) + 1] != map->node.g ||
					map->image->tabPixel[3 * (largeur * y + x) + 2] != map->node.b){
						printf("Les coordonnées des noeuds sont incorrectes\n");
						return 0;
				}
			}
		}
		else {
			printf("Le fichier .itd doit etre de version 1 ou 2\n");
		}
		
		print_info_map(map);
		
		//On vide le buffer et on ferme le fichier
		fflush(file);
		fclose(file);
		return 1;
		}
	return 1;
}

void print_info_map(Map* map) {
	printf("------- Infos de la carte -------\n\n");
	
	printf("VERSION\n\tITD %d\n\n", map->version);
	
	printf("COULEURS CLES\n");
		printf("\t- Chemins : %u %u %u\n", map->path.r, map->path.g, map->path.b);
		printf("\t- Noeuds : %u %u %u\n", map->node.r, map->node.g, map->node.b);
		printf("\t- Zones constructibles : %u %u %u\n", map->buildable.r, map->buildable.g, map->buildable.b);
		printf("\t- Entrée : %u %u %u\n", map->in.r, map->in.g, map->in.b);
		printf("\t- Sortie : %u %u %u\n\n", map->out.r, map->out.g, map->out.b);
	
	if (map->version == 2) {
		printf("CARACTERISTIQUES DES TOURS\n");
		printf("\t- Rocket : puissance %u, cadence %u, portée %u, coût d'achat %u\n\n", map->powerR, map->rateR, map->rangeR, map->costR);
		printf("\t- Laser : puissance %u, cadence %u, portée %u, coût d'achat %u\n\n", map->powerL, map->rateL, map->rangeL, map->costL);
		printf("\t- Mitraillette : puissance %u, cadence %u, portée %u, coût d'achat %u\n\n", map->powerM, map->rateM, map->rangeM, map->costM);
		printf("\t- Hybride : puissance %u, cadence %u, portée %u, coût d'achat %u\n\n", map->powerH, map->rateH, map->rangeH, map->costH);
	}
	
	printf("NOEUDS\n");
		printf("\t- Nombre de noeuds : %d\n", map->nb_node);
		printf("\t- Coordonnées des noeuds :\n");
		int j;
		for (j = 0; j < map->nb_node; j++) {
			printf("\t\t%d/ (%d, %d)\n", j+1, map->node_array[j].x, map->node_array[j].y);
		}
		printf("\n");
	
	printf("--- Fin des infos de la carte ---\n\n");
}

int count_lines(char* filename) {
	FILE* file = NULL;
	file = fopen(filename, "r"); //droits de lecture
	if(file == NULL){
		printf("Le fichier est vide\n");
		return 0;
	}
	
	int lines = 0; 
	int current_char = 0; 
	int tmp = 0; //Permet de vérifier si la ligne comporte juste un "\n"
	while((current_char = fgetc(file)) != EOF) 
	{
		if(current_char == '\n' && tmp == 1) 
		{ 
			lines++;
			tmp = 0;
		}
		else {
			tmp = 1;
		}
	}
		
	//On vide le buffer et on ferme le fichier
	fflush(file);
	fclose(file);
	
	return lines;
}
