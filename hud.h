#ifndef _HUD_H_   /* Include guard */
#define _HUD_H_

#define MAX_CHARACTERS 2
#define MAX_POINTS 4
#include <allegro5/allegro5.h>  /*Utilizada para carregar o BITMAP do personagem*/
#include <allegro5/allegro_primitives.h> /*utilizada para o manipulamento dos objetos primitivos*/
#include "character.h"

#define LIFE_PLAYER_X1 22
#define LIFE_PLAYER_Y1 269
#define LIFE_PLAYER_X2 75
#define LIFE_PLAYER_Y2 273

typedef struct HUD{
	ALLEGRO_BITMAP *sprite;
	int life[MAX_POINTS][MAX_CHARACTERS];	
}HUD;

void load_hud(HUD *hud);
void draw_hud(HUD *hud,Character *character);


#endif 

