#include "bigbosschara.h"
enum {BSTOP = 0, BMOVE, BATK,BTURN};
typedef struct bigbosschara
{
    int x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    double angle=0;
    int turnrate=50;
    ALLEGRO_BITMAP *img_move[2];
    ALLEGRO_BITMAP *img_atk[2];
    ALLEGRO_SAMPLE_INSTANCE *atk_Sound;
     int anime=0;
     int anime_time=10;
}bigbosschara;
bigbosschara bigchar;

ALLEGRO_SAMPLE *Bsample = NULL;
void bigbosschar_init(){
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/tank_level%d.png", 1 );
        bigchar.img_move[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/tank_level_atk%d.png", i );
        bigchar.img_atk[i-1] = al_load_bitmap(temp);
    }
    // load effective sound
    Bsample = al_load_sample("./sound/atk_sound.wav");
    bigchar.atk_Sound  = al_create_sample_instance(Bsample);
    al_set_sample_instance_playmode(bigchar.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(bigchar.atk_Sound, al_get_default_mixer());

    // initial the geometric information of bigcharcter
    bigchar.width = al_get_bitmap_width(bigchar.img_move[0]);
    bigchar.height = al_get_bitmap_height(bigchar.img_move[0]);
    bigchar.x = WIDTH/2;
    bigchar.y = HEIGHT/2;
    bigchar.dir = false;

    // initial the animation component
    bigchar.state = BSTOP;
    bigchar.anime = 0;
    bigchar.anime_time = 10;

}
int coordination=0;
void bigbosschar_process(ALLEGRO_EVENT event){

    if(bigchar.x>920) bigchar.x=920;
    if(bigchar.y>920) bigchar.y=920;
    if(bigchar.x<10) bigchar.x=10;
    if(bigchar.y<10) bigchar.y=10;
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            bigchar.anime++;
            bigchar.anime %= bigchar.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        bigchar.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void bigbosschar_update(){
    coordination++;
    int coo=coordination%10;
    if(coordination>10) coordination=0;
    if(key_state[ALLEGRO_KEY_UP] ){
        bigchar.y -= 2;
        bigchar.state = BMOVE;
    }
    if(key_state[ALLEGRO_KEY_LEFT]){
        bigchar.dir = false;
        bigchar.x -= 2;
        bigchar.state = BMOVE;
    }
    if(key_state[ALLEGRO_KEY_DOWN]){
        bigchar.y += 2;
        bigchar.state = BMOVE;
    }
    if(key_state[ALLEGRO_KEY_RIGHT]){
        bigchar.dir = true;
        bigchar.x += 2;
        bigchar.state = BMOVE;
    }
    if( key_state[ALLEGRO_KEY_D]){
        bigchar.angle +=(ALLEGRO_PI/(bigchar.turnrate));
        bigchar.state = BTURN;
    }
    if( key_state[ALLEGRO_KEY_A]){
        bigchar.angle -=(ALLEGRO_PI/bigchar.turnrate);
        bigchar.state = BTURN;
    }
    if( key_state[ALLEGRO_KEY_W] ){
        bigchar.state = BATK;
        bulletani++;
        bigchar.height = al_get_bitmap_height(bigchar.img_move[0]);//question not fixed
    }
    else if( bigchar.anime == bigchar.anime_time-1 ){
        bigchar.anime = 0;
        bigchar.state = BSTOP;
    }else if ( bigchar.anime == 0 ){
        bigchar.state = BSTOP;
    }

}
void bigbosschar_draw(){
    if( bigchar.state == BSTOP ){
        al_draw_rotated_bitmap(bigchar.img_move[0], (bigchar.width)/2,((bigchar.height)/2),(bigchar.x+(bigchar.width)/2),(bigchar.y+(bigchar.height)/2),bigchar.angle,0);
        center_firex=bigchar.x+(bigchar.width)/2;
        center_firey=(bigchar.y+(bigchar.height)/2);
        fire_angle=bigchar.angle;
    }
    else if( bigchar.state == BMOVE ){
        al_draw_rotated_bitmap(bigchar.img_move[0], (bigchar.width)/2,((bigchar.height)/2),(bigchar.x+(bigchar.width)/2),(bigchar.y+(bigchar.height)/2),bigchar.angle,0);
        center_firex=bigchar.x+(bigchar.width)/2;
        center_firey=bigchar.y+(bigchar.height)/2;
        fire_angle=bigchar.angle;
    }
    else if( bigchar.state == BTURN ){
        al_draw_rotated_bitmap(bigchar.img_move[0], (bigchar.width)/2,((bigchar.height)/2),(bigchar.x+(bigchar.width)/2),(bigchar.y+(bigchar.height)/2),bigchar.angle,0);
        center_firex=bigchar.x+(bigchar.width)/2;
        center_firey=bigchar.y;
        fire_angle=bigchar.angle;
    }
    if( bigchar.state == BATK ){
            if( bigchar.anime < bigchar.anime_time/2 ){
                al_draw_rotated_bitmap(bigchar.img_atk[0], (bigchar.width)/2,((bigchar.height)/2),(bigchar.x+(bigchar.width)/2),(bigchar.y+(bigchar.height)/2),bigchar.angle,0);
            }
            else{

                al_draw_rotated_bitmap(bigchar.img_atk[1], (bigchar.width)/2,((bigchar.height)/2),(bigchar.x+(bigchar.width)/2),(bigchar.y+(bigchar.height)/2),bigchar.angle,0);
                al_play_sample_instance(bigchar.atk_Sound);

            }
    }
    //printf("%f\n",bigchar.angle);
}
void bigbosschar_destory(){
    al_destroy_bitmap(bigchar.img_atk[0]);
    al_destroy_bitmap(bigchar.img_atk[1]);
    al_destroy_bitmap(bigchar.img_move[0]);
    al_destroy_bitmap(bigchar.img_move[1]);
    al_destroy_sample_instance(bigchar.atk_Sound);
}
void bigbosschar_restart(){
    bigchar.x = WIDTH/2;
    bigchar.y = HEIGHT/2;
    bigchar.dir = false;
    bigchar.angle=0;
    // initial the animation component
    bigchar.state = BSTOP;
    bigchar.anime = 0;
    bigchar.anime_time = 10;

}
