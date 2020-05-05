/*
** tekline.c for tekline in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:27:37 2015 leroy_0
** Last update Sun Jan  3 23:33:41 2016 leroy_0
*/

#include <lapin.h>
#include "my.h"

void    my_supy(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color,
		int a)
{
  int   b;
  int   y;
  int   addx;
  int   addy;

  addx = 0;
  y = pos[0].y;
  addx = my_addx(pos, addx);
  if (pos[0].y < pos[1].y)
    addy = 1;
  else
    addy = -1;
  b = abs(pos[1].y - pos[0].y) / 2;
  while (a++ < abs(pos[1].y - y))
    {
      pos[0].y += addy;
      b += abs(pos[1].x - pos[0].x);
      if (b > abs(pos[1].y - pos[0].y))
	{
	  b -= abs(pos[1].y - pos[0].y);
	  pos[0].x += addx;
	}
      tekpixel(pix, &pos[0], color);
    }
}

void    my_supx(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color,
		int a)
{
  int   b;
  int   x;
  int   addx;
  int   addy;

  addx = 0;
  x = pos[0].x;
  addx = my_addx(pos, addx);
  if (pos[0].y < pos[1].y)
    addy = 1;
  else
    addy = -1;
  b = abs(pos[1].x - pos[0].x) / 2;
  while (a++ < abs(pos[1].x - x))
    {
      pos[0].x += addx;
      b += abs(pos[1].y - pos[0].y);
      if (b > abs(pos[1].x - pos[0].x))
	{
	  b -= abs(pos[1].x - pos[0].x);
	  pos[0].y += addy;
	}
      tekpixel(pix, &pos[0], color);
    }
}

void	my_equaly(t_bunny_pixelarray *pix, t_bunny_position *pos,
		  t_color *color, int x)
{
  int   a;

  a = 0;
  while (a++ < abs(pos[1].x - x))
    {
      tekpixel(pix, &pos[0], color);
      pos[0].x += 1;
    }
}

void	my_equalx(t_bunny_pixelarray *pix, t_bunny_position *pos,
		  t_color *color, int y)
{
  int   a;

  a = 0;
  while (a++ < abs(pos[1].y - y))
    {
      tekpixel(pix, &pos[0], color);
      pos[0].y += 1;
    }
}

void    tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  int   a;
  int   x;
  int   y;
  int	savex1;
  int	savey1;

  a = 0;
  x = pos[0].x;
  y = pos[0].y;
  savex1 = x;
  savey1 = y;
  if (pos[1].x == pos[0].x)
    my_equalx(pix, pos, color, x);
  else if (pos[1].y == pos[0].y)
    my_equaly(pix, pos, color, y);
  else if (abs(pos[1].x - pos[0].x) > abs(pos[1].y - pos[0].y))
    my_supx(pix, pos, color, a);
  else if (abs(pos[1].y - pos[0].y) > abs(pos[1].x - pos[0].x))
    my_supy(pix, pos, color, a);
  tekpixel(pix, &pos[0], color);
  pos[0].x = savex1;
  pos[0].y = savey1;
}
