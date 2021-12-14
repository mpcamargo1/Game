#ifndef LIB_H
#define LIB_H

/*Macros*/
#define X           0
#define Y           1
#define MAX_POINTS  4
#define MAX_ANIM    20
#define MAX_STATES  20
#define MAX_FIRE    5
#define VELOCIDADE_BULLET	4

/*Bibliotecas*/
#include <stdbool.h>  		/*Biblioteca para utilizar valores booleanos*/
#include <allegro5/allegro5.h>  /*Bilbioteca utilizada para carregar o BITMAP do personagem*/

enum CHARACTER_STATE {IDLE,RUNNING,JUMPING,FALLING,JUMPING_FIRE,FALLING_FIRE,RUNNING_FIRE};

/*Estrutura de dados dos tiros*/
typedef struct bulletChar{
	/*Controlador de Animação*/
	int FrameShotAnimation;

	/*Matrizes de Animação*/
	int ShotAnimation[MAX_POINTS][MAX_ANIM];

	/*Timeout dos tiros*/
	int delayShot;
	/*Posição X e Y do tiro*/
	int  position_X[MAX_FIRE];
	int  position_Y[MAX_FIRE];

	int direction[MAX_FIRE];

	/*Booleano que armazena se o tiro está visível na tela*/
	bool active[MAX_FIRE];
	
}bulletChar;

/*Estrutura de dados do personagem*/
typedef struct character{
	/*Posição atual do personagem*/
	int Position[2];
	/*Direção do personagem -- 0 -> Direita | 45 -> Esquerda*/
	int Direction;

	/*Controladores de Animação*/
	float FrameRunningAnimation;
	float FrameRunningShotAnimation;
	float FrameIdlingAnimation;
	int FrameJumpingAnimation;
	int FrameJumpingShotAnimation;

	int MirroredOffset;

	/*Armazena o nível(chão) que o personagem está*/
	int currentLevel;

	/*Matrizes de Animação -- Contém posição(x,y) de cada bitmap da animação*/
	int RunningAnimation[MAX_POINTS][MAX_ANIM];
	int RunningShotAnimation[MAX_POINTS][MAX_ANIM];
	int IdlingAnimation[MAX_POINTS][MAX_ANIM];
	int JumpingAnimation[MAX_POINTS][MAX_ANIM];
	int JumpingShotAnimation[MAX_POINTS][MAX_ANIM];

	/*Booleano que armazena se o usuário pressionou um botão*/
	bool KeyPressed;

	/*Armazena o estado do personagem*/
	enum CHARACTER_STATE state;

	/*Estrutura do Allegro para carregar um bitmap*/
	ALLEGRO_BITMAP *sprite;
	
	bulletChar fires;
	
}Character;


/*Declaração das funções utilizadas em character.c*/

/*Inicializa a posição do personagem*/
void initializePosition(Character *character);
/*Carrega os valores(x,y) de cada bitmap nas matrizes de animação*/
void load_character(Character *character);
/*Função que lida com o movimento de corrida do personagem*/
void RunningRight(Character *character);
/*Função que lida com o movimento de corrida do personagem*/
void RunningLeft(Character *character);
/*Função que lida com o repouso do personagem*/
void Idling(Character *character);
/*Função que lida com o pulo do personagem*/
void Jumping(Character *character,bool upPressed);
/*Função que lida com o tiro do personagem*/
void Firing(Character *character);
/*Função que lida com despromoção de estados*/
void depromove(Character *character);
/*Verifica se o estado do personagem é pode voltar para IDLE*/
bool verifyIdle(Character *character);
/*Verifica se os tiros estão na tela*/
bool verifyBullet(Character *character);
/*Aplica movimento ao tiro*/
void moveBullet(Character *character);

#endif // LIB_H_
