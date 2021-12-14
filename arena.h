#ifndef LIB_H_   /* Include guard */
#define LIB_H_

#define MAX_LEVELS  3		/*Essa fase possui 3 plataformas de solo firme*/
#define MAX_BORDERS 2		/*Borda da esquerda e direita*/
#define DIMENSION   2		/*X e Y*/

#define LIMITE_ESQUERDA 0	/*Macro para facilitar a legibilidade do código*/
#define LIMITE_DIREITA  1

#define QUEDA_POR_FRAME 4	/*Indica a força da gravidade por frame*/

#include "character.h"
typedef struct battle_arena{

		int levels[MAX_LEVELS][MAX_BORDERS][DIMENSION];	 /*Matriz de 3 dimensão para armazenar os valores de solo firme*/
		int limitFalling;				 /*Indica qual a posição máxima no eixo Y que o personagem pode cair*/
		ALLEGRO_BITMAP *sprite;				 /*Armazena o sprite*/
		
}Arena;

/*Carregar valores (x,y) da arena*/
void load_arena(Arena *arena);
/*Função responsável por aplicar gravidade aos personagens*/
void gravity(Character *character,Arena *arena);
/*Verificar se o personagem está em solo firme, olhando somente na dimensão X*/
bool verify_position_X(int PositionCharacter, int limiteEsquerdaArena, int limiteDireitaArena);
/*Verificar se o personagem está em solo firme, olhando somente na dimensão Y*/
bool verify_position_Y(int PositionCharacter, int limiteInferiorArena);


#endif // LIB_H_
