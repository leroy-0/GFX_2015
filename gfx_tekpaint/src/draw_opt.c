/*
** draw_opt.c for draw_opt in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan 14 13:05:25 2016 Arthur Klein
** Last update Tue Jan 26 23:21:52 2016 Sebastien BRUERE
*/

#include			<lapin.h>
#include			"../include/my.h"
#include			"../include/structure.h"

int				square(t_struct *data, int *i)
{
  int				a;
  int				b;

  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  a = data->mouse->x;
  b = data->mouse->y;
  data->pos[0].x = a - data->square_size;
  data->pos[0].y = b - data->square_size;
  data->pos[1].x = a + data->square_size;
  data->pos[1].y = b - data->square_size;
  while (data->pos[0].y < (b + data->square_size))
    loop_square(data);
  return (0);
}

int				draw_circle(t_struct *data, int *i)
{
  int				x;
  int				y;

  x = -data->square_size;
  y = -data->square_size;
  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  while (y <= data->square_size)
    {
      x = -data->square_size;
      while (x <= data->square_size)
	{
	  loop_circle(data, x, y);
	  x++;
	}
      y++;
    }
  return (0);
}

void				opt_line(t_struct *data, int *i)
{
  static t_bunny_position	pos[2];
  float                 	x;
  float                 	y;

  x = (float)((float)1/(float)8);
  y = (float)((float)9/(float)10);
  if (*i == 0)
    {
      pos[0].x = data->mouse->x;
      pos[0].y = data->mouse->y;
      *i = 1;
    }
  else if (*i == 1)
    {
      pos[1].x = data->mouse->x;
      pos[1].y = data->mouse->y;
      if ((pos[0].x > (SIZE_X * x) && pos[0].y < (SIZE_Y * y))
	&& (pos[1].x > (SIZE_X * x) && pos[1].y < (SIZE_Y * y)))
      tekline(data->pix, pos, &data->color);
      *i = 0;
    }
  if (*i == 2)
    *i = 0;
}

int				rectangle(t_struct *data, int *i)
{
  float				x;
  float				y;

  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  x = (float)((float)1/(float)8);
  y = (float)((float)9/(float)10);
  data->pos[0].x = data->mouse->x - data->square_size;
  data->pos[0].y = data->mouse->y + data->square_size/2;
  data->pos[1].x = data->mouse->x + data->square_size;
  data->pos[1].y = data->mouse->y + data->square_size/2;
  while (data->pos[0].y > (data->mouse->y - (data->square_size/2))
    && data->pos[1].y > (data->mouse->y - (data->square_size/2)))
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

int				triangle(t_struct *data, int *i)
{
  float				x;
  float				y;

  if (*i == 2)
    {
      *i = 0;
      return (1);
    }
  x = (float)((float)1/(float)8);
  y = (float)((float)9/(float)10);
  data->pos[0].x = data->mouse->x;
  data->pos[0].y = data->mouse->y - data->square_size;
  data->pos[1].x = data->mouse->x - data->square_size;
  data->pos[1].y = data->mouse->y + data->square_size;
  while (data->pos[1].x < (data->mouse->x + data->square_size))
    {
      data->pos[1].x += 1;
      if ((data->pos[0].x > (SIZE_X * x) && data->pos[0].y < (SIZE_Y * y))
	&& (data->pos[1].x > (SIZE_X * x) && data->pos[1].y < (SIZE_Y * y))
      && (data->pos[0].x < SIZE_X && data->pos[1].x < SIZE_X))
      tekline(data->pix, data->pos, &data->color);
    }
  return (0);
}
