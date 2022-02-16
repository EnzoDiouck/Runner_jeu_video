#include "runner.h"

void std_display(t_bunny_pixelarray *picture,
		 t_main *map)
{
  int x;
  int comp;
  int postemp;
  t_bunny_position pos;

  comp = 0;
  pos.x = 0;
  postemp = 0;
  pos.y = 0;
  while (comp < map->mapx * map->mapy)
    {
      x = 0;
      while (x < map->mapx)
	{
	  pos.y = postemp;
	  if (map->map[comp] == 1)
	    pos = std_draw(picture,map->size,pos,WHITE);
	  else
	    pos.x += map->size;
	  x++;
	  comp++;
	}
      pos.x = 0;
      postemp = pos.y;
    }
}


t_bunny_position std_draw(t_bunny_pixelarray *picture,
                          int size,
                          t_bunny_position pos,
                          unsigned int color)
{
  int y;
  int x;
  int postemp;

  postemp = pos.x;
  y = 0;
  x = 0;
  while (y < size)
    {
      x = 0;
      pos.x = postemp;
      while (x < size)
        {
          std_set_pixel(picture,pos,color);
          pos.x++;
          x++;
        }
      pos.y++;
      y++;
    }
  return pos;
}


void std_draw_bullet(t_main *map,
		     double size_bullet)
{
  t_bunny_position pos;
  double angle;
  t_bunny_position centre;

  angle = 0.0;
  centre.x = map->game->clipable.buffer.width /2;
  centre.y = map->game->clipable.buffer.height /2;
  while (angle < 360)
    {
      pos.x = (int)(size_bullet * cos(angle) + centre.x);
      pos.y = (int)(size_bullet * sin(angle) + centre.y);
      std_set_pixel(map->game,pos,WHITE);
      angle += 0.01;
    }
}



