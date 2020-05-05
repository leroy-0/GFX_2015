/*
** tekpixel.c for tekpixel in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:27:14 2015 leroy_0
** Last update Sun Apr 17 23:30:56 2016 Tekm
*/

#include		<lapin.h>
#include		"my.h"

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
