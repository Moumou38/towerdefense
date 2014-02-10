#ifndef LDR_IMAGE___
#define LDR_IMAGE___


typedef struct structure_image 
	{
	// type de variante entre 1 et 6
	char var[2];
	// Hauteur et largeur
	unsigned int height;
	unsigned int width;
	// Valeur maximale
	int max;
	// Valeur des pixels unsigned char va de 0 à 255
	unsigned char* tabPixel; //taille à multiplier par 3 pour chaque couleur
}Img;

int open(Img* img, char* nom);


#endif
