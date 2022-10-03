#include "global.h"
void bigboss_init();
void bigboss_destory();
void bigbossenemy_update();
void bigbossenemy_process(ALLEGRO_EVENT event);
void bigboss_draw();
void bigboss_restart();
void bigboss_scoreboarddraw();
void bigboss_scoreupdate();
#ifndef BIG_ENEMY_H
#define BIG_ENEMY_H
typedef struct {
    double x, y; // the position of image
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    bool life;
    ALLEGRO_BITMAP *img_bigboss;
    float speed;
    int type;
    int big_anime;
    int big_anime_time;
}bigbossenemy;

enum{bigdown=0,bigup,bigright,bigleft};
extern bigbossenemy bigboss19;
#endif
