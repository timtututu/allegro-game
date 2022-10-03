#include "GameWindow.h"

bool draw = false;

const char *title = "Final Project 109034030 & 109034023";
const char *vedioname="./video/die.ogv";

// ALLEGRO Variables
int Game_establish() {
    int tt=0;
    int msg = 0;
    //key_state[ALLEGRO_KEY_SPACE] = true;
        game_init();
        game_begin();
        window=1;
        while ( msg != GAME_TERMINATE &&msg!=-100) {
        if(timess==1){
               // printf("in\n");
       // printf("%d\n",level);
         nextlevelkeyre();
        }
        //printf("%d ww\n",window);
        msg = game_run();

        if ( msg == GAME_TERMINATE ){
            printf( "Game Over\n" );
            }
        else if(msg==-100){
        if(level==10) al_stop_sample_instance(sfwin10_instance);
         else  al_stop_sample_instance(sfwin2_instance);

            music_play=true;
           /* ALLEGRO_EVENT videoeve;
            video_begin();
            al_wait_for_event(videoq,&videoeve);
            vedioprocess(videoeve);
            al_stop_timer(fps);
            al_stop_timer(fpsforvid);

            //al_flush_event_queue(videoq);
            tempvideo=al_get_video_event_source(dievideo);*/
            dievid();

            enemy_restart();
            chara_restart();
            bullet_restart();
            treasure_restart();
            bigboss_restart();
            bigbossbullet_restart();
            newlevel();
            window = 1;level=1;timess=1;
            msg=0;
            }
         else if(msg==-10){
            al_stop_sample_instance(sfwin10_instance);
            music_play=true;
            haending();

            enemy_restart();
            chara_restart();
            bullet_restart();
            treasure_restart();
            bigboss_restart();
            bigbossbullet_restart();
            newlevel();
            Blifebarlong=500;
            window = 1;level=1;timess=1;
            msg=0;
            }
        }

    game_destroy();

    return 0;
}

