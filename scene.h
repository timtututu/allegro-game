#include "global.h"
#include "charater.h"
#include "bullet_fire.h"
#include "enemy.h"
#include "scorecount.h"
#include "treasure.h"
#include "video_end_game.h"
#include "menuclick.h"
#include "bigboss.h"
#include "bigbosschara.h"
#include "bigbossbullet.h"
void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();
void menurectdraw();
void game_scene_init();
void game_scene_draw();
void game_scene_destroy();