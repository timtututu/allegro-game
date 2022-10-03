#include "bullet_fire.h"
#include <math.h>
int bulletnum=0;
float bulspeed;
track tra[100];
void bullet_init(){
    bulspeed=5;
    //printf("0000\n");
    //printf("%d\n",bulletloding);
    for(int o=0;o<bulletloding;o++){
      for(int i = 1 ; i <= 2 ; i++){
        char temp[50];
        sprintf( temp, "./image/bulletBlue%d.png", i );
        tra[o].bullet_img[i-1] = al_load_bitmap(temp);
    }

    tra[o].width = al_get_bitmap_width(tra[o].bullet_img[0]);
    tra[o].height = al_get_bitmap_height(tra[o].bullet_img[0]);
    tra[o].x = 0;
    tra[o].y= 0;

    tra[o].anime_tr = 0;
    tra[o].anime_time_tr = 10;
    }
    //printf("adsfadfsd\n");
}
int times=0;
int temp=0;
//int bullet_mix_x=center_firex+tra.x;
//int bullet_mix_y=center_firey+tra.y;
void bullet_process(ALLEGRO_EVENT event){

    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            /*anime_tr++;
            anime_tr%= chara.anime_time;*/
        }
    // process the keyboard event
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        //printf("down\n");
        key_state[event.keyboard.keycode] = true;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        //printf("up\n");
        key_state[event.keyboard.keycode] = false;
    }
}
void bullet_update(){
    if( key_state[ALLEGRO_KEY_W]){
            if(bulletani%10==0){
                for(int o=bulletnum;o<bulletloding;o++){
                    if(bulletbarlong==0) break;
                    if(!tra[o].bullet_live){
                        bulletbarlong--;
                        bulletnum++;
                        tra[o].x=center_firex;
                        tra[o].y=center_firey;
                        tra[o].bullet_live=true;
                        if(bulletnum==bulletloding-1) bulletnum=0;
                        break;
                    }

            }
        }
    }
    for(int o=0;o<bulletloding;o++){
    if(tra[o].bullet_live){
            double xsin=sin(tra[o].angle);
            double ycos=cos(tra[o].angle);


                tra[o].x=tra[o].x+xsin*bulspeed;
                tra[o].y=tra[o].y-ycos*bulspeed;
                //printf("%f\n",xsin);
                //printf("%d %d \n",tra[o].x,tra[o].y);


            if(tra[o].x>1000){
                tra[o].bullet_live=false;
                tra[o].time=0;
            }
            if(tra[o].y>1000){
                tra[o].bullet_live=false;
                tra[o].time=0;
            }
            if(tra[o].x<0) {
                tra[o].bullet_live=false;
                tra[o].time=0;
            }
            if(tra[o].y<0){
                tra[o].bullet_live=false;
                tra[o].time=0;
            }
            temp=o+1;
        }
    }
}

void bullet_draw(){
    for(int o=0;o<bulletloding;o++){

        if(tra[o].bullet_live){
        if(tra[o].time==0){
            //printf("%d\n",o);
          tra[o].angle=fire_angle;
          tra[o].time=1;
          if(bulletbarlong<0) bulletbarlong=0;
        }
        al_draw_rotated_bitmap(tra[o].bullet_img[0], tra[o].width/2,(tra[o].height/2),tra[o].x,tra[o].y,tra[o].angle,0);
        }
        //else break;
    }
}
void bullet_destory(void){
    for(int i=0;i<bulletloding;i++){
        al_destroy_bitmap(tra[i].bullet_img[0]);
        al_destroy_bitmap(tra[i].bullet_img[1]);
    }
}
void bullet_restart(){
    for(int o=0;o<bulletloding;o++){
        tra[o].bullet_live=false;
        tra[o].time=0;
    }
}
