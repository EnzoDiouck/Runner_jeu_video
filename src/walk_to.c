#include "runner.h"

t_bunny_accurate_position std_walk_to(t_bunny_accurate_position start,
                                      double angle,
                                      double len)
{
  start.x += cos(angle * M_PI /180.0) * len;
  start.y += sin(angle * M_PI /180.0) * len;
  return (start);
}

t_bunny_position std_strafe(t_bunny_position start,
			     double angle,
			     double len)
{
  start.x += (int)(cos(angle * M_PI /180.0) * len);
  start.y += (int)(sin(angle * M_PI /180.0) * len);
  return (start);
}

