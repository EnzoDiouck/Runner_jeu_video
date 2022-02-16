/*                                                                                                                                                                                                   
** *****************************************************************************                                                                                                                     
** enzo.pfeiffer                                                                                                                                                                                     
** enzo.pfeiffer <enzo.pfeiffer@student-station>                                                                                                                                                     
**                                                                                                                                                                                                   
** vectrex_line.c - 2021                                                                                                                                                                             
**                                                                                                                                                                                                   
** *****************************************************************************                                                                                                                     
*/

#include "runner.h"

void std_set_line(t_bunny_pixelarray *px,
		  t_bunny_position   *pos,
		  unsigned int       color)
{
  t_bunny_position vector;
  t_bunny_position draw;
  double coeffdir;
  
  coeffdir = 0.0;
  vector.x = pos[1].x - pos[0].x;
  vector.y = pos[1].y - pos[0].y;
  while (coeffdir < 1)
    {
      draw.x = pos->x + vector.x * coeffdir;
      draw.y = pos->y + vector.y * coeffdir;
      std_set_pixel(px,draw,color);
      coeffdir = coeffdir + 0.001;
    }
}
