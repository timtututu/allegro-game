#include "scene.h"
#include"bullet_fire.h"
#include "collider.h"

ALLEGRO_BITMAP *background[10] = {NULL};
ALLEGRO_BITMAP *menubackground = NULL;
ALLEGRO_MOUSE_STATE state;
ALLEGRO_EVENT next;
int moveupdowm=450;//y1
int moverightleft=400;//x1
int widthre=520;//x2
int leftre=480;//y2
float xmenu=0,ymenu=0;
bool judgemouse=false;
void menu_init(){
    font = al_load_ttf_font("./font/pirulen.ttf",30,0);
}
void menu_process(ALLEGRO_EVENT event){

    if( window==1 ){
        if(event.type==ALLEGRO_EVENT_MOUSE_AXES&&judgemouse==false){
            xmenu=event.mouse.x;
            ymenu=event.mouse.y;
            while(al_peek_next_event(event_queue,&next)&&next.type==ALLEGRO_EVENT_MOUSE_AXES&&next.timer.source==event.timer.source){
                al_drop_next_event(event_queue);
                //printf("out\n");
            }
        }
        else if(event.type ==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN&&judgemouse==false){
            if(event.mouse.button& 1){
               moverightleft=xmenu;
               moveupdowm=ymenu;
                judgeprefig(moverightleft,moveupdowm);
                al_play_sample_instance(sclick_instance);
            }

        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            judge_next_window = true;
            al_stop_sample_instance(sample_instance);
            music_play=true;
        }
    }
    else if(window==3){
            if( event.keyboard.keycode == ALLEGRO_KEY_SPACE ){
                    judge_next_window = true;
                    al_stop_sample_instance(sfwin3_instance);
                    music_play=true;
            }
            else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    window = 1;
                    level=1;
                    al_stop_sample_instance(sfwin3_instance);
                    music_play=true;
            }
    }
}
void menu_draw(){
    if(window==1){
            menubackground = al_load_bitmap("./image/virus.jpg");
            al_draw_bitmap(menubackground, 0, 0, 0);
            menurectdraw();
    }
    else if(window==3){
            //printf("here\n");
            turnback=al_load_bitmap("./image/turnbackground.png");
            al_draw_bitmap(turnback, 0, 0, 0);
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+150 , ALLEGRO_ALIGN_CENTRE, "Press 'Space' to next level");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2-150 , ALLEGRO_ALIGN_CENTRE, "Press 'ESC' back to menu");
    }
}
void menurectdraw(){
            font = al_load_ttf_font("./font/pirulen.ttf",30,0);
            al_draw_filled_rectangle(xmenu,ymenu,xmenu+10,ymenu+10, al_map_rgb(	0,0,200));
            //volume
            al_draw_rectangle(380,350,420,390, al_map_rgb(75,238,238),menu_recthickvol[0]);//1
            al_draw_rectangle(430,350,470,390, al_map_rgb(75,238,238),menu_recthickvol[1]);//2
            al_draw_rectangle(485,350,525,390, al_map_rgb(75,238,238),menu_recthickvol[2]);//3
            al_draw_rectangle(540,350,580,390, al_map_rgb(75,238,238),menu_recthickvol[3]);//4
            al_draw_rectangle(590,350,630,390, al_map_rgb(75,238,238),menu_recthickvol[4]);//5

            al_draw_rectangle(390,440,520,490, al_map_rgb(75,238,238),menu_recthickdif[0]);
            al_draw_rectangle(540,440,720,490, al_map_rgb(75,238,238),menu_recthickdif[1]);
            al_draw_rectangle(740,440,950,490, al_map_rgb(75,238,238),menu_recthickdif[2]);
            al_draw_rectangle(380,595,420,635, al_map_rgb(75,238,238),menu_recthicklev[0]);//1
            al_draw_rectangle(430,595,470,635, al_map_rgb(75,238,238),menu_recthicklev[1]);//2
            al_draw_rectangle(485,595,525,635, al_map_rgb(75,238,238),menu_recthicklev[2]);//3
            al_draw_rectangle(540,595,580,635, al_map_rgb(75,238,238),menu_recthicklev[3]);//4
            al_draw_rectangle(590,595,630,635, al_map_rgb(75,238,238),menu_recthicklev[4]);//5

            al_draw_rectangle(370,645,410,685, al_map_rgb(75,238,238),menu_recthicklev[5]);//6
            al_draw_rectangle(430,645,470,685, al_map_rgb(75,238,238),menu_recthicklev[6]);//7
            al_draw_rectangle(485,645,525,685, al_map_rgb(75,238,238),menu_recthicklev[7]);//8
            al_draw_rectangle(540,645,580,685, al_map_rgb(75,238,238),menu_recthicklev[8]);//9
            al_draw_rectangle(600,645,645,685, al_map_rgb(75,238,238),menu_recthicklev[9]);//10
            //in
            al_draw_rectangle(365,735,555,775, al_map_rgb(75,238,238),menu_recthickintor[0]);
            al_draw_rectangle(580,735,805,775, al_map_rgb(75,238,238),menu_recthickintor[1]);

            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2-250, HEIGHT/2-150 , ALLEGRO_ALIGN_CENTRE, "Volume:");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2-150 , ALLEGRO_ALIGN_CENTRE, " 1  2  3  4  5");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2-250, HEIGHT/2-50 , ALLEGRO_ALIGN_CENTRE, "Difficulty:");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2-100, HEIGHT/2-50 , ALLEGRO_ALIGN_LEFT, "EASY  Medium  Difficult");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+50 , ALLEGRO_ALIGN_CENTRE, "Level:");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+100 , ALLEGRO_ALIGN_CENTRE, " 1  2  3  4  5");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+150 , ALLEGRO_ALIGN_CENTRE, " 6  7  8  9  10");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+240 , ALLEGRO_ALIGN_CENTRE, "MODE   Normal  Invincible");
            al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+310 , ALLEGRO_ALIGN_CENTRE, "Press 'Enter' to start");
}
void menu_destroy(){
    if(window==1){
      al_destroy_bitmap(menubackground);
      al_start_timer(fps);
      moverightleft=0;
      moveupdowm=0;
      if(level==10) window=10;
      else window = 2;
      timess=0;
      //printf("destory1\n");
    }
    else if(window==3){
      al_destroy_bitmap(turnback);
      al_start_timer(fps);
      //printf("destory\n");
      timess=0;
    }
}

