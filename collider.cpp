#include <math.h>
#include <time.h>
#include "enemy.h"
#include "bullet_fire.h"
#include "collider.h"
#include <stdlib.h>
#include "treasure.h"
#include "charater.h"
#include "bigbossbullet.h"
#include "bigboss.h"
void judge(){
    for(int o=0;o<bulletloding;o++){
        if(tra[o].bullet_live){
            for(int e=0;e<totalene;e++){
                if(ene[e].life){
                    if(ene[e].x<=(tra[o].x)&&(ene[e].x+60)>=(tra[o].x)&&(ene[e].y+60)>=(tra[o].y)&&ene[e].y<=(tra[o].y)){
                        tra[o].bullet_live=false;
                        tra[o].time=0;
                        ene[e].life=false;
                        if(score<50) score++;
                        srand(time(0));
                                int u=rand()%1000;
                                if(ene[e].type==up){
                                    ene[e].x = (double)u;
                                    ene[e].y = -65;
                                    }
                                else if(ene[e].type==down){
                                    ene[e].x = (double)u;
                                    ene[e].y = 1005;
                                    }
                                else if(ene[e].type==right){
                                    ene[e].x = 1005;
                                    ene[e].y = (double)u;
                                    }
                                else if(ene[e].type==left){
                                    ene[e].x = -65;
                                    ene[e].y = (double)u;
                        }
                    }
                }
            }
        }
    }
}
void judge_bu_tre_gun(){
    for(int o=0;o<bulletloding;o++){
        if(tra[o].bullet_live){
            for(int e=0;e<10;e++){
                if(tre_gun[e].life){
                    if(tre_gun[e].x<=(tra[o].x)&&(tre_gun[e].x+60)>=(tra[o].x)&&(tre_gun[e].y+60)>=(tra[o].y)&&tre_gun[e].y<=(tra[o].y)){
                        tra[o].bullet_live=false;
                        tra[o].time=0;
                        if(bulletbarlong<100){
                            if(bulletbarlong>=90) bulletbarlong=100;
                            else bulletbarlong+=10;
                        }
                        tre_gun[e].life=false;
                        if(score<50) score++;
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
                    }
                }
            }
        }
    }
}
void judge_bu_tre_vac(){
    for(int o=0;o<bulletloding;o++){
        if(tra[o].bullet_live){
            for(int e=0;e<10;e++){
                if(tre_vac[e].life){
                    if(tre_vac[e].x<=(tra[o].x)&&(tre_vac[e].x+60)>=(tra[o].x)&&(tre_vac[e].y+60)>=(tra[o].y)&&tre_vac[e].y<=(tra[o].y)){
                        tra[o].bullet_live=false;
                        tra[o].time=0;
                        if(lifebarlong<100){
                            if(lifebarlong>=95) lifebarlong=100;
                            else lifebarlong+=5;
                        }
                        tre_vac[e].life=false;
                        if(score<50) score++;
                        srand(time(0));
                                int u=rand()%1000;
                                if(tre_vac[e].type==u){
                                    tre_vac[e].x = (double)u;
                                    tre_vac[e].y = -65;
                                    }
                                else if(tre_vac[e].type==d){
                                    tre_vac[e].x = (double)u;
                                    tre_vac[e].y = 1005;
                                    }
                                else if(tre_vac[e].type==r){
                                    tre_vac[e].x = 1005;
                                    tre_vac[e].y = (double)u;
                                    }
                                else if(tre_vac[e].type==l){
                                    tre_vac[e].x = -65;
                                    tre_vac[e].y = (double)u;
                        }
                    }
                }
            }
        }
    }
}

