#include "global.h"
#include "bullet_fire.h"
void treasure_init();
void treasure_process(ALLEGRO_EVENT event);
void treasure_update();
void treasure_draw();
void treasure_destory();
void treasure_restart();
#ifndef treasure_H
#define treasure_H
typedef struct treasure{
    double x, y; // the position of image
    int width, height; // the width and height of image
    bool life;
    float angle=0;
    //int eneblood=15;
    int type;
    int movetype;
    int times=0;
    float speed;
    ALLEGRO_BITMAP *img_tre;
    ALLEGRO_SAMPLE_INSTANCE *tre_sound;

}treasure;
enum{d=0,u,r,l};
extern  treasure tre_gun[10];
extern  treasure tre_vac[10];
#endif
