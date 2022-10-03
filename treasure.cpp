#include "treasure.h"
#include <time.h>
#include <math.h>
enum{moven1=0,moven2,moven3,moven4,moven5,moven6,moven7,moven8};
treasure tre_gun[10];
treasure tre_vac[10];
int tremakgun; // counting the time of animation
int tremakvan;
int tremak_time; // indicate how long the animation

int numtre_vac=0;
int numtre_gun=0;
void treasure_init(){
    srand(time(0));
    // load character images
    for(int o=0;o<10;o++){
        tre_gun[o].speed=0.5*level;
        tre_vac[o].speed=0.5*level;
        if(level==10){
           tre_gun[o].speed=1.5;
           tre_vac[o].speed=1.5;
        }
        int u=rand()%1000;
        int vu=rand()%1000;
        tre_gun[o].img_tre = al_load_bitmap("./image/gun.png");
        tre_vac[o].img_tre = al_load_bitmap("./image/vaccine.png");

    // load effective sound
    /*sam = al_load_sample("./sound/atk_sound.wav");
    ene.vir_sound  = al_create_sample_instance(sam);
    al_set_sample_instance_playmode(ene.vir_sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ene.vir_sound, al_get_default_mixer());*/

    // initial the geometric information of character
    tre_gun[o].width = al_get_bitmap_width(tre_gun[o].img_tre);
    tre_vac[o].width = al_get_bitmap_width(tre_vac[o].img_tre);
    tre_gun[o].height = al_get_bitmap_width(tre_gun[o].img_tre);
    tre_vac[o].height = al_get_bitmap_width(tre_vac[o].img_tre);
    if(o%4==0){
       tre_gun[o].x = -60;
       tre_gun[o].y = (double)u;
       tre_gun[o].type=l;
       tre_vac[o].x = -60;
       tre_vac[o].y = (double)vu;
       tre_vac[o].type=l;
    }
    else if(o%4==1){
       tre_gun[o].x = 1000;
       tre_gun[o].y = (double)u;
       tre_gun[o].type=r;
       tre_vac[o].x = 1000;
       tre_vac[o].y = (double)vu;
       tre_vac[o].type=r;
    }
    else if(o%4==2){
       tre_gun[o].x = (double)u;
       tre_gun[o].y = -60;
       tre_gun[o].type=u;
       tre_vac[o].x = (double)vu;
       tre_vac[o].y = -60;
       tre_vac[o].type=u;
    }
    else if(o%4==3){
       tre_gun[o].x = (double)u;
       tre_gun[o].y = 1000;
       tre_gun[o].type=d;
       tre_vac[o].x = (double)vu;
       tre_vac[o].y = 1000;
       tre_vac[o].type=d;

    }
    tre_gun[o].life = false;
    tre_vac[o].life = false;
    }
    //printf("%f %f\n",tre_gun[2].x,tre_gun[2].y);

    tremakgun=0;
    tremakvan=0;
    tremak_time=level*200;
    if(level==10) tremak_time=400;
}
void treasure_process(ALLEGRO_EVENT event){
for(int o=0;o<10;o++){
    int u=rand()%1000;
    if(tre_gun[o].x>1000){
        tre_gun[o].times=0;
        tre_gun[o].life=false;
            if(tre_gun[o].type==u){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = -60;
                //printf("ad");
            }
            else if(tre_gun[o].type==d){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = 1000;
            }
            else if(tre_gun[o].type==r){
                tre_gun[o].x = 1000;
                tre_gun[o].y = (double)u;
            }
            else if(tre_gun[o].type==l){
                tre_gun[o].x = -60;
                tre_gun[o].y = (double)u;
            }
    }
    else if(tre_gun[o].y>1000){
        tre_gun[o].times=0;
        tre_gun[o].life=false;
            if(tre_gun[o].type==u){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = -60;
            }
            else if(tre_gun[o].type==d){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = 1000;
            }
            else if(tre_gun[o].type==r){
                tre_gun[o].x = 1000;
                tre_gun[o].y = (double)u;
            }
            else if(tre_gun[o].type==l){
                tre_gun[o].x = -60;
                tre_gun[o].y = (double)u;
            }
    }
    else if(tre_gun[o].x<-60){
        tre_gun[o].times=0;
        tre_gun[o].life=false;
            if(tre_gun[o].type==u){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = -60;
            }
            else if(tre_gun[o].type==d){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = 1000;
            }
            else if(tre_gun[o].type==r){
                tre_gun[o].x = 1000;
                tre_gun[o].y = (double)u;
            }
            else if(tre_gun[o].type==l){
                tre_gun[o].x = -60;
                tre_gun[o].y = (double)u;
            }
    }
    else if(tre_gun[o].y<-60){
        tre_gun[o].times=0;
        tre_gun[o].life=false;
            if(tre_gun[o].type==u){
                tre_gun[o].x = (double)u;
                tre_gun[o].y =-60;
            }
            else if(tre_gun[o].type==d){
                tre_gun[o].x = (double)u;
                tre_gun[o].y = 1000;
            }
            else if(tre_gun[o].type==r){
                tre_gun[o].x = 1000;
                tre_gun[o].y = (double)u;
            }
            else if(tre_gun[o].type==l){
                tre_gun[o].x = -60;
                tre_gun[o].y = (double)u;
            }
        }
    int vu=rand()%1000;
    if(tre_vac[o].x>1000){
        tre_vac[o].times=0;
        tre_vac[o].life=false;

            if(tre_vac[o].type==u){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = -60;
                //printf("ad");
            }
            else if(tre_vac[o].type==d){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = 1000;
            }
            else if(tre_vac[o].type==r){
                tre_vac[o].x = 1000;
                tre_vac[o].y = (double)vu;
            }
            else if(tre_vac[o].type==l){
                tre_vac[o].x = -60;
                tre_vac[o].y = (double)vu;
            }
    }
    else if(tre_vac[o].y>1000){
        tre_vac[o].times=0;
        tre_vac[o].life=false;
            if(tre_vac[o].type==u){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = -60;
            }
            else if(tre_vac[o].type==d){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = 1000;
            }
            else if(tre_vac[o].type==r){
                tre_vac[o].x = 1000;
                tre_vac[o].y = (double)vu;
            }
            else if(tre_vac[o].type==l){
                tre_vac[o].x = -60;
                tre_vac[o].y = (double)vu;
            }
    }
    else if(tre_vac[o].x<-60){
        tre_vac[o].times=0;
        tre_vac[o].life=false;
            if(tre_vac[o].type==u){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = -60;
            }
            else if(tre_vac[o].type==d){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = 1000;
            }
            else if(tre_vac[o].type==r){
                tre_vac[o].x = 1000;
                tre_vac[o].y = (double)vu;
            }
            else if(tre_vac[o].type==l){
                tre_vac[o].x = -60;
                tre_vac[o].y = (double)vu;
            }
    }
    else if(tre_vac[o].y<-60){
        tre_vac[o].times=0;
        tre_vac[o].life=false;
            if(tre_vac[o].type==u){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y =-60;
            }
            else if(tre_vac[o].type==d){
                tre_vac[o].x = (double)vu;
                tre_vac[o].y = 1000;
            }
            else if(tre_vac[o].type==r){
                tre_vac[o].x = 1000;
                tre_vac[o].y = (double)vu;
            }
            else if(tre_vac[o].type==l){
                tre_vac[o].x = -60;
                tre_vac[o].y = (double)vu;
            }
        }
    }
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            tremakgun++;
            tremakgun %= tremak_time;
            tremakvan++;
            tremakvan%=tremak_time;
        }
    }
}
double xg[15];
double yg[15];
double xv[15];
double yv[15];
void treasure_update(){
    int temp;
    if(tremakgun==tremak_time-1&&numtre_gun<10){
        for(int o=0;o<10;o++){
            if(!tre_gun[o].life){
               tre_gun[numtre_gun].life=true;
               numtre_gun++;
               if(numtre_gun==10) numtre_gun=0;
               break;
            }
        }
    }
    if(tremakvan==tremak_time-5&&numtre_vac<10){
        for(int o=0;o<10;o++){
            if(!tre_vac[o].life){
               tre_vac[numtre_vac].life=true;
               numtre_vac++;
               if(numtre_vac==10) numtre_vac=0;
               break;
            }
        }
    }
    srand(time(0));
    for(int o=0;o<10;o++){
        int u=rand();
        int uv=rand();
        if(tre_gun[o].life){
            if(tre_gun[o].times==0){
                 xg[o]=abs(sin(u));
                 yg[o]=abs(cos(u+10));
            if(tre_gun[o].type==u){
                if(tre_gun[o].x>500){
                    tre_gun[o].movetype=moven1;
                }
                else{
                    tre_gun[o].movetype=moven2;
                }
            }
            else if(tre_gun[o].type==d){
                if(tre_gun[o].x>500){
                    tre_gun[o].movetype=moven3;
                }
                else{
                    tre_gun[o].movetype=moven4;
                }
            }
            else if(tre_gun[o].type==r){
                if(tre_gun[o].y>500){
                    tre_gun[o].movetype=moven5;
                }
                else{
                    tre_gun[o].movetype=moven6;
                }
            }
            else if(tre_gun[o].type==l){
                if(tre_gun[o].y>500){
                    tre_gun[o].movetype=moven7;
                }
                else{
                    tre_gun[o].movetype=moven8;
                    }
                }
            }
        if(tre_gun[o].movetype==moven1){
            tre_gun[o].x -=xg[o]*tre_gun[o].speed;
            tre_gun[o].y +=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;
        }
        else if(tre_gun[o].movetype==moven2){
            tre_gun[o].x +=xg[o]*tre_gun[o].speed;
            tre_gun[o].y +=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;
        }
        else if(tre_gun[o].movetype==moven3){
            tre_gun[o].x -=xg[o]*tre_gun[o].speed;
            tre_gun[o].y -=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;

        }
        else if(tre_gun[o].movetype==moven4){
            tre_gun[o].x +=xg[o]*tre_gun[o].speed;
            tre_gun[o].y -=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;
        }
        else if(tre_gun[o].movetype==moven5){
            tre_gun[o].x -=xg[o]*tre_gun[o].speed;
            tre_gun[o].y -=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;

        }
        else if(tre_gun[o].movetype==moven6){
            tre_gun[o].x -=xg[o]*tre_gun[o].speed;
            tre_gun[o].y +=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;

        }
        else if(tre_gun[o].movetype==moven7){
            tre_gun[o].x +=xg[o]*tre_gun[o].speed;
            tre_gun[o].y -=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;

        }
        else if(tre_gun[o].movetype==moven8){
            tre_gun[o].x +=xg[o]*tre_gun[o].speed;
            tre_gun[o].y +=yg[o]*tre_gun[o].speed;
            tre_gun[o].times++;
        }
    }
    if(tre_vac[o].life){
            if(tre_vac[o].times==0){
                 xv[o]=abs(sin(uv));
                 yv[o]=abs(cos(uv+10));

            if(tre_vac[o].type==u){
                if(tre_vac[o].x>500){
                    tre_vac[o].movetype=moven1;
                }
                else{
                    tre_vac[o].movetype=moven2;
                }
            }
            else if(tre_vac[o].type==d){
                if(tre_vac[o].x>500){
                    tre_vac[o].movetype=moven3;
                }
                else{
                    tre_vac[o].movetype=moven4;
                }
            }
            else if(tre_vac[o].type==r){
                if(tre_vac[o].y>500){
                    tre_vac[o].movetype=moven5;
                }
                else{
                    tre_vac[o].movetype=moven6;
                }
            }
            else if(tre_vac[o].type==l){
                if(tre_vac[o].y>500){
                    tre_vac[o].movetype=moven7;
                }
                else{
                    tre_vac[o].movetype=moven8;
                    }
                }
            }
        if(tre_vac[o].movetype==moven1){
            tre_vac[o].x -=xv[o]*tre_vac[o].speed;
            tre_vac[o].y +=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;
        }
        else if(tre_vac[o].movetype==moven2){
            tre_vac[o].x +=xv[o]*tre_vac[o].speed;
            tre_vac[o].y +=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;
        }
        else if(tre_vac[o].movetype==moven3){
            tre_vac[o].x -=xv[o]*tre_vac[o].speed;
            tre_vac[o].y -=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;

        }
        else if(tre_vac[o].movetype==moven4){
            tre_vac[o].x +=xv[o]*tre_vac[o].speed;
            tre_vac[o].y -=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;
        }
        else if(tre_vac[o].movetype==moven5){
            tre_vac[o].x -=xv[o]*tre_vac[o].speed;
            tre_vac[o].y -=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;

        }
        else if(tre_vac[o].movetype==moven6){
            tre_vac[o].x -=xv[o]*tre_vac[o].speed;
            tre_vac[o].y +=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;

        }
        else if(tre_vac[o].movetype==moven7){
            tre_vac[o].x +=xv[o]*tre_vac[o].speed;
            tre_vac[o].y -=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;

        }
        else if(tre_vac[o].movetype==moven8){
            tre_vac[o].x +=xv[o]*tre_vac[o].speed;
            tre_vac[o].y +=yv[o]*tre_vac[o].speed;
            tre_vac[o].times++;
        }
    }
    }
}
void treasure_draw(){
    for(int o=0;o<10;o++){
        if(tre_gun[o].life){
            al_draw_bitmap(tre_gun[o].img_tre, tre_gun[o].x,tre_gun[o].y , 0);
        }
        if(tre_vac[o].life){
            al_draw_bitmap(tre_vac[o].img_tre, tre_vac[o].x,tre_vac[o].y , 0);
        }
    }
}
void treasure_destory(){
    for(int i=0;i<10;i++){
        al_destroy_bitmap(tre_gun[i].img_tre);
        al_destroy_bitmap(tre_vac[i].img_tre);
    }
}
void treasure_restart(){
    for(int e=0;e<10;e++){
        tre_gun[e].life=false;
        tre_vac[e].life=false;
        srand(time(0));
        int u=rand()%1000;
        if(tre_gun[e].type==u){
            tre_gun[e].x = (double)u;
            tre_gun[e].y = -65;
        }
        else if(tre_gun[e].type==d){
            tre_gun[e].x = (double)u;
            tre_gun[e].y = 1005;
        }
        else if(tre_gun[e].type==r){
            tre_gun[e].x = 1005;
            tre_gun[e].y = (double)u;
        }
        else if(tre_gun[e].type==l){
            tre_gun[e].x = -65;
            tre_gun[e].y = (double)u;
            }
        int uu=rand()%1000;
        if(tre_vac[e].type==u){
                tre_vac[e].x = (double)uu;
                tre_vac[e].y = -65;
            }
            else if(tre_vac[e].type==d){
                tre_vac[e].x = (double)uu;
                tre_vac[e].y = 1005;
            }
        else if(tre_vac[e].type==r){
                tre_vac[e].x = 1005;
                tre_vac[e].y = (double)uu;
            }
        else if(tre_vac[e].type==l){
                tre_vac[e].x = -65;
                tre_vac[e].y = (double)uu;
        }
    }
}
