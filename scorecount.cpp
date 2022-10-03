#include "scorecount.h"
char scorenum[15];
char levelnum[15];

void scoredraw(){
        float life=775+lifebarlong*1.9;
        float bulletnu=775+bulletbarlong*1.9;
     al_draw_rectangle(770, 40, 970, 60, al_map_rgb(255, 255, 255), 0);
     al_draw_rectangle(770, 70, 970, 90, al_map_rgb(255, 255, 255), 0);
     al_draw_filled_rectangle(775, 43, life, 56, al_map_rgb(255,69,0));
     al_draw_filled_rectangle(775, 73, bulletnu, 86, al_map_rgb(0, 191, 225));
     al_draw_text(font, al_map_rgb(255,255,255), 50, 40 , ALLEGRO_ALIGN_LEFT, scorenum);
     al_draw_text(font, al_map_rgb(255,255,255), 430, 40 , ALLEGRO_ALIGN_LEFT, levelnum);
     if(life<=775&&modeinm==0) {
        window=-1;
        al_stop_timer(fps);
     }
}
void scoreupdate(){
    if(level==10){
        if(Blifebarlong<=0){
            window=5;
        }
    }
    else {
        if(score==50){
        window=3;
        al_stop_sample_instance(sfwin2_instance);
        music_play=true;
        al_stop_timer(fps);
        key_state[ALLEGRO_KEY_MAX] = {false};
        //al_pause_event_queue(event_queue,true);
        //printf("score=10\n");
        //al_unregister_event_source(event_queue,al_get_keyboard_event_source());
        //al_unregister_event_source(event_queue,al_get_mouse_event_source());
        level++;
        timess=1;
    }
    sprintf(scorenum, "Score %d/50", score);
    sprintf(levelnum, "Level %d/10", level);
    }
}
void scoredestory(){
}
void newlevel(){
 center_firex=540;
 center_firey=540;
 bulletani=0;
 bulletloding=100;
 fire_angle=0;
 flag=false;
 //level=1;
// totalene=50;
 lifebarlong=100;
 bulletbarlong=100;
 score=0;
 Lethality=10;
 key_state[ALLEGRO_KEY_MAX] = {false};
 judge_next_window = false;
}
void nextlevelkeyre(){
    //al_flush_event_queue(event_queue);
    key_state[ALLEGRO_KEY_W] = {false};
    key_state[ALLEGRO_KEY_D] = {false};
    key_state[ALLEGRO_KEY_A] = {false};
    key_state[ALLEGRO_KEY_UP] = {false};
    key_state[ALLEGRO_KEY_DOWN] = {false};
    key_state[ALLEGRO_KEY_RIGHT] = {false};
    key_state[ALLEGRO_KEY_LEFT] = {false};
    key_state[ALLEGRO_KEY_S] = {false};
}

