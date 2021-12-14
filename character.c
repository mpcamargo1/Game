/*Bibliotecas*/
#include "character.h"  /*Biblioteca do personagem*/

/*Inicializa as posições*/
void initializePosition(Character *character){
	/*Essa posição é posição do chão NIVEL 0 -- VIDE arena.c na função load_arena*/
	character->Position[X]=200;
	character->Position[Y]=218;
}

void load_character(Character *character){
	/*Configura as variáveis de controle*/
	character->Direction=0;			/*Personagem olhando para a direita*/
	character->FrameRunningAnimation=0;
	character->FrameIdlingAnimation=0;
	character->FrameJumpingAnimation=0;
	character->FrameJumpingShotAnimation=0;
	character->MirroredOffset=0;
	character->state=IDLE;			/*Atualiza o estado do personagem*/
	character->currentLevel=0;
	character->fires.delayShot=0;
	character->fires.FrameShotAnimation=0;

	/*Running Animation*/
	character->RunningAnimation[0][0] = 314;
	character->RunningAnimation[1][0] = 344;
	character->RunningAnimation[2][0] = 15;
	character->RunningAnimation[3][0] = 49;

	character->RunningAnimation[0][1] = 345;
	character->RunningAnimation[1][1] = 365;
	character->RunningAnimation[2][1] = 15;
	character->RunningAnimation[3][1] = 49;

	character->RunningAnimation[0][2] = 366;
	character->RunningAnimation[1][2] = 389;
	character->RunningAnimation[2][2] = 14;
	character->RunningAnimation[3][2] = 49;

	character->RunningAnimation[0][3] = 389;
	character->RunningAnimation[1][3] = 421;
	character->RunningAnimation[2][3] = 15;
	character->RunningAnimation[3][3] = 49;

	character->RunningAnimation[0][4] = 421;
	character->RunningAnimation[1][4] = 455;
	character->RunningAnimation[2][4] = 15;
	character->RunningAnimation[3][4] = 49;

	character->RunningAnimation[0][5] = 455;
	character->RunningAnimation[1][5] = 481;
	character->RunningAnimation[2][5] = 15;
	character->RunningAnimation[3][5] = 49;

	character->RunningAnimation[0][6] = 484;
	character->RunningAnimation[1][6] = 506;
	character->RunningAnimation[2][6] = 15;
	character->RunningAnimation[3][6] = 49;

	character->RunningAnimation[0][7] = 506;
	character->RunningAnimation[1][7] = 531;
	character->RunningAnimation[2][7] = 14;
	character->RunningAnimation[3][7] = 49;

	character->RunningAnimation[0][8] = 534;
	character->RunningAnimation[1][8] = 563;
	character->RunningAnimation[2][8] = 15;
	character->RunningAnimation[3][8] = 49;

	character->RunningAnimation[0][9] = 565;
	character->RunningAnimation[1][9] = 599;
	character->RunningAnimation[2][9] = 16;
	character->RunningAnimation[3][9] = 49;

	character->RunningAnimation[0][10] = 599;
	character->RunningAnimation[1][10] = 628;
	character->RunningAnimation[2][10] = 16;
	character->RunningAnimation[3][10] = 49;

	/*IdlingAnimation*/

	character->IdlingAnimation[0][0] = 208;
	character->IdlingAnimation[1][0] = 238;
	character->IdlingAnimation[2][0] = 14;
	character->IdlingAnimation[3][0] = 48;

	character->IdlingAnimation[0][1] = 242;
	character->IdlingAnimation[1][1] = 272;
	character->IdlingAnimation[2][1] = 14;
	character->IdlingAnimation[3][1] = 48;

	character->IdlingAnimation[0][2] = 276;
	character->IdlingAnimation[1][2] = 306;
	character->IdlingAnimation[2][2] = 14;
	character->IdlingAnimation[3][2] = 48;

	/*JumpingAnimation*/

	character->JumpingAnimation[0][0] = 0;
	character->JumpingAnimation[1][0] = 24;
	character->JumpingAnimation[2][0] = 69;
	character->JumpingAnimation[3][0] = 106;

	character->JumpingAnimation[0][1] = 29;
	character->JumpingAnimation[1][1] = 44;
	character->JumpingAnimation[2][1] = 65;
	character->JumpingAnimation[3][1] = 106;

	character->JumpingAnimation[0][2] = 50;
	character->JumpingAnimation[1][2] = 69;
	character->JumpingAnimation[2][2] = 60;
	character->JumpingAnimation[3][2] = 106;

	character->JumpingAnimation[0][3] = 72;
	character->JumpingAnimation[1][3] = 95;
	character->JumpingAnimation[2][3] = 65;
	character->JumpingAnimation[3][3] = 106;

	character->JumpingAnimation[0][4] = 97;
	character->JumpingAnimation[1][4] = 124;
	character->JumpingAnimation[2][4] = 64;
	character->JumpingAnimation[3][4] = 106;

	character->JumpingAnimation[0][5] = 129;
	character->JumpingAnimation[1][5] = 153;
	character->JumpingAnimation[2][5] = 68;
	character->JumpingAnimation[3][5] = 106;

	/*
	character->JumpingAnimation[0][6] = 154;
	character->JumpingAnimation[1][6] = 184;
	character->JumpingAnimation[2][6] = 74;
	character->JumpingAnimation[3][6] = 106;
	*/

	/*JumpingShotAnimation*/

	character->JumpingShotAnimation[0][0] = 0;
	character->JumpingShotAnimation[1][0] = 29;
	character->JumpingShotAnimation[2][0] = 117;
	character->JumpingShotAnimation[3][0] = 154;

	character->JumpingShotAnimation[0][1] = 30;
	character->JumpingShotAnimation[1][1] = 55;
	character->JumpingShotAnimation[2][1] = 113;
	character->JumpingShotAnimation[3][1] = 154;

	character->JumpingShotAnimation[0][2] = 55;
	character->JumpingShotAnimation[1][2] = 82;
	character->JumpingShotAnimation[2][2] = 108;
	character->JumpingShotAnimation[3][2] = 154;

	character->JumpingShotAnimation[0][3] = 83;
	character->JumpingShotAnimation[1][3] = 114;
	character->JumpingShotAnimation[2][3] = 113;
	character->JumpingShotAnimation[3][3] = 154;

	character->JumpingShotAnimation[0][4] = 115;
	character->JumpingShotAnimation[1][4] = 146;
	character->JumpingShotAnimation[2][4] = 112;
	character->JumpingShotAnimation[3][4] = 154;

	character->JumpingShotAnimation[0][5] = 147;
	character->JumpingShotAnimation[1][5] = 177;
	character->JumpingShotAnimation[2][5] = 116;
	character->JumpingShotAnimation[3][5] = 154;

	/*
	character->JumpingShotAnimation[0][6] = 177;
	character->JumpingShotAnimation[1][6] = 213;
	character->JumpingShotAnimation[2][6] = 122;
	character->JumpingShotAnimation[3][6] = 154;
	*/
	
	
	/*RunningShotAnimation*/
	character->RunningShotAnimation[0][0] = 285;
	character->RunningShotAnimation[1][0] = 314;
	character->RunningShotAnimation[2][0] = 67;
	character->RunningShotAnimation[3][0] = 101;
	
	character->RunningShotAnimation[0][1] = 314;
	character->RunningShotAnimation[1][1] = 346;
	character->RunningShotAnimation[2][1] = 66;
	character->RunningShotAnimation[3][1] = 101;
	
	character->RunningShotAnimation[0][2] = 346;
	character->RunningShotAnimation[1][2] = 381;
	character->RunningShotAnimation[2][2] = 67;
	character->RunningShotAnimation[3][2] = 101;
	
	character->RunningShotAnimation[0][3] = 382;
	character->RunningShotAnimation[1][3] = 420;
	character->RunningShotAnimation[2][3] = 68;
	character->RunningShotAnimation[3][3] = 101;
	
	character->RunningShotAnimation[0][4] = 421;
	character->RunningShotAnimation[1][4] = 455;
	character->RunningShotAnimation[2][4] = 68;
	character->RunningShotAnimation[3][4] = 101;
	
	character->RunningShotAnimation[0][5] = 455;
	character->RunningShotAnimation[1][5] = 486;
	character->RunningShotAnimation[2][5] = 67;
	character->RunningShotAnimation[3][5] = 101;
	
	character->RunningShotAnimation[0][6] = 486;
	character->RunningShotAnimation[1][6] = 519;
	character->RunningShotAnimation[2][6] = 66;
	character->RunningShotAnimation[3][6] = 101;
	
	character->RunningShotAnimation[0][7] = 519;
	character->RunningShotAnimation[1][7] = 554;
	character->RunningShotAnimation[2][7] = 68;
	character->RunningShotAnimation[3][7] = 101;
	
	character->RunningShotAnimation[0][8] = 555;
	character->RunningShotAnimation[1][8] = 592;
	character->RunningShotAnimation[2][8] = 69;
	character->RunningShotAnimation[3][8] = 101;
	
	character->RunningShotAnimation[0][9] = 592;
	character->RunningShotAnimation[1][9] = 627;
	character->RunningShotAnimation[2][9] = 68;
	character->RunningShotAnimation[3][9] = 101;

	/*ShotAnimation*/

	character->fires.ShotAnimation[0][0] = 211;
	character->fires.ShotAnimation[1][0] = 251;
	character->fires.ShotAnimation[2][0] = 364;
	character->fires.ShotAnimation[3][0] = 383;

	character->fires.ShotAnimation[0][1] = 260;
	character->fires.ShotAnimation[1][1] = 296;
	character->fires.ShotAnimation[2][1] = 364;
	character->fires.ShotAnimation[3][1] = 386;

}

