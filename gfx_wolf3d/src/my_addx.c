/*
** my_addx.c for my_addx in /home/leroy_0/rendu/gfx_fdf1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 22 21:55:02 2015 leroy_0
** Last update Sun Nov 22 22:03:04 2015 leroy_0
*/

#include <lapin.h>
#include "my.h"

int     my_addx(t_bunny_position *pos, int addx)
{
  if (pos[0].x < pos[1].x)
    addx = 1;
  else
    addx = -1;
  return (addx);
}
