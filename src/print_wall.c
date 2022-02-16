#include "runner.h"


static double          std_powf(double x,
				double y)
{
  double        resultat;
  int           z;

  z = 0;
  resultat = 1;
  while (z < y)
    {
      resultat = resultat * x;
      z++;
    }
  return (resultat);
}


void std_print_wall(t_main *map,
		    t_bunny_position pos1,
		    int x)
{
  double calcule;
  double distance_wall_player;
  double hauteur;
  t_bunny_position pos[2];
  
  calcule = std_powf(((double)map->pos.x - (double)pos1.x),2) + std_powf(((double)map->pos.y - (double)pos1.y),2);
  distance_wall_player = sqrt(calcule);
  hauteur = 10.0 * (1000.0 / distance_wall_player);
  if (hauteur > map->game->clipable.buffer.height / 2)
    hauteur = map->game->clipable.buffer.height / 2;
  pos[0].x = x;
  pos[0].y = map->game->clipable.buffer.height / 2 - hauteur;
  pos[1].x = x;
  pos[1].y = map->game->clipable.buffer.height / 2 + hauteur;
  std_set_line(map->game,pos,BLACK);
}