void RunningRight(Character *character){
	/*Configura as variáveis de controle*/
	character->KeyPressed=true;
	character->Direction=0;
	character->MirroredOffset=0;

	switch(character->state){
		case RUNNING:
		case RUNNING_FIRE:
				character->FrameRunningAnimation+=0.25;		/*FrameJumpingAnimation é incrementado*/
				character->Position[X]+=2;			/*Posição no eixo X é incrementado em duas unidades*/
				break;
		case IDLE:
				character->state=RUNNING;			/*Atualiza o estado do personagem para correndo*/
				character->FrameRunningAnimation=0;		/*Reseta a animação da corrida*/
				character->FrameRunningAnimation+=0.25;		/*Incrementa a animação da corrida*/
				character->Position[X]+=2;			/*Incrementa a posição em duas unidades*/
				break;
		case FALLING:
		case JUMPING:
		case JUMPING_FIRE:
		case FALLING_FIRE:
				character->Position[X]+=2;			/*Caso o estado do personagem for CAINDO ou PULANDO, incrementa a posição dele em duas unidades*/
				break;
	}

	/*Controlador da animação de corrida*/
	if(character->FrameRunningAnimation>10)					/*Caso o FrameRunningAnimation for maior que 10 -- A corrida tem 11 animações*/
		character->FrameRunningAnimation=5;				/*Seta o FrameRunningAnimation para 5 -- FrameRunningAnimation atua como índice*/

}

