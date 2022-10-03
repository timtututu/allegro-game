#include "bigbossbullet.h"
#include <math.h>
int Bbulletnum=0;
int razerbulletnum=0;
float Bbulspeed;
razertrack Brazer[10];
void bigbossbullet_init(){
    gamefont = al_load_ttf_font("./font/pirulen.ttf",30,0);
    game2font = al_load_ttf_font("./font/pirulen.ttf",20,0);
    Bbulspeed=5;
    for(int o=0;o<razerloding;o++){
      for(int i = 1 ; i <= 6 ; i++){
        char temp[50];
        sprintf( temp, "./image/razer%d.png", i );
        Brazer[o].razer_img[i] = al_load_bitmap(temp);
    }

    Brazer[o].width = al_get_bitmap_width(Brazer[o].razer_img[1]);
    Brazer[o].height = al_get_bitmap_height(Brazer[o].razer_img[1]);
    Brazer[o].x = 0;
    Brazer[o].y= 0;
    Brazer[o].time=0;
    Brazer[o].anime_tr = 0;
    Brazer[o].anime_time_tr = 60;
    }
}
int Btemp=0;

void bigbossbullet_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            for(int i=0;i<razerloding;i++){
                Brazer[i].anime_tr++;
                Brazer[i].anime_tr%=Brazer[i].anime_time_tr;
            }
        }
    }else if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
bool razer=false;
void bigbossbullet_update(){
    if( key_state[ALLEGRO_KEY_S]){
            //printf("ok\n");
            if(razerbulletani%10==0){
                for(int o=razerbulletnum;o<razerloding;o++){
                    //if(bulletbarlong==0) break;
                    if(!Brazer[o].Brazer_live&&cease_razer_fire==false){
                        razerbulletnum++;
                        Brazer[o].x=center_firex;
                        Brazer[o].y=center_firey;
                        Brazer[o].Brazer_live=true;
                        if(razerbulletnum==razerloding-1) razerbulletnum=0;
                        break;
                }
            }
        }
    }
}

void bigbossbullet_draw(){
    for(int o=0;o<razerloding;o++){

        if(Brazer[o].Brazer_live&&cease_razer_fire==false){
               // printf("%d\n",o);
            if(Brazer[o].time==0){
                Brazer[o].angle=fire_angle;
                Brazer[o].time=1;
            }
            if(Brazer[o].anime_tr<=Brazer[o].anime_time_tr/6 ){
                al_draw_rotated_bitmap(Brazer[o].razer_img[1], Brazer[o].width/2-250,(Brazer[o].height/2),Brazer[o].x-15,Brazer[o].y,Brazer[o].angle-1.57,0);
            }
            else if(Brazer[o].anime_tr<= Brazer[o].anime_time_tr/3&&Brazer[o].anime_tr>Brazer[o].anime_time_tr/6){
            al_draw_rotated_bitmap(Brazer[o].razer_img[2], Brazer[o].width/2-250,(Brazer[o].height/2),Brazer[o].x-15,Brazer[o].y,Brazer[o].angle-1.57,0);

            }
            else if(Brazer[o].anime_tr <= Brazer[o].anime_time_tr/2&&Brazer[o].anime_tr> Brazer[o].anime_time_tr/3){
            al_draw_rotated_bitmap(Brazer[o].razer_img[3], Brazer[o].width/2-250,(Brazer[o].height/2),Brazer[o].x-15,Brazer[o].y,Brazer[o].angle-1.57,0);

            }
            else if(Brazer[o].anime_tr <= (Brazer[o].anime_time_tr/6*4)&&Brazer[o].anime_tr > Brazer[o].anime_time_tr/2){
            al_draw_rotated_bitmap(Brazer[o].razer_img[4], Brazer[o].width/2-250,(Brazer[o].height/2),Brazer[o].x-15,Brazer[o].y,Brazer[o].angle-1.57,0);
            }
            else if(Brazer[o].anime_tr <= Brazer[o].anime_time_tr/6*5&&Brazer[o].anime_tr > (Brazer[o].anime_time_tr/6*4)){
            al_draw_rotated_bitmap(Brazer[o].razer_img[5], Brazer[o].width/2-250,(Brazer[o].height/2),Brazer[o].x-15,Brazer[o].y,Brazer[o].angle-1.57,0);
//printf("false\n",o);
            Brazer[o].Brazer_live=false;
            Brazer[o].time=0;
            }
        }
    }
}
void bigbossbullet_destory(void){
    for(int i=0;i<razerloding;i++){
            for(int u=0;u<6;u++){
                al_destroy_bitmap(Brazer[i].razer_img[u]);
        }
    }
}
void bigbossbullet_restart(){
    for(int o=0;o<razerloding;o++){
        Brazer[o].Brazer_live=false;
        Brazer[o].time=0;
    }
}

void razer_accept(){
    if(lifebarlong<=30){
        for(int i=0;i<razerloding;i++){
            Brazer[i].Brazer_live=false;
            Brazer[i].time=0;
        }
        cease_razer_fire=false;
        warning=true;
    }
    else{
            //printf("adf\n");
    cease_razer_fire=true;
    warning=false;
    /*for(int i=0;i<razerloding;i++){
            Brazer[i].Brazer_live=false;
        }*/
    }
}
int timeW=0;
void warning_razer(){
    if(timeW%2==0){
        al_draw_text(gamefont, al_map_rgb(255,255,255), 450, 70 , ALLEGRO_ALIGN_LEFT, "Razer");
        timeW++;
    }
    else{
        al_draw_text(game2font, al_map_rgb(255,255,255), 450, 70 , ALLEGRO_ALIGN_LEFT, "Razer");
    }
    timeW%=2;
}
