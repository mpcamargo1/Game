#include <stdio.h>
#include <math.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "arena.h"		/*Inclui Character.h | stdbool.h | Allegro5 */
#include "hud.h"

/*Macros*/
	/*Tela*/
#define SCREEN_WIDTH    506
#define SCREEN_HEIGHT   900

	/*Teclado*/
#define KEY_SEEN     1
#define KEY_RELEASED 2

// Compilar com o GCC : gcc game.c arena.c hud.c -lm -o game $(pkg-config allegro-5 allegro_font-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_image-5 --libs --cflags)
// Obs : A estrutura principal do código é baseado em https://github.com/liballeg/allegro_wiki/wiki/Allegro-Vivace%3A-Input


// Desenha na tela a caixa de colisão
void draw_box_collision(Character *character){
	al_draw_rectangle(character->Position[X], character->Position[Y] ,character->Position[X] + 30 ,character->Position[Y] + 35 ,al_map_rgba_f(0.2, 0.2, 0, 1), 0);
}

// Desenha na tela o personagem
void draw_character(Character *character){
	int IndexAnimation=0;

 	switch(character->state){
                case RUNNING:
                             IndexAnimation = floor(character->FrameRunningAnimation);
                             al_draw_bitmap_region(character->sprite,character->RunningAnimation[0][IndexAnimation], character->RunningAnimation[2][IndexAnimation], character->RunningAnimation[1][IndexAnimation] - character->RunningAnimation[0][IndexAnimation], character->RunningAnimation[3][IndexAnimation] - character->RunningAnimation[2][IndexAnimation], character->Position[X], character->Position[Y], character->Direction);
                        break;
		case RUNNING_FIRE:
			    IndexAnimation = floor(character->FrameRunningShotAnimation);
			    al_draw_bitmap_region(character->sprite,character->RunningShotAnimation[0][IndexAnimation], character->RunningShotAnimation[2][IndexAnimation], character->RunningShotAnimation[1][IndexAnimation] - character->RunningShotAnimation[0][IndexAnimation], character->RunningShotAnimation[3][IndexAnimation] - character->RunningShotAnimation[2][IndexAnimation], character->Position[X], character->Position[Y], character->Direction);

			break;
                case IDLE:
                          IndexAnimation = floor(character->FrameIdlingAnimation);
                          al_draw_bitmap_region(character->sprite,character->IdlingAnimation[0][IndexAnimation], character->IdlingAnimation[2][IndexAnimation], character->IdlingAnimation[1][IndexAnimation] - character->IdlingAnimation[0][IndexAnimation],character->IdlingAnimation[3][IndexAnimation] - character->IdlingAnimation[2][IndexAnimation],character->Position[X], character->Position[Y], character->Direction);
                        break;
                case FALLING:
                case JUMPING:
                        IndexAnimation = floor(character->FrameJumpingAnimation/10);
                        al_draw_bitmap_region(character->sprite,character->JumpingAnimation[0][IndexAnimation],character->JumpingAnimation[2][IndexAnimation], character->JumpingAnimation[1][IndexAnimation] - character->JumpingAnimation[0][IndexAnimation],character->JumpingAnimation[3][IndexAnimation] - character->JumpingAnimation[2][IndexAnimation], character->Position[X], character->Position[Y], character->Direction);
                        break;
                case FALLING_FIRE:
                case JUMPING_FIRE:
                        IndexAnimation = floor(character->FrameJumpingAnimation/10);
                        al_draw_bitmap_region(character->sprite,character->JumpingShotAnimation[0][IndexAnimation],character->JumpingShotAnimation[2][IndexAnimation], character->JumpingShotAnimation[1][IndexAnimation] - character->JumpingShotAnimation[0][IndexAnimation],character->JumpingShotAnimation[3][IndexAnimation] - character->JumpingShotAnimation[2][IndexAnimation], character->Position[X] - character->MirroredOffset, character->Position[Y], character->Direction);
                                        break;


            }


}