void RunningLeft(Character *character){
	/*Configura as variáveis de controle*/
	character->KeyPressed=true;		/*Indica que o usuário apertou o botão*/
	character->Direction=45;		/*Personagem olhando para a esquerda*/
	character->MirroredOffset=8;

	/*Verifica o estado do personagem*/
	switch(character->state){
		case RUNNING:
		case RUNNING_FIRE:
				character->FrameRunningAnimation+=0.25;		/*FrameRunningAnimation é incrementado*/
				character->Position[X]-=2;			/*Posição do personagem é decrementado*/
				break;
		case IDLE:
				character->state=RUNNING;			/*Atualiza o estado do personagem para CORRENDO*/
				character->FrameRunningAnimation=0;		/*Reseta o valor do FrameJumpingAnimation*/
				character->FrameRunningAnimation+=0.25;		/*Incrementa o valor do FrameJumpingAnimation*/
				character->Position[X]-=2;			/*Posição do personagem é decrementado em duas unidades*/
				break;
		case FALLING:
		case JUMPING:
		case FALLING_FIRE:
		case JUMPING_FIRE:
				character->Position[X]-=2;		       /*Caso o estado do personagem for CAINDO ou PULANDO, sua posição é decrementado em duas unidades*/
				break;
	}

	if(character->FrameRunningAnimation>10)					/*Caso o FrameRunningAnimation for maior que 10 -- A corrida tem 11 animações*/
	     character->FrameRunningAnimation=5;				/*Seta o FrameRunningAnimation para 5 -- FrameRunningAnimation atua como índice*/

}

void Idling(Character *character){

	character->FrameRunningAnimation=0;


	/*Se o estado do personagem anteriormente for RUNNING -- Força a animação do idling começar do início*/
	if(character->state==RUNNING || character->state==RUNNING_FIRE)
		character->FrameIdlingAnimation=0;

	character->state=IDLE; 				/*Manutenção ou atualização do estado de IDLE do personagem*/

	character->FrameIdlingAnimation+=0.02;		/*FrameIdlingAnimation é incrementado*/
	if(character->FrameIdlingAnimation>2)		/*FrameIdlingAnimation possui 3 animações -- Caso for maior que 2 -- FrameIdlingAnimation atua como índice*/
		character->FrameIdlingAnimation=0;	/*FrameIdlingAnimation é resetado*/

}

