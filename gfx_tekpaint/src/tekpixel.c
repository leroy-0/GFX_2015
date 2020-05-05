/*
** tekpixel.c for tekpixel in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:27:14 2015 leroy_0
** Last update Tue Jan 26 00:11:12 2016 Henri Longle
*/

#include		<lapin.h>
#include		"../include/my.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  if ((pos->y >= 0 && pos->y <= SIZE_Y) && (pos->x >= 0 && pos->x <= SIZE_X))
    {
      ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
	= (*color);
    }
}

t_color			getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos)
{
  t_color		color;
  if ((pos->y >= 0 && pos->y <= SIZE_Y) && (pos->x >= 0 && pos->x <= SIZE_X))
    color = ((t_color *)(pix->pixels))[pos->y *
				       pix->clipable.clip_width + pos->x];
  return (color);
}

void			check_state(t_struct *data,
			    t_bunny_event_state state)
{
  if (state == GO_UP)
    data->yes = false;
  else
    data->yes = true;
}

int			erase_opt(t_struct *data)
{
  int			i;

  i = 0;
  data->color.full = WHITE;
  color_palette_blue(data);
  color_palette_green(data);
  color_palette_red(data);
  square(data, &i);
  return (0);
}
