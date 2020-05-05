/*
** event_all.c for event_all in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan 14 12:57:11 2016 Arthur Klein
** Last update Tue Jan 26 23:22:11 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"
#include		"../include/bmp.h"

int			tek_pencil(t_struct *data, int *i)
{
  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  if ((data->mouse->x >= 128 && data->mouse->x <= 1024) &&
      (data->mouse->y >= 0 && data->mouse->y <= 695))
    tekpixel(data->pix, (t_bunny_position *)data->mouse, &data->color);
  return (0);
}

int			roller(t_struct *data, int *i, int square_size)
{
  float			x;
  float			y;

  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  x = (float)((float)1/(float)8);
  y = (float)((float)9/(float)10);
  data->pos[0].x = data->mouse->x - square_size;
  data->pos[0].y = data->mouse->y + square_size/2;
  data->pos[1].x = data->mouse->x + square_size;
  data->pos[1].y = data->mouse->y + square_size/2;
  while (data->pos[0].y > (data->mouse->y - (square_size/2))
    && data->pos[1].y > (data->mouse->y - (square_size/2)))
    {
      data->pos[0].y -= 1;
      data->pos[1].y -= 1;
      if ((data->pos[0].x > (SIZE_X * x) && data->pos[0].y < (SIZE_Y * y))
	&& (data->pos[1].x > (SIZE_X * x) && data->pos[1].y < (SIZE_Y * y))
      && (data->pos[0].x < SIZE_X && data->pos[1].x < SIZE_X))
      tekline(data->pix, data->pos, &data->color);
    }
  return (0);
}

int			bombe(t_struct *data, int *i)
{
  int			x;
  int			y;

  x = -20;
  y = -20;
  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  while (y <= 20)
    {
      x = -20;
      while (x <= 20)
	{
	  if (x * x + y * y <= 20 * 20)
	    loop_bombe(data, x, y);
	  x += 2;
	}
      y += 2;
    }
  return (0);
}