void game_scene_init(){

    font = al_load_ttf_font("./font/pirulen.ttf",20,0);
    character_init();
    bullet_init();
    enemy_init();
    treasure_init();
    bigboss_init();
    bigbossbullet_init();
    for(int i=1;i<=10;i++){
        char temp[50];
        sprintf( temp, "./image/level%dbackground.png", i );
        background[i-1] = al_load_bitmap(temp);
    }

}
void game_scene_draw(){
    if(level==10){
    al_draw_bitmap(background[level-1], 0, 0, 0);
    al_draw_text(font, al_map_rgb(255,255,255), 700, 100 , ALLEGRO_ALIGN_LEFT, "Life");
    al_draw_text(font, al_map_rgb(255,255,255), 660, 70 , ALLEGRO_ALIGN_LEFT, "Bullet");
    al_draw_text(font, al_map_rgb(255,255,255), 5, 40 , ALLEGRO_ALIGN_LEFT, "Boss");
    bigboss_draw();
    //bigbosschar_draw();
    bigbossbullet_draw();
    character_draw();
    treasure_draw();
    bullet_draw();
    enemy_draw();
    bigboss_scoreboarddraw();
    if(warning) warning_razer();
    if(flag) minublood_draw();
    }
    else {
    al_draw_bitmap(background[level-1], 0, 0, 0);
    al_draw_text(font, al_map_rgb(255,255,255), 700, 40 , ALLEGRO_ALIGN_LEFT, "Life");
    al_draw_text(font, al_map_rgb(255,255,255), 660, 70 , ALLEGRO_ALIGN_LEFT, "Bullet");
    if(flag) minublood_draw();
    character_draw();
    enemy_draw();
    bullet_draw();
    scoredraw();
    treasure_draw();
    }
    al_flip_display();
}
void game_scene_destroy(){
    for(int i=1;i<=10;i++){
        al_destroy_bitmap(background[i-1]);
    }

    character_destory();
    bullet_destory();
    enemy_destory();
    scoredestory();
    treasure_destory();
    bigboss_destory();
    //bigbosschar_destory();
    bigbossbullet_destory();
}
