#include "runner.h"



t_bunny_accurate_position std_send_ray(t_main *map,
				       t_bunny_accurate_position start,
				       double angle)
{
  t_bunny_accurate_position pos;
  double len;
  int pos_tile;
  int comp;

  comp = 0;
  len = 0.0;
  pos.x = start.x; 
  pos.y = start.y; //start c'est la pos du carré
  pos_tile = (int) ((double) pos.y / (double) map->size) * (double) map->mapx + ((double) pos.x / (double) map->size);
  while (map->map [pos_tile] != 1)
    {
      pos = std_walk_to(start, angle, len);
      pos_tile = (int) ((double) pos.y / (double) map->size) * (double) map->mapx + ((double) pos.x / (double) map->size);
      len += 0.5;
      comp++;
    }
  return pos; 
}