void enecha(){
    int devide=0;
    for(int o=0;o<totalene;o++){
       if(ene[o].life){
        for(int f=0;f<5;f++){
            double r=pow((ene[o].x+f*12)-center_firex,2)+pow(ene[o].y-center_firey,2);
            if(r<=1500){
                al_play_sample_instance(colli_instance);
                flag=true;
                if(level!=10){
                    if(lifebarlong>0) lifebarlong-=level*Lethality;
                }
                else{
                    if(lifebarlong>0) lifebarlong-=Lethality;
                }
                ene[o].life=false;
                srand(time(0));
                int u=rand()%1000;
                if(ene[o].type==up){
                    ene[o].x = (double)u;
                    ene[o].y = -65;
                }
                else if(ene[o].type==down){
                    ene[o].x = (double)u;
                    ene[o].y = 1005;
                }
                else if(ene[o].type==right){
                    ene[o].x = 1005;
                    ene[o].y = (double)u;
                }
                else if(ene[o].type==left){
                    ene[o].x = -65;
                    ene[o].y = (double)u;
                }
                break;
            }
        }
        if(!ene[o].life) break;
        for(int f=0;f<5;f++){
            double r=pow((ene[o].x+f*12)-center_firex,2)+pow(ene[o].y+60-center_firey,2);
            if(r<=1500){
                al_play_sample_instance(colli_instance);
                flag=true;
                if(level!=10){
                    if(lifebarlong>0) lifebarlong-=level*Lethality;
                }
                else{
                    if(lifebarlong>0) lifebarlong-=Lethality;
                }
                ene[o].life=false;
                srand(time(0));
                int u=rand()%1000;
                if(ene[o].type==up){
                    ene[o].x = (double)u;
                    ene[o].y = -65;
                }
                else if(ene[o].type==down){
                    ene[o].x = (double)u;
                    ene[o].y = 1005;
                }
                else if(ene[o].type==right){
                    ene[o].x = 1005;
                    ene[o].y = (double)u;
                }
                else if(ene[o].type==left){
                    ene[o].x = -65;
                    ene[o].y = (double)u;
                }
                break;
            }
        }
        if(!ene[o].life) break;
        for(int f=0;f<5;f++){
            double r=pow((ene[o].y+f*12)-center_firey,2)+pow(ene[o].x-center_firex,2);
            if(r<=1500){
                al_play_sample_instance(colli_instance);
                flag=true;
                if(level!=10){
                    if(lifebarlong>0) lifebarlong-=level*Lethality;
                }
                else{
                    if(lifebarlong>0) lifebarlong-=Lethality;
                }
                ene[o].life=false;
                srand(time(0));
                int u=rand()%1000;
                if(ene[o].type==up){
                    ene[o].x = (double)u;
                    ene[o].y = -65;
                }
                else if(ene[o].type==down){
                    ene[o].x = (double)u;
                    ene[o].y = 1005;
                }
                else if(ene[o].type==right){
                    ene[o].x = 1005;
                    ene[o].y = (double)u;
                }
                else if(ene[o].type==left){
                    ene[o].x = -65;
                    ene[o].y = (double)u;
                }
                break;
            }
        }
        if(!ene[o].life) break;
        for(int f=0;f<5;f++){
            double r=pow((ene[o].y+f*12)-center_firey,2)+pow(ene[o].x+60-center_firex,2);
            if(r<=1500){
                al_play_sample_instance(colli_instance);
                flag=true;
                if(level!=10){
                    if(lifebarlong>0) lifebarlong-=level*Lethality;
                }
                else{
                    if(lifebarlong>0) lifebarlong-=Lethality;
                }

                ene[o].life=false;
                srand(time(0));
                int u=rand()%1000;
                if(ene[o].type==up){
                    ene[o].x = (double)u;
                    ene[o].y = -65;
                }
                else if(ene[o].type==down){
                    ene[o].x = (double)u;
                    ene[o].y = 1005;
                }
                else if(ene[o].type==right){
                    ene[o].x = 1005;
                    ene[o].y = (double)u;
                }
                else if(ene[o].type==left){
                    ene[o].x = -65;
                    ene[o].y = (double)u;
                }
                break;
            }
        }
        if(!ene[o].life) break;
       }
    }

}
int minanime=0,minanime_time=0;

