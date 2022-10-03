#include"enemy.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
//enum{down=0,up,right,left};
enum{moven1=0,moven2,moven3,moven4,moven5,moven6,moven7,moven8};
ene_eve ene[50];
int enemymak; // counting the time of animation
int enemymak_time; // indicate how long the animation
int numvirus=0;

int randomflyang=0;
ALLEGRO_SAMPLE *sam = NULL;
void enemy_init(){
    srand(time(0));


    // load character images
    for(int o=0;o<totalene;o++){
        ene[o].speed=0.5*level+speedprefig;
        if(level==10) ene[o].speed=1.5;
        int u=rand()%1000;
        for(int i = 1 ; i <= 10 ; i++){
        char temp[55];
        sprintf( temp, "./image/vires_level%d.png",i);
        ene[o].img_enemy[i-1] = al_load_bitmap(temp);
    }
    //printf("here\n");
    // load effective sound
    /*sam = al_load_sample("./sound/atk_sound.wav");
    ene.vir_sound  = al_create_sample_instance(sam);
    al_set_sample_instance_playmode(ene.vir_sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ene.vir_sound, al_get_default_mixer());*/

    // initial the geometric information of character
    ene[o].width = al_get_bitmap_width(ene[o].img_enemy[level-1]);
    ene[o].height = al_get_bitmap_height(ene[o].img_enemy[level-1]);
    if(o%4==0){
       ene[o].x = -60;
       ene[o].y = (double)u;
       ene[o].type=left;
    }
    else if(o%4==1){
       ene[o].x = 1000;
       ene[o].y = (double)u;
       ene[o].type=right;
    }
    else if(o%4==2){
       ene[o].x = (double)u;
       ene[o].y = -60;
       ene[o].type=up;
    }
    else if(o%4==3){
       ene[o].x = (double)u;
       ene[o].y = 1000;
       ene[o].type=down;
    }
    ene[o].life = false;

    }
    // initial the animation component
    enemymak = 0;
    enemymak_time = 30;
    //printf("%d %f %f aasdf\n",1,ene[1].x,ene[1].y);
}
void enemy_process(ALLEGRO_EVENT event){
    for(int o=0;o<totalene;o++){
    int u=rand()%1000;
    if(ene[o].x>1000){
        ene[o].times=0;
        ene[o].life=false;
            if(ene[o].type==up){
                ene[o].x = (double)u;
                ene[o].y = -60;
                //printf("ad");
            }
            else if(ene[o].type==down){
                ene[o].x = (double)u;
                ene[o].y = 1000;
            }
            else if(ene[o].type==right){
                ene[o].x = 1000;
                ene[o].y = (double)u;
            }
            else if(ene[o].type==left){
                ene[o].x = -60;
                ene[o].y = (double)u;
            }
    }
    if(ene[o].y>1000){
        ene[o].times=0;
        ene[o].life=false;
            if(ene[o].type==up){
                ene[o].x = (double)u;
                ene[o].y = -60;
            }
            else if(ene[o].type==down){
                ene[o].x = (double)u;
                ene[o].y = 1000;
            }
            else if(ene[o].type==right){
                ene[o].x = 1000;
                ene[o].y = (double)u;
            }
            else if(ene[o].type==left){
                ene[o].x = -60;
                ene[o].y = (double)u;
            }
    }

    if(ene[o].x<-60){
        ene[o].times=0;
        ene[o].life=false;
            if(ene[o].type==up){
                ene[o].x = (double)u;
                ene[o].y = -60;
            }
            else if(ene[o].type==down){
                ene[o].x = (double)u;
                ene[o].y = 1000;
            }
            else if(ene[o].type==right){
                ene[o].x = 1000;
                ene[o].y = (double)u;
            }
            else if(ene[o].type==left){
                ene[o].x = -60;
                ene[o].y = (double)u;
            }
    }
    if(ene[o].y<-60){
        ene[o].times=0;
        ene[o].life=false;
            if(ene[o].type==up){
                ene[o].x = (double)u;
                ene[o].y =-60;
            }
            else if(ene[o].type==down){
                ene[o].x = (double)u;
                ene[o].y = 1000;
            }
            else if(ene[o].type==right){
                ene[o].x = 1000;
                ene[o].y = (double)u;
            }
            else if(ene[o].type==left){
                ene[o].x = -60;
                ene[o].y = (double)u;
            }
    }
    }
    if( event.type == ALLEGRO_EVENT_TIMER ){
        if( event.timer.source == fps ){
            enemymak++;
            enemymak %= enemymak_time;
        }
    }
}
double x[155];///////////////////////////////////////remember to change
double y[155];
void enemy_update(){
    int temp;
    if(enemymak==enemymak_time-1&&numvirus<totalene){
        ene[numvirus].life=true;
        numvirus++;
        if(numvirus==totalene) numvirus=0;
    }
    srand(time(0));
    for(int o=0;o<totalene;o++){
        int u=rand();
        if(ene[o].life){
            if(ene[o].times==0){
                 x[o]=abs(sin(u));
                 y[o]=abs(cos(u+10));

            if(ene[o].type==up){
                if(ene[o].x>500){
                    ene[o].movetype=moven1;
                }
                else{
                    ene[o].movetype=moven2;
                }
            }
            else if(ene[o].type==down){
                if(ene[o].x>500){
                    ene[o].movetype=moven3;
                }
                else{
                    ene[o].movetype=moven4;
                }
            }
            else if(ene[o].type==right){
                if(ene[o].y>500){
                    ene[o].movetype=moven5;
                }
                else{
                    ene[o].movetype=moven6;
                }
            }
            else if(ene[o].type==left){
                if(ene[o].y>500){
                    ene[o].movetype=moven7;
                }
                else{
                    ene[o].movetype=moven8;
                    }
                }
            }
        if(ene[o].movetype==moven1){
            ene[o].x -=x[o]*ene[o].speed;
            ene[o].y +=y[o]*ene[o].speed;
            ene[o].times++;
        }
        else if(ene[o].movetype==moven2){
            ene[o].x +=x[o]*ene[o].speed;
            ene[o].y +=y[o]*ene[o].speed;
            ene[o].times++;
        }
        else if(ene[o].movetype==moven3){
            ene[o].x -=x[o]*ene[o].speed;
            ene[o].y -=y[o]*ene[o].speed;
            ene[o].times++;

        }
        else if(ene[o].movetype==moven4){
            ene[o].x +=x[o]*ene[o].speed;
            ene[o].y -=y[o]*ene[o].speed;
            ene[o].times++;
        }
        else if(ene[o].movetype==moven5){
            ene[o].x -=x[o]*ene[o].speed;
            ene[o].y -=y[o]*ene[o].speed;
            ene[o].times++;

        }
        else if(ene[o].movetype==moven6){
            ene[o].x -=x[o]*ene[o].speed;
            ene[o].y +=y[o]*ene[o].speed;
            ene[o].times++;

        }
        else if(ene[o].movetype==moven7){
            ene[o].x +=x[o]*ene[o].speed;
            ene[o].y -=y[o]*ene[o].speed;
            ene[o].times++;

        }
        else if(ene[o].movetype==moven8){
            ene[o].x +=x[o]*ene[o].speed;
            ene[o].y +=y[o]*ene[o].speed;
            ene[o].times++;
        }
    }
    }
}
void enemy_draw(){
    for(int o=0;o<totalene;o++){
        if(ene[o].life){
                //printf("asdfasdf");
            al_draw_bitmap(ene[o].img_enemy[level-1], ene[o].x,ene[o].y , 0);

        }
    }
    //printf("%d %d enemy position\n ",ene[0].x,ene[0].y);
}
void enemy_destory(){
    for(int i=0;i<totalene;i++){
        for(int i=0;i<2;i++){
        al_destroy_bitmap(ene[i].img_enemy[i]);
        }
    }
}
void enemy_restart(){
    for(int o=0;o<totalene;o++){
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
    }

}

