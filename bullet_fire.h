#include "global.h"

void bullet_init();
void bullet_process(ALLEGRO_EVENT);
void bullet_update();
void bullet_draw();
void bullet_destory();
void bullet_restart();
#ifndef BULLET_H
#define BULLET_H
 struct track
{
    double x, y; // the position of image
    int width, height; // the width and height of image
    //bool dir; // left: false, right: true
    //int state; // the state of character
    double angle=0;
    int time=0;
    //int turnrate=30;
    ALLEGRO_BITMAP *bullet_img[2];
    //ALLEGRO_BITMAP *img_atk[2];
    //ALLEGRO_SAMPLE_INSTANCE *bullet_Sound;
    int anime_tr; // counting the time of animation
    bool bullet_live=false;
    int anime_time_tr;// indicate how long the animation
};
extern track tra[100];
#endif
