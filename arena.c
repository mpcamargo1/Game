#include "arena.h"       /*Headers do arquivo arena.c*/

void load_arena(Arena *arena){

	/*Limite da Posição Y da queda*/
	arena->limitFalling=480;

	/*Berolinha do primeiro nível -- Esquerda*/
	arena->levels[0][LIMITE_ESQUERDA][X] = 131;
	arena->levels[0][LIMITE_ESQUERDA][Y] = 218;

	/*Berolinha do primeiro nível -- Direita*/
	arena->levels[0][LIMITE_DIREITA][X] = 580;
	arena->levels[0][LIMITE_DIREITA][Y] = 218;

	/*Berolinha do segundo nível -- Esquerda*/

	arena->levels[1][LIMITE_ESQUERDA][X] = 186;
	arena->levels[1][LIMITE_ESQUERDA][Y] = 154;

	/*Berolinha do segundo nível -- Direita*/

	arena->levels[1][LIMITE_DIREITA][X] = 310;
	arena->levels[1][LIMITE_DIREITA][Y] = 154;

	/*Berolinha do terceiro nível -- Esquerda*/

	arena->levels[2][LIMITE_ESQUERDA][X] = 404;
	arena->levels[2][LIMITE_ESQUERDA][Y] = 154;

	/*Berolinha do terceiro nível -- Direita*/
	arena->levels[2][LIMITE_DIREITA][X] = 522;
	arena->levels[2][LIMITE_DIREITA][Y] = 154;

}

/*Lida com a gravidade do personagem*/
void gravity(Character *character,Arena *arena){

	
	if((character->state == FALLING  || character->state == FALLING_FIRE) && character->Position[Y] < arena->limitFalling){
		character->Position[Y]+=QUEDA_POR_FRAME;                /*Posição do personagem cai de acordo com o valor QUEDA_POR_FRAME*/
			if(++character->FrameJumpingAnimation > 59)	/*Incrementa o valor do FrameJumpingAnimation e verifica a sentença. Caso o FrameJumpingAnimation for maior que 59 -- FrameJumpingAnimation controla a animação da queda -- Nesse caso, 59 significa a sexta animação*/
				character->FrameJumpingAnimation=0;     /*Animação é resetada*/

		/*Detectar se o personagem encontra-se em solo firme*/
		for(int i=0;i<MAX_LEVELS;i++){
			if(verify_position_X(character->Position[X],arena->levels[i][LIMITE_ESQUERDA][X],arena->levels[i][LIMITE_DIREITA][X]) && verify_position_Y(character->Position[Y],arena->levels[i][LIMITE_ESQUERDA][Y])){

			 	character->state=IDLE; 						/*O estado personagem é IDLE (Pois ele está em solo firme)*/
				character->Position[Y]=arena->levels[i][LIMITE_ESQUERDA][Y];    /*Ajusta a posição do personagem para ficar com a posição Y correta*/
				character->currentLevel=i;					/*Indica qual é o nível atual do personagem*/
				character->FrameJumpingAnimation=0;				/*FrameJumpingAnimation é resetada */

				break; /*Sai do laço FOR -- É uma gambiarra -- Será reescrito posteriormente (Sugestão -- Utilizar While)*/
			}
		}
	}
	/*Caso o personagem passou dos limites da fase caindo*/
	else if(character->Position[Y] > arena->limitFalling){
		initializePosition(character);			/*Coloca o personagem na posição atual*/
	}
	/*Caso o personagem não estiver caindo, verificar se a está em pisando em solo firme*/
	else if (character->state == IDLE || character->state == RUNNING || character->state == RUNNING_FIRE){
			/*verify_position_X retorna verdadeiro se o personagem está no intervalo X do chão*/
			/*Nessa caso, para verificar se está caindo, a função retorna FALSE. Portanto, se estiver caindo, !verify_position_X é verdadeiro*/
			/* '!' é o operador de negação -- Propriedade da lógica: !(FALSE) = TRUE*/
			if(!verify_position_X(character->Position[X],arena->levels[character->currentLevel][LIMITE_ESQUERDA][X],arena->levels[character->currentLevel][LIMITE_DIREITA][X])){
				character->state = FALLING;	/*Atualiza o estado personagem (CAINDO)*/
			}
		
	}

}

/*Verifica se o personagem está solo firme (Olha apenas a dimensão Y) -- TRUE -> SIM -- FALSE -> NÃO*/
bool verify_position_Y(int PositionCharacter, int limiteInferiorArena){

	if(PositionCharacter >= limiteInferiorArena && PositionCharacter<= limiteInferiorArena + QUEDA_POR_FRAME)
		return true;
	else
		return false;

}

/*Verifica se o personagem está em solo firme (Olha apenas a dimensão X) -- TRUE-> SIM -- FALSE -> NÃO*/
bool verify_position_X(int PositionCharacter, int limiteEsquerdaArena, int limiteDireitaArena){

	if(PositionCharacter < limiteEsquerdaArena || PositionCharacter > limiteDireitaArena){
		return false;
	}
	else
		return true;

}
