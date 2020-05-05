/*
** tekpaint.c for tekpaint in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan  7 10:07:05 2016 Arthur Klein
** Last update Thu Feb 25 13:41:31 2016 Tekm
*/

#include		<lapin.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<math.h>
#include		"../include/structure.h"

t_bunny_response        key(t_bunny_event_state state,
                            t_bunny_keysym key, t_struct *data)
{
  (void)data;
  (void)state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(t_struct *data)
{
  int           i;

  i = 0;
  while (i < data->out->clipable.clip_width * data->out->clipable.clip_height)
    ((unsigned int *)(data->out->pixels))[i++] = BLACK;
  tektext(data->out, "^^ ta vu ca MARCHE tutur AHA !!^^", data->pix);
  tekfunction("amdoula");
  data->pos->x = 200;
  data->pos->y = 200;
  data->color.full = RED;
  tekpixel(data->pix, data->pos, &data->color);
  bunny_blit(&data->win->buffer, &data->out->clipable, &data->fen);
  bunny_display(data->win);
  return (GO_ON);
}

int                     main()
{
  t_struct	data;

  data.fen.x = 0;
  data.fen.y = 0;
  set_max_heap_size(15);
  data.win = bunny_start(SIZE_X, SIZE_Y, false, "TekPaint");
  data.pix = bunny_load_pixelarray("font.png");
  data.out = bunny_new_pixelarray(SIZE_X, SIZE_Y);
  bunny_set_key_response((t_bunny_key)&key);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, 150, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_clear(&data.win->buffer, 0x000000);
  bunny_stop(data.win);
  return (0);
}
