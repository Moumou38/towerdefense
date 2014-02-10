#ifndef LDR_BUTTON___
#define LDR_BUTTON___

#include "game/map.h"
#include "game/point.h"
#include "game/player.h"



typedef struct s_button{
	char *nom;
	point coord[4];
}Button;

void init_tab_Button(SDL_Surface** tab_sprite_button);
Button* addButton(char *nom, point coord, int width, int height);
int isButtonSelected(Button *button, int x, int y);
void deleteButton(Button *button);























#endif
