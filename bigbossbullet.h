#include "global.h"

void bigbossbullet_init();
void bigbossbullet_process(ALLEGRO_EVENT);
void bigbossbullet_update();
void bigbossbullet_draw();
void bigbossbullet_destory();
void bigbossbullet_restart();
void razer_accept();
void warning_razer();
#ifndef BBULLET_H
#define BBULLET_H
struct razertrack{
    double x, y; // the position of image
    int width, height; // the width and height of image
    //bool dir; // left: false, right: true
    //int state; // the state of character
    double angle=0;
    int time=0;
    //int turnrate=30;
    ALLEGRO_BITMAP *razer_img[6];
    //ALLEGRO_BITMAP *img_atk[2];
    //ALLEGRO_SAMPLE_INSTANCE *bullet_Sound;
    int anime_tr; // counting the time of animation
    bool Brazer_live=false;
    int anime_time_tr;// indicate how long the animation
};
extern razertrack Brazer[10];
#endif

