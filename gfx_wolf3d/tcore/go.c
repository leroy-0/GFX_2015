/*
** go.c for go in /home/leroy_0/rendu/gfx_wolf3d/src
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sat Jan  2 18:06:04 2016 leroy_0
** Last update Sun Jan  3 23:31:27 2016 leroy_0
*/

#include <math.h>

void		go(t_bunny_position *curpos, double angle,
		   t_bunny_position *newpos, int move)
{
  newpos.x = curpos.x + (cos(angle) * move);
  newpos.y = curpos.y + (sin(angle) * move);
}
