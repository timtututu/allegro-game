#include "global.h"
#include "bullet_fire.h"
void enemy_init();
void enemy_process(ALLEGRO_EVENT event);
void enemy_update();
void enemy_draw();
void enemy_destory();
void enemy_restart();
#ifndef ENEMY_H
#define ENEMY_H
typedef struct enemy_evelevel{
    double x, y; // the position of image
    int width, height; // the width and height of image
    bool life; // left: false, right: true
    float angle=0;
    int eneblood=15;
    int type;
    int movetype;
    int times=0;
    float speed;
    ALLEGRO_BITMAP *img_enemy[10];
    ALLEGRO_SAMPLE_INSTANCE *vir_sound;

}ene_eve;
enum{down=0,up,right,left};
extern ene_eve ene[50];
#endif
