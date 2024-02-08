#include "hud.h" /*Biblioteca responsável pela manipulação dos HUDs*/


void load_hud(HUD *hud){
	
	/*Carrega as posições X e Y do personagem baseado no arquivo hud.png*/
	hud->life[0][0] = 8;
	hud->life[1][0] = 80;
	hud->life[2][0] = 157;
	hud->life[3][0] = 175;


}

void draw_hud(HUD *hud,Character *character){

        for(int i=0;i<MAX_CHARACTERS;i++){
                al_draw_tinted_bitmap_region(hud->sprite,al_map_rgba_f(0, 0, 0.7, 0.8),
                                hud->life[0][i], hud->life[2][i],
                                hud->life[1][i] - hud->life[0][i],hud->life[3][i] - hud->life[2][i],
                                5,260,0);
        }
	
	/*Verificação para impedir que impressao fica inversa*/
	if(character->damage <= (LIFE_PLAYER_X2 - LIFE_PLAYER_X1))
		/*Imprime a vida*/
		al_draw_filled_rectangle(LIFE_PLAYER_X1,LIFE_PLAYER_Y1,
				 LIFE_PLAYER_X2 - character->damage,LIFE_PLAYER_Y2,
				 al_map_rgba_f(1,0,0,0.8));
	else{	
		/*Impede a impressao inversa da vida*/
		character->damage=0;
	}

	/*Barra de vida diminui gradativamente -- Propósitos de TESTE somente*/
	character->damage = character->damage + 0.02;


}
