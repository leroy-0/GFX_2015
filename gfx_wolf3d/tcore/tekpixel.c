/*
** tekpixel.c for tekpixel in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:27:14 2015 leroy_0
** Last update Sun Nov 22 22:04:51 2015 leroy_0
*/

#include <lapin.h>
#include "../include/my.h"

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
    = color[0];
}
