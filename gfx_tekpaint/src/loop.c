/*
** loop.c for loop in /home/bruere_s/Projet/Infographie/gfx_tekpaint/src
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Tue Jan 26 21:28:29 2016 Sebastien BRUERE
** Last update Wed Jan 27 00:00:09 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"

void			loop_square(t_struct *data)
{
  float			x;
  float			y;

  x = (float)((float)1/(float)8);
  y = (float)((float)9/(float)10);
  data->pos[0].y += 1;
  data->pos[1].y += 1;
  if ((data->pos[0].x > (SIZE_X * x) && data->pos[0].y < (SIZE_Y * y))
    && (data->pos[1].x > (SIZE_X * x) && data->pos[1].y < (SIZE_Y * y))
  && (data->pos[0].x < SIZE_X && data->pos[1].x < SIZE_X))
  tekline(data->pix, data->pos, &data->color);
}

void			loop_circle(t_struct *data, int x, int y)
{
  if (x * x + y * y <= data->square_size * data->square_size)
    {
      data->pos[0].x = data->mouse->x + x;
      data->pos[0].y = data->mouse->y + y;
      if ((data->pos[0].x < SIZE_X && data->pos[0].y <
      (SIZE_Y * (float)((float)9/(float)10)))
      && data->pos[0].x > (SIZE_X * (float)((float)1/(float)8)))
      tekpixel(data->pix, data->pos, &data->color);
    }
}

void			loop_bombe(t_struct *data, int x, int y)
{
  data->pos[0].x = data->mouse->x + x;
  data->pos[0].y = data->mouse->y + y;
  if ((data->pos[0].x < SIZE_X && data->pos[0].y <
  (SIZE_Y * (float)((float)9/(float)10)))
  && data->pos[0].x > (SIZE_X * (float)((float)1/(float)8))
  && x%3 != 0 && y %3 != 0)
  tekpixel(data->pix, data->pos, &data->color);
}

void			loop_filter(t_struct *data, t_bunny_position *pos)
{
  t_color		c;

  c = getpixel(data->pix, pos);
  c.argb[0] = 255 - c.argb[0];
  c.argb[1] = 255 - c.argb[1];
  c.argb[2] = 255 - c.argb[2];
  tekpixel(data->pix, pos, &c);
}
