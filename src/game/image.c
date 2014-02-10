#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game/image.h"



int open(Img* img, char* nom)
	{

	int cp = 0 ; // compteur pour la ligne de commentaire 
	char *str ; // utilisé pour la ligne de commentaire
	str = (char*)malloc(1*sizeof(char));
	FILE* file = NULL;
	file = fopen(nom,"r"); //droit de lecture
	
	if(file == NULL){
		return 0;
		}
	else {
		fscanf(file,"%c%c", &(img->var[0]), &(img->var[1])); //variante
			
			if (img->var[1] != '6') { //variante n'est pas P6 erreur à gérer
				return 0 ; 
			}
		
			
		do { 
			cp = fscanf(file,"%d %d",&(img->width), &(img->height));
				if (cp == 0) {  // on a une ligne de commentaire
					while(str[0] != '\n'){
						str = (char*)malloc(1*sizeof(Img));
						fread(str, 1, 1, file);
					}
				}
		} while(cp != 2);
		
		
		//valeur max
		fscanf(file,"%d \n", &(img->max));
		// On alloue la mémoire - attention il y a 3 octets par pixel
		(img->tabPixel) = (unsigned char*)malloc( ((img->height)*(img->width)*3) * sizeof(unsigned char)); 
		// On récupère tous les pixels dans le tableau tabPixel en faisant fread dans le reste du fichier
		fread (img->tabPixel, sizeof(unsigned char),(img->height)*(img->width)*3,file);	
		
		// vider le buffer et on ferme le fichier
		fflush(file);
		fclose(file);
		return 1;
		}
		
	}
	