/*Desenha os tiros na tela*/
void draw_shot(Character *character){
	bulletChar *bc = &character->fires;
	int IndexAnimation = floor(bc->FrameShotAnimation/60);
	for(int i=0;i<MAX_FIRE;i++){
		if(bc->active[i] == true){
			al_draw_bitmap_region(character->sprite,bc->ShotAnimation[0][IndexAnimation], bc->ShotAnimation[2][IndexAnimation], bc->ShotAnimation[1][IndexAnimation] - bc->ShotAnimation[0][IndexAnimation], bc->ShotAnimation[3][IndexAnimation] - bc->ShotAnimation[2][IndexAnimation], bc->position_X[i], bc->position_Y[i], 0);
		}

	
	}

}


void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{
    Character megaman;
    Arena battle_arena;
    initializePosition(&megaman);
    load_character(&megaman);
    load_arena(&battle_arena);

    fprintf(stderr,"%d e %d\n",megaman.Position[X],megaman.Position[Y]);

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(SCREEN_HEIGHT, 506);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");
    megaman.sprite = al_load_bitmap("megamanx.png");
    battle_arena.sprite = al_load_bitmap("arena.png");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    ALLEGRO_TRANSFORM trans, prevTrans;
    al_copy_transform(&prevTrans, al_get_current_transform());

    al_start_timer(timer);

	unsigned char key[ALLEGRO_KEY_MAX];
   	memset(key, 0, sizeof(key));
    while(true)
    {
        al_wait_for_event(queue, &event);

   	switch(event.type){
    	case ALLEGRO_EVENT_TIMER:

		megaman.KeyPressed=false;
		depromove(&megaman);

		/*Verifica se os tiros estão na tela*/
		verifyBullet(&megaman);
		/*Aplica movimento ao tiro*/
		moveBullet(&megaman);

		if(key[ALLEGRO_KEY_UP]){
		    //megaman.Position[Y]+=-2;
        	    Jumping(&megaman,true);
		}
        	if(key[ALLEGRO_KEY_DOWN]){
        	    //megaman.Position[Y]+=2;
		}
        	if(key[ALLEGRO_KEY_LEFT]){
        	    RunningLeft(&megaman);
		}
        	if(key[ALLEGRO_KEY_RIGHT]){
		    RunningRight(&megaman);
		}


        	if(key[ALLEGRO_KEY_ESCAPE]){
        	    done = true;
		}
		if(key[ALLEGRO_KEY_X]){
		   Firing(&megaman);
		}



		if(megaman.KeyPressed == false && verifyIdle(&megaman))/* && megaman.state != JUMPING && megaman.state != FALLING && megaman.state!=JUMPING_FIRE && megaman.state!=FALLING_FIRE)*/
		  	Idling(&megaman);
		else if(megaman.state == JUMPING || megaman.state == JUMPING_FIRE)
			Jumping(&megaman,false);

		/*Aplica gravidade ao personagem*/
		gravity(&megaman,&battle_arena);

        	for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
        	    key[i] &= KEY_SEEN;

        	redraw = true;
        	break;

    		case ALLEGRO_EVENT_KEY_DOWN:
        		key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
        		break;
    		case ALLEGRO_EVENT_KEY_UP:
        		key[event.keyboard.keycode] &= KEY_RELEASED;
        		break;

    		case ALLEGRO_EVENT_DISPLAY_CLOSE:
        		done = true;
        		break;
	}




       if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue)){
	    al_clear_to_color(al_map_rgb(0,0,0));
	    al_draw_bitmap(battle_arena.sprite,0,0,0);
            al_draw_textf(font, al_map_rgb(0,0,0), 0, 0, 0, "X: %d Y: %d", megaman.Position[X], megaman.Position[Y]);


	    al_identity_transform(&trans);
            
	    
	    al_scale_transform(&trans, 1.2, 1.2);
	    al_use_transform(&trans);
	    draw_character(&megaman);
	    //draw_box_collision(&megaman);
	    draw_shot(&megaman);

	    al_flip_display();
	    al_use_transform(&prevTrans);
            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_bitmap(megaman.sprite);
    al_destroy_event_queue(queue);

    return 0;
}