void Jumping(Character *character,bool upPressed){

	character->KeyPressed=true;			/*Indica que o usuário teclou -- CÓDIGO QUEBRADO NESSA LINHA, POIS NEM SEMPRE ISSO É VERDADE -- RESTOS MORTAIS DE UMA VERSÃO ANTERIOR -- CONSERTAR*/

	/*upPressed = TRUE - Significa que o usuário apertou UP*/
	/*Caso o estado do personagem for CORRENDO OU IDLE e botão de pulo foi apertado*/
	if(upPressed == true && (character->state==RUNNING || character->state==IDLE || character->state==RUNNING_FIRE)){
		character->FrameJumpingAnimation+=1;		/*Incrementa o valor de FrameJumpingAnimation -- IMPORTANTE: FrameJumpingAnimation possui valor INTEIRO*/
		character->Position[Y]-=4;			/*Posição é decrementada (Decrementar em Y possui ação de subir)*/
		character->state=JUMPING;			/*Atualiza o estado do personagem*/
	}
	/*Esta é a parte do código responsável por lidar com o resto da animação do pulo*/
	/*É executada, automaticamente, a cada frame -- VIDE game.c*/
	/*FrameJumpingAnimation > 0 indica que a animação já começou*/
	/*upPressed = FALSE - Significa que o usuário já realizou o movimento do pulo*/
	/*character->state = JUMPING - O estado do personagem é pulando*/
	else if(character->FrameJumpingAnimation > 0 && upPressed == false){
		character->FrameJumpingAnimation+=1;

		/*Caso FrameJumpingAnimation for menor que a metade das animações*/
		if(character->FrameJumpingAnimation < 30){
			character->Position[Y]-=4;	/*A posição é decrementada -- Decrementar a posição no eixo Y corresponde a subir*/
			//fprintf(stderr,"Down -- %d\n",character->FrameJumpingAnimation);
		}
		else{
			/*Significa que o pulo do personagem chegou na metade, ou seja, agora é necessário cair*/
			/*Para isso, atualiza o estado do personagem para FALLING*/
			/*A função de gravidade lida com o resto*/
			character->state=FALLING;
			//fprintf(stderr,"Up -- %d\n",character->FrameJumpingAnimation);
		}

	}
}

void Firing(Character *character){
	int i=0;
	/*Verifica o estado do personagem*/
	switch(character->state){
		case RUNNING:
			character->state=RUNNING_FIRE;
			if (character->FrameRunningAnimation < 2)
				character->FrameRunningShotAnimation = 0;
			else
				character->FrameRunningShotAnimation = character->FrameRunningAnimation - 1;
			break;
		case JUMPING:
			character->state=JUMPING_FIRE;
			break;
		case FALLING:
			character->state=FALLING_FIRE;
			break;

	}


	bulletChar *bc = &character->fires;
	if(bc->delayShot > 90){
		bc->delayShot=0;
		while(i++<MAX_FIRE){
			if(bc->active[i] == false){
				bc->active[i] = true;
				bc->position_X[i] = character->Position[X] + 5;
				bc->position_Y[i] = character->Position[Y];
				break;
			}
		}
	}


}

void depromove(Character *character){

	/*Isso aplica o efeito do personagem apenas mirar quando o usuário aperta X (botão de tiro)*/
	if(character->state == RUNNING_FIRE)
		character->state = RUNNING;
	if(character->state == JUMPING_FIRE)
        	character->state = JUMPING;
        if(character->state == FALLING_FIRE )
                character->state = FALLING;

}

/*Verifica se o personagem pode retornar ao estado de repouso*/
bool verifyIdle(Character *character){

	switch(character->state){
		case RUNNING:
		case IDLE:
			return true;
		case JUMPING:
		case JUMPING_FIRE:
		case FALLING:
		case FALLING_FIRE:
			return false;
	}


}

void moveBullet(Character *character){
	bulletChar *bc = &character->fires;
	bc->FrameShotAnimation++;
        bc->delayShot++;
        if (++bc->FrameShotAnimation == 120)
		bc->FrameShotAnimation = 0;

	
	for(int i=0;i<MAX_FIRE;i++){
		if(bc->active[i] == true)
			bc->position_X[i]+=VELOCIDADE_BULLET;
	}


}

/*Verifica se os tiros estão na tela*/
bool verifyBullet(Character *character){
	bulletChar *bc = &character->fires;
	for(int i=0;i<MAX_FIRE;i++){
		if(bc->position_X[i] > 900)
			bc->active[i] = false;
	
	}

}





