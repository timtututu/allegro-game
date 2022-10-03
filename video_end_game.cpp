#include "video_end_game.h"
#include "time.h"
/*void vedioprocess(ALLEGRO_EVENT event){
    int x=0;
    time_t en;
    time_t start=clock();
    while(1){
      if(event.type==ALLEGRO_EVENT_TIMER){
       dievideo_f(dievideo);
        en=clock();
        //if((en-start)/CLOCKS_PER_SEC>7) break;
    }
    else if(event.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
            printf("adsfasfd\n");
        al_close_video(dievideo);
        break;
    }
    else if(event.type==ALLEGRO_EVENT_VIDEO_FINISHED){
            printf("adsfasfd\n");
        break;
        }
    }
   // printf("adsfasfd\n");
//destory_video();
}
void dievideo_f(ALLEGRO_VIDEO* dievideo){

   ALLEGRO_BITMAP *fr=al_get_video_frame(dievideo);
    if ( !fr)
        return;
   al_draw_scaled_bitmap(fr,
                        0,0,
                        al_get_bitmap_width(fr),
                        al_get_bitmap_height(fr),
                        0,0,
                        al_get_display_width(display),
                        al_get_display_height(display),0

   );
   al_flip_display();
}
void video_begin(){
    al_reserve_samples(1);
    al_start_video(dievideo,al_get_default_mixer());
    al_start_timer(fpsforvid);
}
void destory_video(){
    al_destroy_event_queue(videoq);
}*/
void haending(){
    time_t e;
    time_t s=clock();
    //printf("adf\n");
    al_play_sample_instance(ha_instance);
    while((e-s)/CLOCKS_PER_SEC<=5){
        al_draw_filled_rectangle(0, 0, 1000, 1000, al_map_rgb(0,0,0));
        al_draw_bitmap(algif_get_bitmap(gifend, al_get_time()),300,300, 0);
        al_flip_display();
        e=clock();
    }
}
void dievid(){
    time_t e;
    time_t s=clock();
    //printf("in \n");
     al_play_sample_instance(diemusic_instance);
    while((e-s)/CLOCKS_PER_SEC<=10){
        al_draw_filled_rectangle(0, 0, 1000, 1000, al_map_rgb(0,0,0));
        al_draw_bitmap(algif_get_bitmap(gameend, al_get_time()),250,300, 0);
        al_flip_display();
        e=clock();
    }
}
