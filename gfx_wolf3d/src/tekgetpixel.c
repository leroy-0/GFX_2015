/*
** tekgetpixel.c for tekgetpixel in /home/leroy_0/rendu/xorshape_2015
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Dec  2 09:31:16 2015 leroy_0
** Last update Sun Jan  3 23:38:01 2016 leroy_0
*/

#include <lapin.h>
#include "../include/my.h"

unsigned int	tekgetpixel(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  unsigned int	color;

  color =
    ((unsigned int *)(pix->pixels))[pos->x*(pix->clipable.clip_height)
				    + pos->y];
  return (color);
}
