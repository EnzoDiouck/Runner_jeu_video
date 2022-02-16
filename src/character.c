#include "runner.h"

void std_action(t_bunny_pixelarray *picture,
		int taille,
		t_bunny_position pos)
{
  std_draw(picture,taille,pos,YELLOW);
}

void std_action_enemy(t_bunny_pixelarray *picture,
		      int taille,
		      t_bunny_position pos)
{
  std_draw(picture,taille,pos,BLUE);
}

void std_shoot(t_main *map)
{
  t_bunny_accurate_position pos;
  t_bunny_accurate_position pos_end;
  t_bunny_position pos_endint;
  t_bunny_position pos_impact[2];

  pos.x = (double)map->pos.x;
  pos.y = (double)map->pos.y;
  pos_end = std_send_ray(map,pos,map->angle);
  pos_endint.x = (int)pos_end.x;
  pos_endint.y = (int)pos_end.y;
  pos_impact[0].x = pos.x + map->taille / 2;
  pos_impact[0].y = pos.y + map->taille / 2;
  pos_impact[1].x = pos_endint.x;
  pos_impact[1].y = pos_endint.y; 
  std_set_line(map->picture,pos_impact,RED);
  pos_impact[0].x = 860;
  pos_impact[0].y = 530;
  pos_impact[1].x = map->game->clipable.buffer.width / 2;
  pos_impact[1].y = map->game->clipable.buffer.height / 2; 
  std_set_line(map->game,pos_impact,RED);
}

  
void std_vision(t_main *map,
		t_bunny_pixelarray *picture,
		int taille,
		t_bunny_position pos)
{
  t_bunny_position position[2];
  t_bunny_accurate_position pos_player;
  t_bunny_accurate_position pos_wall;
  double angle_vision;
  int x;

  x = 0;
  angle_vision = map->angle - 30;
  pos_player.x = (double)pos.x;
  pos_player.y = (double)pos.y;
  if (map->angle > 360 || map->angle < -360)
    map->angle = 0;
  position[0].x = pos.x + taille / 2;
  position[0].y = pos.y + taille / 2;
  while (angle_vision <= map->angle + 30)
    {
      pos_wall = std_send_ray(map,pos_player, angle_vision);
      position[1].x = (int)pos_wall.x;
      position[1].y = (int)pos_wall.y;
      std_print_wall(map,position[1],x);
      //std_set_line(picture,position,GREEN);
      std_set_pixel(picture,position[1],RED);
      x++;
      angle_vision += 60.0 / (double) map->game->clipable.buffer.width;
    }
}
