/*
** disp.c for disp in /home/leroy_0/rendu/gfx_wolf3d
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jan  3 23:13:48 2016 leroy_0
** Last update Sun Jan  3 23:15:02 2016 leroy_0
*/

#include <lapin.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "my.h"
#include "structure.h"

void    draw_angle(t_struct_data *data)
{
  int   cpt;
  int   cpt2;
  int	savey = 0;
  int	savex = 0;

  cpt = -1;
  cpt2 = 1;
  my_declare(data, cpt, cpt2);
  while (cpt++ <= fov)
    {
      cpt2 = my_whil(data, cpt2, cpt);
      savey = data->pos[0].y;
      savex = data->pos[0].x;
      while (data->pos[0].x < savex + 20)
	{
	  data->pos[0].y = savey;
	  while (data->pos[0].y  < ((data->win->buffer.height/4) + (data->colh/2)))
	    {
	      tekpixel(data->pix, data->pos, (t_color*)&data->color);
	      data->pos[0].y += 1;
	    }
	  data->pos[0].x++;
	}
      cpt2 = 1;
      cpt++;
      my_declare(data, cpt, cpt2);
    }
}

void    my_prev_ini(t_struct_data *data)
{
  data->tile_size =
    my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                  "level1", "tile_size", 0));
  data->width = my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                              "level1", "width", 0));
  data->height = my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                               "level1", "height", 0));
  data->startx = my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                               "level1", "start_position", 0));
  data->starty = my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                               "level1", "start_position", 1));
  data->startangle =
    my_getnbr(bunny_ini_get_field(bunny_load_ini(data->nameofmap),
                                  "level1", "start_position", 2));
  if ((data->map = malloc(sizeof(*data->map)*data->height*data->width)) == NULL)
    return ;
  data->x = data->startx*100;
  data->y = data->starty*100;
  data->angle = data->startangle - fov/2;
}
