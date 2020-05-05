/*
** tekpaint.c for tekpaint in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan  7 10:07:05 2016 Arthur Klein
** Last update Wed Jan 27 00:22:33 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<math.h>
#include		"../include/my.h"
#include		"../include/structure.h"
#include		"../include/bmp.h"

void 			continuous_click(t_struct *data, int *i)
{
  if (data->yes == true)
    {
      if (data->opt == 2)
	square(data, i);
      if (data->opt == 3)
	draw_circle(data, i);
      if (data->opt == 4)
	rectangle(data, i);
      if (data->opt == 5)
	triangle(data, i);
      if (data->opt == 6)
	tek_pencil(data, i);
      if (data->opt == 7)
	roller(data, i, 10);
      if (data->opt == 8)
	bombe(data, i);
    }
}

t_bunny_response	mainloop(t_struct *data)
{
  static 		int  i = 0;

  color_full(data);
  data->mouse = bunny_get_mouse_position();
  continuous_click(data, &i);
  bunny_set_click_response((t_bunny_click)&click);
  bunny_set_key_response((t_bunny_key)&key);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->fen);
  bunny_display(data->win);
  return (GO_ON);
}

void			init_all(t_struct *data)
{
  data->square_size = 25;
  data->yes = false;
  data->opt = 0;
  data->color.argb[0] = 250;
  data->color.argb[1] = 250;
  data->color.argb[2] = 250;
  data->color.argb[3] = 250;
  color_palette_red(data);
  color_palette_green(data);
  color_palette_blue(data);
}

int			check_env(char **env, int ac)
{
  if (ac > 2)
    return (-1);
  if (env == NULL || env[0] == NULL)
    {
      write(1, "Error: Cannot be displayed\n", 27);
      return (-1);
    }
  return (0);
}

int                     main(int ac, char **av, char **env)
{
  t_struct		data;
  t_bunny_position 	pos;

  pos.x = 0;
  pos.y = 0;
  set_max_heap_size(5);
  if (check_env(env, ac) == -1)
    return (1);
  data.fen.x = 0;
  data.fen.y = 0;
  data.save_format = 0;
  data.win = bunny_start(SIZE_X, SIZE_Y, false, "TekPaint");
  data.pix = bunny_new_pixelarray(SIZE_X, SIZE_Y);
  if (load_bitmap("plan_tools.bmp", &data, &pos) == NULL)
    return (1);
  if ((ac == 2 && load_image(&data, av[1]) == 1))
      return (1);
  init_all(&data);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, 150, &data);
  bunny_clear(&data.win->buffer, 0x000000);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_stop(data.win);
  return (0);
}
