#ifndef LDR_PLAY___
#define LDR_PLAY___

int play_game(SDL_Surface* framebuffer, SDL_Surface* screen, char* map_itd, char* img_map);
int game_over(SDL_Surface* framebuffer, SDL_Surface* screen, int scorenb, int vague, int monster_quit);
int help(SDL_Surface* framebuffer, SDL_Surface* screen);
int pause() ;
#endif 
