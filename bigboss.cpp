#include "bigboss.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
bigbossenemy bigboss19;
void bigboss_init(){
    bigboss19.speed=20.5+speedprefig;
    bigboss19.x=450;
    bigboss19.y=20;
    bigboss19.dir=true;
    char temp[50];
    sprintf( temp, "./image/vires_level%dB.png", 10);
    bigboss19.img_bigboss = al_load_bitmap(temp);

    // load effective sound
    /*sam = al_load_sample("./sound/atk_sound.wav");
    ene.vir_sound  = al_create_sample_instance(sam);
    al_set_sample_instance_playmode(ene.vir_sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ene.vir_sound, al_get_default_mixer());*/
    // initial the geometric information of character
    bigboss19.width = al_get_bitmap_width(bigboss19.img_bigboss);
    bigboss19.height = al_get_bitmap_height(bigboss19.img_bigboss);
    bigboss19.life=true;
    bigboss19.type=bigup;
    bigboss19.big_anime=0;
    bigboss19.big_anime_time=30;
}
void bigbossenemy_process(ALLEGRO_EVENT event){
    //printf("prroin\n");
    if( event.type == ALLEGRO_EVENT_TIMER ){
            //printf("prrokin\n");
        if( event.timer.source == fps ){
            bigboss19.big_anime++;
            bigboss19.big_anime %= bigboss19.big_anime_time;
        }
    }
    //printf("prrofin\n");
}
bool judgeflag=true;
double tempx=3,tempy=3;
void bigbossenemy_update(){
    srand(time(0));
    int u=rand();


    if(judgeflag){
        tempx=abs(sin(u))+3;
        tempy=abs(cos(u+10))+3;
        judgeflag=false;
    }
    //printf("%d %d\n",tempx,tempy);

    if(bigboss19.life){
        if(bigboss19.type==bigup){
            if(bigboss19.dir==false){
               bigboss19.x +=(tempx*bigboss19.speed);
               bigboss19.y -= (tempy*bigboss19.speed);
            }
            else{
              bigboss19.x -=(tempx*bigboss19.speed);
              bigboss19.y -= (tempy*bigboss19.speed);
            }
        }
        else if(bigboss19.type==bigdown){
            if(bigboss19.dir==false){
               bigboss19.x +=(tempx*bigboss19.speed);
               bigboss19.y += (tempy*bigboss19.speed);
            }
            else{
              bigboss19.x -=(tempx*bigboss19.speed);
              bigboss19.y += (tempy*bigboss19.speed);
            }
        }
        else if(bigboss19.type==bigright){
            if(bigboss19.dir==false){
               bigboss19.x +=(tempx*bigboss19.speed);
               bigboss19.y -= (tempy*bigboss19.speed);
            }
            else{
              bigboss19.x +=(tempx*bigboss19.speed);
              bigboss19.y += (tempy*bigboss19.speed);
            }
        }
        else if(bigboss19.type==bigleft){
            if(bigboss19.dir==false){
               bigboss19.x -=(tempx*bigboss19.speed);
               bigboss19.y -= (tempy*bigboss19.speed);
            }
            else{
              bigboss19.x -=(tempx*bigboss19.speed);
              bigboss19.y += (tempy*bigboss19.speed);
            }
        }
    if(bigboss19.x<=0){
            bigboss19.type=bigright;
            judgeflag=true;
            if(u%2==0) bigboss19.dir=false;
            else bigboss19.dir=true;
        }
        else if(bigboss19.x>=800){
            bigboss19.type=bigleft;
            judgeflag=true;
            if(u%2==0) bigboss19.dir=false;
            else bigboss19.dir=true;
        }
        else if(bigboss19.y<=0){
            bigboss19.type=bigdown;
            judgeflag=true;
            if(u%2==0) bigboss19.dir=false;
            else bigboss19.dir=true;
        }
        else if(bigboss19.y>=800){
            bigboss19.type=bigup;
            judgeflag=true;
            if(u%2==0) bigboss19.dir=false;
            else bigboss19.dir=true;
        }
    }
}
void bigboss_draw(){
        if(bigboss19.life){
            al_draw_bitmap(bigboss19.img_bigboss,bigboss19.x,bigboss19.y , 0);
        }
}
void bigboss_destory(){
        al_destroy_bitmap(bigboss19.img_bigboss);
}
void bigboss_restart(){
    bigboss19.speed=0.5+speedprefig;
    bigboss19.x=450;
    bigboss19.y=0;
    bigboss19.dir=true;
    bigboss19.life=true;
    bigboss19.type=bigup;
    judgeflag=true;
}
char razertime[15];
void bigboss_scoreboarddraw(){
    float Bosslife=100+Blifebarlong*1.7;
    if(Bosslife<=105) Bosslife=105;
    float Bbulletnu=775+bulletbarlong*1.9;
    if(Bbulletnu<=775) Bbulletnu=775;
     al_draw_rectangle(100, 40, 955, 60, al_map_rgb(255, 255, 255), 0);
     al_draw_rectangle(770, 70, 970, 90, al_map_rgb(255, 255, 255), 0);
     al_draw_filled_rectangle(105, 43, Bosslife, 56, al_map_rgb(255,69,0));
     al_draw_filled_rectangle(775, 73, Bbulletnu, 86, al_map_rgb(0, 191, 225));

     float life=775+lifebarlong*1.9;
     if(life<=775) life=775;
     al_draw_rectangle(770, 100, 970, 120, al_map_rgb(255, 255, 255), 0);
     al_draw_filled_rectangle(775, 103, life, 117, al_map_rgb(255,69,0));
     if(life<=775&&modeinm==0){
        window=-1;
        al_stop_timer(fps);
     }
}