void minublood_draw(){
    al_draw_bitmap(minusblood, 0, 0, 0);
    flag=false;
}
bool razerflag=false;
void bigbossrazercol(){
    for(int i=0;i<razerloding;i++){
        if(Brazer[i].Brazer_live){
            for(int o=1;o<=10;o++){
            double x=500*sin(Brazer[i].angle)/o;
            x+=Brazer[i].x;
            double y=500*cos(Brazer[i].angle)/o;
            y=Brazer[i].y-y;
            double bxc=bigboss19.x+bigboss19.width/2;
            double byc=bigboss19.y+bigboss19.height/2;
            double r=pow((x-bxc),2)+pow(y-byc,2);
            if(r<20000){
                razerflag=true;
                }
            }
            if(razerflag){
              Blifebarlong-=5;
              razerflag=false;
            }
        }
    }
}
void bullet_bosscol(){
    for(int o=0;o<bulletloding;o++){
        if(tra[o].bullet_live){
            if(bigboss19.life){
                if(bigboss19.x<=(tra[o].x)&&(bigboss19.x+190)>=(tra[o].x)&&(bigboss19.y+190)>=(tra[o].y)&&bigboss19.y<=(tra[o].y)){
                       tra[o].bullet_live=false;
                       tra[o].time=0;
                       Blifebarlong--;
                }
            }
        }
    }
}
void boss_charcol(){
int devide=0;
if(bigboss19.life&&bigboss19.big_anime==bigboss19.big_anime_time-1){
    if(devide==0){
        for(int f=0;f<20;f++){
            double r=pow((bigboss19.x+f*10)-center_firex,2)+pow(bigboss19.y-center_firey,2);
            if(r<=1500){
                flag=true;
                if(lifebarlong>0) lifebarlong-=(level*Lethality/5-10);
                devide=1;
                //printf("%d",(level*Lethality/5-10));
                break;

            }
        }
    }
    if(devide==0){
        for(int f=0;f<5;f++){
            double r=pow((bigboss19.x+f*10)-center_firex,2)+pow(bigboss19.y+200-center_firey,2);
            if(r<=1500){
                flag=true;
                if(lifebarlong>0) lifebarlong-=(level*Lethality/5-10);
                devide=1;
                break;
                //printf("%d",(level*Lethality/5-10));
            }
        }
    }
    if(devide==0){
        for(int f=0;f<5;f++){
            double r=pow((bigboss19.y+f*10)-center_firey,2)+pow(bigboss19.x-center_firex,2);
            if(r<=1500){
                flag=true;
                if(lifebarlong>0) lifebarlong-=(level*Lethality/5-10);
                devide=1;
                //printf("%d",(level*Lethality/5-10));
                break;

            }
        }
    }
    if(devide==0){
        for(int f=0;f<5;f++){
            double r=pow((bigboss19.y+f*10)-center_firey,2)+pow(bigboss19.x+200-center_firex,2);
            if(r<=1500){
                   // printf("sdf\n");
                flag=true;
                if(lifebarlong>0) lifebarlong-=(level*Lethality/5-10);
                //printf("%d",(level*Lethality/5-10));
                devide=1;
                break;
                }
            }
        }
        devide=0;
    }
}
bool razereneflag=false;
void razer_enecol(){
    for(int i=0;i<razerloding;i++){
        if(Brazer[i].Brazer_live){
            for(int k=0;k<totalene;k++){
                if(ene[k].life){
                for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x-20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=ene[k].x+ene[k].width/2;
                    double byc=ene[k].y+ene[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<920){
                    ene[u].life=false;
                    srand(time(0));
                    int u=rand()%1000;
                    if(ene[k].type==up){
                        ene[k].x = (double)u;
                        ene[k].y = -65;
                        }
                    else if(ene[k].type==down){
                        ene[k].x = (double)u;
                        ene[k].y = 1005;
                        }
                    else if(ene[k].type==right){
                        ene[k].x = 1005;
                        ene[k].y = (double)u;
                            }
                    else if(ene[k].type==left){
                        ene[k].x = -65;
                        ene[k].y = (double)u;
                            }
                        }
                    }
                    for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x+20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=ene[k].x+ene[k].width/2;
                    double byc=ene[k].y+ene[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<920){
                    ene[u].life=false;
                    srand(time(0));
                    int u=rand()%1000;
                    if(ene[k].type==up){
                        ene[k].x = (double)u;
                        ene[k].y = -65;
                        }
                    else if(ene[k].type==down){
                        ene[k].x = (double)u;
                        ene[k].y = 1005;
                        }
                    else if(ene[k].type==right){
                        ene[k].x = 1005;
                        ene[k].y = (double)u;
                            }
                    else if(ene[k].type==left){
                        ene[k].x = -65;
                        ene[k].y = (double)u;
                            }
                        }
                    }
                }
            }
        }
    }
}
void razer_vaccol(){
    for(int i=0;i<razerloding;i++){
        if(Brazer[i].Brazer_live){
            for(int k=0;k<10;k++){
                if(tre_vac[k].life){
                for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x-20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=tre_vac[k].x+tre_vac[k].width/2;
                    double byc=tre_vac[k].y+tre_vac[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<920){
                    if(lifebarlong>=95) lifebarlong=100;
                    else lifebarlong+=5;
                    tre_vac[k].life=false;
                                srand(time(0));
                                int u=rand()%1000;
                                if(tre_vac[k].type==u){
                                    tre_vac[k].x = (double)u;
                                    tre_vac[k].y = -65;
                                    }
                                else if(tre_vac[k].type==d){
                                    tre_vac[k].x = (double)u;
                                    tre_vac[k].y = 1005;
                                    }
                                else if(tre_vac[k].type==r){
                                    tre_vac[k].x = 1005;
                                    tre_vac[k].y = (double)u;
                                    }
                                else if(tre_vac[k].type==l){
                                    tre_vac[k].x = -65;
                                    tre_vac[k].y = (double)u;
                            }
                            break;
                        }
                    }
                    for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x+20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=tre_vac[k].x+tre_vac[k].width/2;
                    double byc=tre_vac[k].x+tre_vac[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<920){
                    if(lifebarlong>=95) lifebarlong=100;
                    else lifebarlong+=5;
                    tre_vac[k].life=false;
                    srand(time(0));
                                int u=rand()%1000;
                                if(tre_vac[k].type==u){
                                    tre_vac[k].x = (double)u;
                                    tre_vac[k].y = -65;
                                    }
                                else if(tre_vac[k].type==d){
                                    tre_vac[k].x = (double)u;
                                    tre_vac[k].y = 1005;
                                    }
                                else if(tre_vac[k].type==r){
                                    tre_vac[k].x = 1005;
                                    tre_vac[k].y = (double)u;
                                    }
                                else if(tre_vac[k].type==l){
                                    tre_vac[k].x = -65;
                                    tre_vac[k].y = (double)u;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
void razer_guncol(){
    for(int i=0;i<razerloding;i++){
        if(Brazer[i].Brazer_live){
            for(int k=0;k<10;k++){
                if(tre_gun[k].life){
                for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x-20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=tre_gun[k].x+tre_gun[k].width/2;
                    double byc=tre_gun[k].y+tre_gun[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<920){
                    if(lifebarlong>=95) lifebarlong=100;
                    else lifebarlong+=5;
                    tre_gun[k].life=false;
                                srand(time(0));
                                int u=rand()%1000;
                                if(tre_gun[k].type==u){
                                    tre_gun[k].x = (double)u;
                                    tre_gun[k].y = -65;
                                    }
                                else if(tre_gun[k].type==d){
                                    tre_gun[k].x = (double)u;
                                    tre_gun[k].y = 1005;
                                    }
                                else if(tre_gun[k].type==r){
                                    tre_gun[k].x = 1005;
                                    tre_gun[k].y = (double)u;
                                    }
                                else if(tre_gun[k].type==l){
                                    tre_gun[k].x = -65;
                                    tre_gun[k].y = (double)u;
                            }
                            break;
                        }
                    }
                    for(int o=1;o<=10;o++){
                    double x=500*sin(Brazer[i].angle)/o;
                    x+=(Brazer[i].x+20);
                    double y=500*cos(Brazer[i].angle)/o;
                    y=Brazer[i].y-y;
                    double bxc=tre_gun[k].x+tre_gun[k].width/2;
                    double byc=tre_gun[k].x+tre_gun[k].height/2;
                    double r=pow((x-bxc),2)+pow(y-byc,2);
                    if(r<900){
                    if(lifebarlong>=95) lifebarlong=100;
                    else lifebarlong+=5;
                    tre_gun[k].life=false;
                    srand(time(0));
                                int u=rand()%1000;
                                if(tre_gun[k].type==u){
                                    tre_gun[k].x = (double)u;
                                    tre_gun[k].y = -65;
                                    }
                                else if(tre_gun[k].type==d){
                                    tre_gun[k].x = (double)u;
                                    tre_gun[k].y = 1005;
                                    }
                                else if(tre_gun[k].type==r){
                                    tre_gun[k].x = 1005;
                                    tre_gun[k].y = (double)u;
                                    }
                                else if(tre_gun[k].type==l){
                                    tre_gun[k].x = -65;
                                    tre_gun[k].y = (double)u;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

