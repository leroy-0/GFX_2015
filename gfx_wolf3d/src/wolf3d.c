/*
** wolf3d.c for wolf3d in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Nov 20 17:31:06 2015 leroy_0
** Last update Sun Jan  3 23:34:30 2016 leroy_0
*/

#include <lapin.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "my.h"
#include "structure.h"

void	getini(t_struct_data *data)
{
  int	a;
  int	b;
  int	cpt;

  a = 0;
  b = 0;
  cpt = 0;
  my_prev_ini(data);
  while (a < data->height)
    {
      if ((data->map[a] = malloc(sizeof(data->map[a])*data->width)) == NULL)
	return ;
      while (b < data->width)
	{
	  data->map[a][b] = my_getnbr(bunny_ini_get_field
				      (bunny_load_ini(data->nameofmap),
				       "level1", "data", cpt));
	  cpt++;
	  b++;
	}
      a++;
      b = 0;
    }
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key, t_struct_data *data)
{
  (void)state;
  if (key == BKS_LEFT && state == 0)
    data->angle += camspeed;
  if (key == BKS_RIGHT && state == 0)
    data->angle -= camspeed;
  if (key == BKS_UP && state == 0)
    {
      data->x = cos((fov/2 + data->angle)*degree)*4 + data->x;
      data->y = -1*sin((fov/2 + data->angle)*degree)*4 + data->y;
    }
  if (key == BKS_DOWN && state == 0)
    {
      data->x = cos((fov/2 + data->angle)*degree)*-4 + data->x;
      data->y = -1*sin((fov/2 + data->angle)*degree)*-4 + data->y;
    }
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(t_struct_data *data)
{
  int			i;

  i = 0;
  while (i < data->pix->clipable.clip_width * data->pix->clipable.clip_height)
    ((unsigned int *)(data->pix->pixels))[i++] = BLACK;
  draw_minimap(data);
  draw_angle(data);
  bunny_display(data->win);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->fen);
  return (GO_ON);
}

int                     main(int argc, char **argv, char **env)
{
  t_struct_data         data;

  if (argc != 2 || env == NULL || env[0] == NULL)
    {
      write(1, "Usage : ./wolf3d map_name\n", 26);
      return (1);
    }
  if ((data.nameofmap = malloc(sizeof(char) * my_strlen(argv[1]))) == NULL)
    return (1);
  data.nameofmap = argv[1];
  data.fen.x = 0;
  data.fen.y = 0;
  if ((data.win = bunny_start(1600, 920, false, "wolf3d")) == NULL)
    return (1);
  if ((data.pix = bunny_new_pixelarray(data.win->buffer.width,
				       data.win->buffer.height)) == NULL)
    return (1);
  getini(&data);
  my_alloc(&data);
  bunny_set_key_response((t_bunny_key)&key);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, 150, &data);
  bunny_stop(data.win);
  return (0);
}
