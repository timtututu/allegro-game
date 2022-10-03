#include "global.h"

// variables for global usage
const float FPS = 60.0;
const float FPSforvid=180.0;
const int WIDTH = 1000;
const int HEIGHT = 1000;
int menu_recthickdif[3]={0};
int menu_recthicklev[10]={0};
int menu_recthickvol[5]={0};
int menu_recthickintor[2]={0};
float center_firex=540;
float center_firey=540;
int bulletani=0;
int razerbulletani=0;
int bulletloding=100;
int razerloding=10;
int modeinm=0;//0nor 1in
double  fire_angle=0;
int level=1;
int totalene=50;
float lifebarlong=100;
float bulletbarlong=100;
int Blifebarlong=500;
int Bbulletbarlong=100;
int window = 1;
int score=0;
int Lethality=10;
int timess=0;
int music_volume=1;
float speedprefig=0;
bool flag=false;
bool warning=false;
bool music_play=true;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance=NULL;
ALLEGRO_SAMPLE *swin2=NULL;
ALLEGRO_SAMPLE_INSTANCE *sfwin2_instance=NULL;
ALLEGRO_SAMPLE *swin3=NULL;
ALLEGRO_SAMPLE_INSTANCE *sfwin3_instance=NULL;
ALLEGRO_SAMPLE *swin5=NULL;
ALLEGRO_SAMPLE_INSTANCE *sfwin5_instance=NULL;
ALLEGRO_SAMPLE *swin10=NULL;
ALLEGRO_SAMPLE_INSTANCE *sfwin10_instance=NULL;
ALLEGRO_SAMPLE *clicks=NULL;
ALLEGRO_SAMPLE_INSTANCE *sclick_instance=NULL;
ALLEGRO_SAMPLE *diemusic=NULL;
ALLEGRO_SAMPLE_INSTANCE *diemusic_instance=NULL;
ALLEGRO_SAMPLE *collider=NULL;
ALLEGRO_SAMPLE_INSTANCE *colli_instance=NULL;
ALLEGRO_SAMPLE *ha=NULL;
ALLEGRO_SAMPLE_INSTANCE *ha_instance=NULL;


ALLEGRO_BITMAP *minusblood=NULL;
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_VIDEO* dievideo = NULL;
ALLEGRO_EVENT_QUEUE* videoq=NULL;
ALLEGRO_BITMAP *turnback=NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
ALLEGRO_TIMER *fpsforvid = NULL;
ALLEGRO_FONT *font =NULL;
ALLEGRO_FONT *gamefont = NULL;
ALLEGRO_FONT *game2font = NULL;
ALGIF_ANIMATION *gifend=NULL;
ALGIF_ANIMATION *gameend=NULL;
ALLEGRO_EVENT_SOURCE *tempvideo=NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
bool judge_next_window = false;
bool cease_razer_fire = true;


