#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#include <stdio.h>
#include "algif.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_video.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// note that you can't assign initial value here!
extern const float FPS;
extern const float FPSforvid;
extern const int WIDTH;
extern float center_firex;
extern float center_firey;
extern int bulletani;
extern int razerbulletani;
extern int bulletloding;
extern int razerloding;
extern double fire_angle;
extern int level;
extern int totalene;
extern float lifebarlong;
extern float bulletbarlong;
extern int score;
extern int window;
extern int modeinm;
extern int Lethality;
extern int menu_recthickdif[3];
extern int menu_recthickvol[5];
extern int menu_recthickintor[2];
extern int menu_recthicklev[10];
extern int Blifebarlong;
extern int Bbulletbarlong;
extern bool flag;
extern bool warning;
struct track;
extern ALLEGRO_VIDEO* dievideo ;
//extern struct track entity;
extern const int HEIGHT;
extern bool key_state[ALLEGRO_KEY_MAX];
extern bool judge_next_window;
extern bool  music_play;
extern bool cease_razer_fire;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_FONT *font;
extern ALLEGRO_FONT *gamefont;
extern ALLEGRO_FONT *game2font ;
extern ALLEGRO_BITMAP *turnback;
extern ALLEGRO_DISPLAY* display ;
extern int timess;
extern int music_volume;
extern float speedprefig;
extern ALLEGRO_EVENT_QUEUE* videoq;
extern ALLEGRO_BITMAP *minusblood;
extern ALLEGRO_EVENT_SOURCE *tempvideo;
extern ALLEGRO_SAMPLE *song;
extern ALLEGRO_SAMPLE_INSTANCE *sample_instance;
extern ALLEGRO_SAMPLE *swin2;
extern ALLEGRO_SAMPLE_INSTANCE *sfwin2_instance;
extern ALLEGRO_SAMPLE *swin3;
extern ALLEGRO_SAMPLE_INSTANCE *sfwin3_instance;
extern ALLEGRO_SAMPLE *swin5;
extern ALLEGRO_SAMPLE_INSTANCE *sfwin5_instance;
extern ALLEGRO_SAMPLE *swin10;
extern ALLEGRO_SAMPLE_INSTANCE *sfwin10_instance;
extern ALLEGRO_SAMPLE *clicks;
extern ALLEGRO_SAMPLE_INSTANCE *sclick_instance;
extern ALLEGRO_SAMPLE *diemusic;
extern ALLEGRO_SAMPLE_INSTANCE *diemusic_instance;
extern ALLEGRO_SAMPLE *collider;
extern ALLEGRO_SAMPLE_INSTANCE *colli_instance;
extern ALLEGRO_SAMPLE *ha;
extern ALLEGRO_SAMPLE_INSTANCE *ha_instance;
//extern ALLEGRO_EVENT_QUEUE *event_queuebul;
extern ALLEGRO_TIMER *fps;
extern ALLEGRO_TIMER *fpsforvid;
extern ALGIF_ANIMATION *gifend;
extern ALGIF_ANIMATION *gameend;
#endif
