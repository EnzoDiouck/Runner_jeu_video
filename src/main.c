#include "runner.h"

int map[10 * 10]=
  {
    1,1,1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,0,0,1,
    1,0,1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,1,
    1,0,0,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,0,1,
    1,1,1,1,1,1,1,1,1,1
  };


int main()
{
  t_main gb;

  //gun
  gb.gun = bunny_load_picture("gun.png");
  gb.pos_gun.x = 820;
  gb.pos_gun.y = 450;
  //map
  gb.mapx = 10;
  gb.mapy = 10;
  gb.map = map;
  
  //character
  gb.size = 40; //taille d'une tuile
  gb.angle = 0; // angle de vision
  gb.taille = 10; //taille personnage
  gb.pos.x = 4 * gb.size; //pos initial du perso
  gb.pos.y = 4 * gb.size;
  
  //lapin
  gb.win = bunny_start(1600, 800, false, "Stars");
  //picture
  gb.picture = bunny_new_pixelarray(gb.mapx * gb.size, gb.mapy * gb.size);
  gb.pos_picture.x = gb.win->buffer.width - gb.mapx * gb.size;
  gb.pos_picture.y = 0;
  std_clear_pixelarray(gb.picture,BLACK);
  //stats
  gb.stats = bunny_new_pixelarray(gb.mapx * gb.size, gb.mapy * gb.size);
  gb.pos_stats.x = gb.win->buffer.width - gb.mapx * gb.size;
  gb.pos_stats.y = gb.win->buffer.height / 2;
  std_clear_pixelarray(gb.stats, 8421504);
  //game
  gb.game = bunny_new_pixelarray(gb.win->buffer.width - gb.mapx * gb.size, gb.win->buffer.height); 
  std_fill(gb.game,-25536,9850); //la on a un blue ciel et un marron  
  //loop
  bunny_set_loop_main_function(loop_function);
  bunny_set_move_response(loop_mouse);
  bunny_set_click_response(loop_click);
  bunny_set_key_response(loop_key);
  bunny_display(gb.win);
  bunny_loop(gb.win, 60, &gb);
  bunny_stop(gb.win);
}

