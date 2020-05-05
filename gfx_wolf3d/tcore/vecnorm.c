/*
** vecnorm.c for vecnorm in /home/leroy_0/rendu/gfx_wolf3d/src
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sat Jan  2 17:55:23 2016 leroy_0
** Last update Sun Jan  3 23:31:55 2016 leroy_0
*/

#include <math.h>

double		vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  double		new_coord;

  new_coord = sqrt(pow((coord1->x - coord0->x), 2)
		   + pow((coord1->y - coord0->y), 2));
  return (new_coord);
}
