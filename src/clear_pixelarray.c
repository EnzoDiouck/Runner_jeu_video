/*
** *****************************************************************************
** enzo.pfeiffer
** enzo.pfeiffer <enzo.pfeiffer@student-station>
**
** main.c - 2021
**
** *****************************************************************************
*/

#include "runner.h"

void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color)
{
  int *pix;
  int i;

  pix = picture->pixels;
  i = 0;
  while(i < picture->clipable.buffer.width * picture->clipable.buffer.height)
    {
      pix[i] = color;
      i += 1;
    }
}

void std_fill(t_bunny_pixelarray *picture, unsigned int color, unsigned int color2)
{
  int *pix;
  int i;

  pix = picture->pixels;
  i = 0;
  while(i < picture->clipable.buffer.width * (picture->clipable.buffer.height / 2))
    {
      pix[i] = color;
      i += 1;
    }
  while(i < picture->clipable.buffer.width * (picture->clipable.buffer.height / 2) * 2)
    {
      pix[i] = color2;
      i += 1;
    }
}
