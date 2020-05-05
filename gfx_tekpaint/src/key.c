/*
** key.c for key in /home/bruere_s/Projet/Infographie/gfx_tekpaint/src
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Tue Jan 26 21:43:38 2016 Sebastien BRUERE
** Last update Tue Jan 26 00:09:59 2016 Henri Longle
*/

#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"
#include		"../include/bmp.h"

t_bunny_response	key(t_bunny_event_state state,
t_bunny_keysym key, t_struct *data)
  {
    key_reponse(state, key, data);
    if (key == BKS_T && state == GO_DOWN)
      data->color.argb[3] -= 12;
    if (key == BKS_A && state == GO_DOWN)
      erase_opt(data);
    if (key == BKS_C && state == GO_DOWN)
      data->opt = 3;
    if (key == BKS_T && state == GO_DOWN)
      data->opt = 5;
    if (key == BKS_S && state == GO_DOWN)
      data->opt = 2;
    if (key == BKS_L && state == GO_DOWN)
      data->opt = 1;
    if (key == BKS_R && state == GO_DOWN)
      data->opt = 4;
    if (key == BKS_F2 && state == GO_DOWN)
      create_file(data);
    if (key == BKS_F5 && state == GO_DOWN)
      {
	data->pos->x = data->mouse->x;
	data->pos->y = data->mouse->y;
	my_flood_fill(data, data->color, getpixel(data->pix, data->pos));
      }
    if (key == BKS_ESCAPE)
      return (EXIT_ON_SUCCESS);
    return (GO_ON);
  }

void			key_reponse(t_bunny_event_state state,
t_bunny_keysym key, t_struct *data)
  {
    if (key == (BKS_UP) && state == 0)
      {
	if (data->square_size < SIZE_Y / 2)
	  data->square_size += 1;
      }
    if (key == BKS_DOWN && state == 0)
      {
	if (data->square_size > 0)
	  data->square_size -= 1;
      }
    if (key == BKS_1 && state == GO_DOWN)
      {
	data->color.argb[0] -= 20;
	color_palette_red(data);
      }
    if (key == BKS_2 && state == GO_DOWN)
      {
	data->color.argb[1] -= 20;
	color_palette_green(data);
      }
    if (key == BKS_3 && state == GO_DOWN)
      {
	data->color.argb[2] -= 20;
	color_palette_blue(data);
      }
  }
