#include "runner.h"

t_bunny_response loop_mouse(const t_bunny_position *mouse,
			    void *d)
{
  t_main *data;
  t_bunny_position center;
  static int i = 0;

  printf("%d\r",i);
  i++;
  (void)mouse;
  data = (t_main *)d;
  center.x = data->game->clipable.buffer.width / 2;
  center.y = data->game->clipable.buffer.height / 2;
  bunny_set_mouse_visibility(data->win,false);
  data->mousepos = bunny_get_mouse_position();
  if(data->mousepos->x < center.x)
    data->angle -= 1;
  else if(data->mousepos->x > center.x)
    data->angle += 1;
  if (i == 5)
    {
      bunny_set_mouse_position(center.x, center.y);
      i = 0;
    }
  return (GO_ON);
}

t_bunny_response loop_click(t_bunny_event_state    state,
                           t_bunny_mouse_button   button,
                           void                   *data)
{
  (void)data;
  (void)state;
  (void)button;
  return GO_ON;
}


t_bunny_response loop_key(t_bunny_event_state    state,
			  t_bunny_keysym         keycode,
			  void                   *d)
{
  t_main *data;

  data = (t_main *)d;
  (void)data;
  if (state == GO_UP)
    return (GO_ON);
  if (keycode == BKS_ESCAPE)
    return (0);
  return (GO_ON);
}

t_bunny_response loop_function(void *d)
{
  t_main *data;
  
  data = (t_main *)d;
  if (bunny_get_keyboard()[BKS_Z])
    {
      data->pos = std_strafe(data->pos,(double)data->angle,3);
      if (data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1)
	data->pos = std_strafe(data->pos,(double)data->angle,-3);
    }
  if (bunny_get_keyboard()[BKS_D])
    {
      data->pos = std_strafe(data->pos,(double)(data->angle + 90),3);
      if (data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1)
	data->pos = std_strafe(data->pos,(double)(data->angle - 90),3);;
    }
  if (bunny_get_keyboard()[BKS_S])
    {
      data->pos = std_strafe(data->pos,(double)(data->angle + M_PI), -3);
      if (data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1)
	data->pos = std_strafe(data->pos,(double)data->angle,3);
    }
  if (bunny_get_keyboard()[BKS_Q])
    {
      data->pos = std_strafe(data->pos,(double)(data->angle - 90),3);
      if (data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x) / data->size)] == 1 ||
	  data->map [((int)data->pos.y / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1 ||
	  data->map [(((int)data->pos.y + data->taille) / data->size) * data->mapx + (((int)data->pos.x + data->taille) / data->size)] == 1)
	data->pos = std_strafe(data->pos,(double)(data->angle + 90),3);
    }

  std_clear_pixelarray(data->picture,9850);
  std_fill(data->game,-25536,9850);
  std_display(data->picture, data);
  
  std_action(data->picture,data->taille,data->pos);
  std_vision(data,data->picture,data->taille,data->pos);
  std_draw_bullet(data,5);
  if ((bunny_get_mouse_button()[BMB_LEFT] || bunny_get_mouse_button()[BMB_RIGHT]))
    std_shoot(data);
  bunny_blit(&data->win->buffer, &data->picture->clipable, &data->pos_picture);
  bunny_blit(&data->win->buffer, &data->stats->clipable, &data->pos_stats);
  bunny_blit(&data->win->buffer, &data->game->clipable, NULL);
  bunny_blit(&data->win->buffer, data->gun, &data->pos_gun);
  bunny_display(data->win);
  return (GO_ON);
}
