#ifndef LIB_H_   /* Include guard */
#define LIB_H_

#define MAX_CHARACTERS 2
#include <allegro5/allegro5.h>  /*Bilbioteca utilizada para carregar o BITMAP do personagem*/
typedef struct hud{
	ALLEGRO_BITMAP *life[MAX_CHARACTERS];
	
}HUD;





#endif // LIB_H_

