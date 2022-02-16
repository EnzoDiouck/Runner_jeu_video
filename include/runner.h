#include <lapin.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>


typedef struct		s_main
{
  //gun
  t_bunny_picture               *gun;
  t_bunny_position              pos_gun;
  //lapin
  t_bunny_window		*win;
  t_bunny_pixelarray		*picture;
  t_bunny_pixelarray		*game;
  t_bunny_pixelarray		*stats;
  t_bunny_position		pos_picture;
  t_bunny_position		pos_stats;
  
  //personnage
  int				taille;
  t_bunny_position		pos;
  double			angle;
  const t_bunny_position	*mousepos;
  
  //map
  int				size;
  int				mapx;
  int				mapy;
  int				*map;

}			t_main;


#ifndef __RUNNER_H__
#define __RUNNER_H__

//personnage
void				std_vision(t_main *map,
					   t_bunny_pixelarray *picture,
					   int taille,
					   t_bunny_position pos);

void				std_action(t_bunny_pixelarray *picture,
					   int taille,
					   t_bunny_position pos);


void				std_shoot(t_main *map);

void				std_action_enemy(t_bunny_pixelarray *picture,
						 int taille,
						 t_bunny_position pos);

t_bunny_accurate_position 	std_send_ray(t_main *map,
					     t_bunny_accurate_position start,
					     double angle);


t_bunny_accurate_position	std_walk_to(t_bunny_accurate_position start,
					    double angle,
					    double len);

t_bunny_position		std_strafe(t_bunny_position start,
					   double angle,
					   double len);

//affichage


void				std_draw_bullet(t_main *map,
						double size_bullet);

void				std_display(t_bunny_pixelarray *picture,
					    t_main *map);

void				std_clear_pixelarray(t_bunny_pixelarray *picture,
						     unsigned int color);

void				std_fill(t_bunny_pixelarray *picture,
					 unsigned int color,
					 unsigned int color2);

void				std_set_wall(t_main *map);

void				std_set_pixel(t_bunny_pixelarray *px,
					      t_bunny_position   pos,
					      unsigned int       color);

void				std_set_pixel_centre(t_bunny_pixelarray *px,
						     t_bunny_position   pos,
						     unsigned int       color);

void				std_set_line(t_bunny_pixelarray *px,
					     t_bunny_position   *pos,
					     unsigned int       color);

void				std_print_wall(t_main *map,
					       t_bunny_position pos1,
					       int x);

void				std_create_wall(t_main *map,
						int hauteur,
						int largeur,
						int position,
						unsigned int color);
//map
t_main				std_init(t_main init);

t_bunny_position		std_draw(t_bunny_pixelarray *picture,
					 int size,
					 t_bunny_position pos,
					 unsigned int color);


//loop function

t_bunny_response		loop_key(t_bunny_event_state    state,
					 t_bunny_keysym         keycode,
					 void                   *data);

t_bunny_response		loop_mouse(const t_bunny_position *mouse,
					   void *d);

t_bunny_response		loop_click(t_bunny_event_state    state,
					   t_bunny_mouse_button   button,
					   void                   *data);

t_bunny_response		loop_function(void *d);

#endif /* __RUNNER_H__ */
