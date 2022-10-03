#include "charater.h"


// the state of character
enum {STOP = 0, MOVE, ATK,TURN};
typedef struct character
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
    int anime; // counting the time of animation
    int anime_time; // indicate how long the animation
}Character;
Character chara;
ALLEGRO_SAMPLE *sample = NULL;
void character_init(){
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/tank_level%d.png", 1 );
        chara.img_move[i-1] = al_load_bitmap(temp);
    }
    for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/tank_level_atk%d.png", i );
        chara.img_atk[i-1] = al_load_bitmap(temp);
    }
    // load effective sound
    sample = al_load_sample("./sound/atk_sound.wav");
    chara.atk_Sound  = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(chara.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_gain(chara.atk_Sound, music_volume+2) ;
    al_attach_sample_instance_to_mixer(chara.atk_Sound, al_get_default_mixer());

    // initial the geometric information of character
    chara.width = al_get_bitmap_width(chara.img_move[0]);
    chara.height = al_get_bitmap_height(chara.img_move[0]);
    chara.x = WIDTH/2;
    chara.y = HEIGHT/2;
    chara.dir = false;

    // initial the animation component
    chara.state = STOP;
    chara.anime = 0;
    chara.anime_time = 10;

}
int Bcoordination=0;
void charater_process(ALLEGRO_EVENT event){

    if(chara.x>920) chara.x=920;
    if(chara.y>920) chara.y=920;
    if(chara.x<10) chara.x=10;
    if(chara.y<10) chara.y=10;
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            chara.anime++;
            chara.anime %= chara.anime_time;
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
        chara.anime = 0;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void charater_update(){
    Bcoordination++;
    int coo=Bcoordination%10;
    if(Bcoordination>10) Bcoordination=0;
    if(key_state[ALLEGRO_KEY_UP] ){
        chara.y -= 2;
        chara.state = MOVE;
    }
    if(key_state[ALLEGRO_KEY_LEFT]){
        chara.dir = false;
        chara.x -= 2;
        chara.state = MOVE;
    }
    if(key_state[ALLEGRO_KEY_DOWN]){
        chara.y += 2;
        chara.state = MOVE;
    }
    if(key_state[ALLEGRO_KEY_RIGHT]){
        chara.dir = true;
        chara.x += 2;
        chara.state = MOVE;
    }
    if( key_state[ALLEGRO_KEY_D]){
        chara.angle +=(ALLEGRO_PI/(chara.turnrate));
        chara.state = TURN;
    }
    if( key_state[ALLEGRO_KEY_A]){
        chara.angle -=(ALLEGRO_PI/chara.turnrate);
        chara.state = TURN;
    }
    if( key_state[ALLEGRO_KEY_W] ){
        chara.state = ATK;
        bulletani++;
        bulletani%=100;
        chara.height = al_get_bitmap_height(chara.img_move[0]);//question not fixed
    }
    if( key_state[ALLEGRO_KEY_S] ){
        razerbulletani++;
        razerbulletani%=100;
    }
    else if( chara.anime == chara.anime_time-1 ){
        chara.anime = 0;
        chara.state = STOP;
    }else if ( chara.anime == 0 ){
        chara.state = STOP;
    }

}
void character_draw(){
    //printf("%f \n",chara.angle);
    // with the state, draw corresponding image
    if( chara.state == STOP ){
        al_draw_rotated_bitmap(chara.img_move[0], (chara.width)/2,((chara.height)/2),(chara.x+(chara.width)/2),(chara.y+(chara.height)/2),chara.angle,0);
        center_firex=chara.x+(chara.width)/2;
        center_firey=(chara.y+(chara.height)/2);
        fire_angle=chara.angle;
    }
    else if( chara.state == MOVE ){
        al_draw_rotated_bitmap(chara.img_move[0], (chara.width)/2,((chara.height)/2),(chara.x+(chara.width)/2),(chara.y+(chara.height)/2),chara.angle,0);
        center_firex=chara.x+(chara.width)/2;
        center_firey=chara.y+(chara.height)/2;
        fire_angle=chara.angle;
    }
    else if( chara.state == TURN ){
        al_draw_rotated_bitmap(chara.img_move[0], (chara.width)/2,((chara.height)/2),(chara.x+(chara.width)/2),(chara.y+(chara.height)/2),chara.angle,0);
        center_firex=chara.x+(chara.width)/2;
        center_firey=chara.y;
        fire_angle=chara.angle;
    }
    if( chara.state == ATK ){
            if( chara.anime < chara.anime_time/2 ){
                al_draw_rotated_bitmap(chara.img_atk[0], (chara.width)/2,((chara.height)/2),(chara.x+(chara.width)/2),(chara.y+(chara.height)/2),chara.angle,0);
            }
            else{

                al_draw_rotated_bitmap(chara.img_atk[1], (chara.width)/2,((chara.height)/2),(chara.x+(chara.width)/2),(chara.y+(chara.height)/2),chara.angle,0);
                al_play_sample_instance(chara.atk_Sound);

            }
    }
    //printf("%f\n",chara.angle);
}
void character_destory(){
    al_destroy_bitmap(chara.img_atk[0]);
    al_destroy_bitmap(chara.img_atk[1]);
    al_destroy_bitmap(chara.img_move[0]);
    al_destroy_bitmap(chara.img_move[1]);
    al_destroy_sample_instance(chara.atk_Sound);
}
void chara_restart(){
    chara.x = WIDTH/2;
    chara.y = HEIGHT/2;
    chara.dir = false;
    chara.angle=0;
    // initial the animation component
    chara.state = STOP;
    chara.anime = 0;
    chara.anime_time = 10;

}
void bigbosschar();