void game_init() {
    printf( "Game Initializing...\n" );
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    //video
    al_init_video_addon();
    dievideo = al_open_video(vedioname);
    if( dievideo )
        printf("read video succeed\n");
    else
        printf("read video fail!!!!\n");

    tempvideo=al_get_video_event_source(dievideo);
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    videoq = al_create_event_queue();
    //event_queuebul = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_video_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
   // al_register_event_source(videoq,tempvideo);
    //al_register_event_source(videoq, al_get_display_event_source( display ));


    fps  = al_create_timer( 1.0 / FPS );
    fpsforvid  = al_create_timer( 1.0 / FPSforvid );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;
    al_register_event_source(videoq, al_get_timer_event_source( fpsforvid)) ;
    //music
    swin2 = al_load_sample("./sound/win2.wav");
    al_reserve_samples(20);
    sfwin2_instance = al_create_sample_instance(swin2);
    al_set_sample_instance_playmode(sfwin2_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sfwin2_instance, al_get_default_mixer());
    al_set_sample_instance_gain(sfwin2_instance, music_volume);

    swin3 = al_load_sample("./sound/win3.wav");
    al_reserve_samples(20);
    sfwin3_instance = al_create_sample_instance(swin3);
    al_set_sample_instance_playmode(sfwin3_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sfwin3_instance, al_get_default_mixer());
    al_set_sample_instance_gain(sfwin3_instance, music_volume);

    swin10 = al_load_sample("./sound/win10.wav");
    al_reserve_samples(20);
    sfwin10_instance = al_create_sample_instance(swin10);
    al_set_sample_instance_playmode(sfwin10_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sfwin10_instance, al_get_default_mixer());
    al_set_sample_instance_gain(sfwin10_instance, music_volume);

    clicks = al_load_sample("./sound/click.wav");
    al_reserve_samples(20);
    sclick_instance = al_create_sample_instance(clicks);
    al_set_sample_instance_playmode(sclick_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(sclick_instance, al_get_default_mixer());
    al_set_sample_instance_gain(sclick_instance, music_volume+2);

    diemusic = al_load_sample("./sound/diemus.wav");
    al_reserve_samples(20);
    diemusic_instance = al_create_sample_instance(diemusic);
    al_set_sample_instance_playmode(diemusic_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(diemusic_instance, al_get_default_mixer());
    al_set_sample_instance_gain(diemusic_instance, music_volume);

    collider = al_load_sample("./sound/collider.wav");
    al_reserve_samples(20);
    colli_instance = al_create_sample_instance(collider);
    al_set_sample_instance_playmode(colli_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(colli_instance, al_get_default_mixer());
    al_set_sample_instance_gain(colli_instance, music_volume);

    ha = al_load_sample("./sound/ha.wav");
    al_reserve_samples(20);
    ha_instance = al_create_sample_instance(ha);
    al_set_sample_instance_playmode(ha_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ha_instance, al_get_default_mixer());
    al_set_sample_instance_gain(ha_instance, music_volume);
    //picture
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.jpg");
    minusblood = al_load_bitmap("./image/bloodframe.png");
    gifend = algif_load_animation("./image/haend.gif");
    gameend=algif_load_animation("./image/gameend.gif");
    al_set_display_icon(display, icon);
}
void game_begin() {
    // Load sound
    song = al_load_sample("./sound/hello.wav");
    sample_instance = al_create_sample_instance(song);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, music_volume) ;
    //al_start_timer(fps);
    // initialize the menu before entering the loop
    menu_init();

}
void game_update(){
    if( judge_next_window ){

        if( window == 1){
            al_flush_event_queue(event_queue);
           // if(al_is_event_queue_empty(event_queue)) printf("sdf\n");
            menu_destroy();
            game_scene_init();
            enemy_restart();
            chara_restart();
            bullet_restart();
            treasure_restart();
            newlevel();
            bigboss_restart();
            bigbossbullet_restart();
            if(level==10) window=10;
            else window = 2;
            key_state[ALLEGRO_KEY_MAX] = {false};
        }
        else if(window==3){
            al_flush_event_queue(event_queue);
        //if(al_is_event_queue_empty(event_queue)) printf("sdf\n");
            menu_destroy();
            game_scene_init();
            enemy_restart();
            chara_restart();
            bullet_restart();
            treasure_restart();
            bigboss_restart();
            //bigbosschar_restart();
            bigbossbullet_restart();
            newlevel();
            if(level==10) window=10;
            else window = 2;
            key_state[ALLEGRO_KEY_MAX] = {false};
        }
    }
    else if( window == 2 ){
        judge();
        enecha();
        judge_bu_tre_gun();
        judge_bu_tre_vac();
        charater_update();
        bullet_update();
        enemy_update();
        scoreupdate();//windows==3;
        treasure_update();
        }
    else if( window == 10 ){
        razer_enecol();
        judge_bu_tre_gun();
        judge_bu_tre_vac();
        razer_vaccol();
        razer_guncol();
        judge();
        enecha();
        bullet_update();
        boss_charcol();
        bullet_bosscol();
        bigbossrazercol();
        charater_update();
        bigbossenemy_update();
        razer_accept();
        bigbossbullet_update();
        treasure_update();
        enemy_update();
        scoreupdate();
        }
        //if(al_get_timer_started(fps)) printf("run\n");
        //printf("%f\n",FPS);
}
int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    if( window == 1){
        if(music_play){
            al_play_sample_instance(sample_instance);
            music_play=false;
        }
    al_stop_timer(fps);
    al_hide_mouse_cursor(display);
    //if(event.type==ALLEGRO_EVENT_KEY_DOWN) printf("down\n");
   // else if(event.type==ALLEGRO_EVENT_TIMER) printf("titi\n");
    //if(al_is_event_queue_empty(event_queue)) printf("sdf\n");
        menu_process(event);
    }
    else if(window==3){
        if(music_play){
            al_play_sample_instance(sfwin3_instance);
            music_play=false;
        }
            al_stop_timer(fps);
            menu_process(event);
    }else if( window == 2 ){
        if(music_play){
            al_play_sample_instance(sfwin2_instance);
            music_play=false;
        }
       // if(event.type==ALLEGRO_EVENT_KEY_DOWN) printf("down %d\n",level);
        //else if(event.type==ALLEGRO_EVENT_TIMER) printf("titi\n");

        charater_process(event);
        bullet_process(event);
        enemy_process(event);
        treasure_process(event);
    }else if(window==-1){
        al_stop_timer(fps);
        return -100;
    }else if(window==5){
        al_stop_timer(fps);
        return -10;
    }else if( window == 10 ){
        if(music_play){
            //printf("sdf\n");
            al_play_sample_instance(sfwin10_instance);
            music_play=false;
        }
        bullet_process(event);
        treasure_process(event);
        //bigbosschar_process(event);
        charater_process(event);
        bigbossenemy_process(event);
        bigbossbullet_process(event);
        enemy_process(event);
    }

    // Shutdown our program
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps){
            draw = true;
        }
    game_update();
    return 0;
}
void game_draw(){
    if( window == 1||window==3 ){
        menu_draw();
    }else if( window == 2||window==10 ){
        //printf("in  %d\n",level);
        game_scene_draw();
    }
    al_flip_display();
}
int game_run() {
    int error = 0;
    if( draw ||window==1||window==3){
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    al_destroy_event_queue(videoq);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    game_scene_destroy();
    algif_destroy_animation(gameend);
    algif_destroy_animation(gifend);
}
