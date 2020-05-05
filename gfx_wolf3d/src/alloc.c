/*
** alloc.c for alloc in /home/leroy_0/rendu/gfx_wolf3d
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jan  3 23:10:28 2016 leroy_0
** Last update Sun Jan  3 23:36:34 2016 leroy_0
*/

#include <lapin.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "my.h"
#include "structure.h"

void    my_alloc(t_struct_data *data)
{
  int           a;
  int           b;

  a = 0;
  b = 0;
  if ((data->wall = malloc(sizeof(int *)
			   *data->pix->clipable.clip_width
			   *data->pix->clipable.clip_height)) == NULL)
    return ;
  while (a < data->pix->clipable.clip_height)
    {
      if ((data->wall[a] = malloc(sizeof(int) * data->pix->clipable.clip_width)) == NULL)
	return ;
      while (b < data->pix->clipable.clip_width)
	{
	  data->wall[a][b] = 0;
	  b++;
	}
      a++;
      b = 0;
    }
  data->wall[a] = NULL;
}

void    square(t_struct_data *data, int a, int b)
{
  int   cpt1;
  int   cpt2;

  cpt1 = 0;
  cpt2 = 0;
  while (cpt2 < 50)
    {
      while (cpt1 < 50)
	{
	  data->pos[0].x = b * 45 + cpt1;
	  data->pos[0].y = a * 45 + cpt2;
	  data->wall[data->pos[0].x][data->pos[0].y] = 2;
	  tekpixel(data->pix, data->pos, (t_color *)&data->color);
	  cpt1++;
	}
      cpt2++;
      cpt1 = 0;
    }
}

void    draw_minimap(t_struct_data *data)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  data->color[0] = 0x00FFFF;
  while (a < data->height)
    {
      while (b < data->width)
	{
	  if (data->map[a][b] == 1)
	    square(data, a, b);
	  b++;
	}
      a++;
      b = 0;
    }
}

void    my_declare(t_struct_data *data, int cpt, int cpt2)
{
  data->color[0] = WHITE;
  data->pos[0].x = (data->x)/1.75;
  data->pos[0].y = (data->y)/1.75;
  data->pos[1].x = cos((cpt + data->angle) * degree) * cpt2 + data->pos[0].x;
  data->pos[1].y = -1*sin((cpt + data->angle)*degree) *cpt2 + data->pos[0].y;
}

int     my_whil(t_struct_data *data, int cpt2, int cpt)
{
  static	int savex = (1600 / 2);

  while (data->wall[data->pos[1].x][data->pos[1].y] == 0)
    {
      data->pos[1].x = cos((cpt + data->angle)*degree)*cpt2
	+ data->pos[0].x;
      data->pos[1].y = -1*sin((cpt + data->angle)*degree)*cpt2
	+ data->pos[0].y;
      cpt2++;
    }
  tekline(data->pix, data->pos, (t_color *)&data->color);
  data->dist = sqrt(pow((data->pos[1].x - data->pos[0].x), 2)
		    + pow((data->pos[1].y - data->pos[0].y), 2));
  data->colh = (((data->pix->clipable.clip_height/2)/tan(fov/2))*64)
    /data->dist;
  data->color[0] = RED;
  data->pos[0].x = savex + 20;
  if (fov == cpt - 1)
    savex = (1600 / 2);
  else
    savex += 20;
  data->pos[0].y = (data->win->buffer.height/4) - (data->colh/2) + 400;
  return (cpt2);
}
