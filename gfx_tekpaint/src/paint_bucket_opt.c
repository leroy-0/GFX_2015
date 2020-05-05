/*
** paint_bucket_opt.c for paint_bucket_opt in /home/leroy_0/rendu/gfx_tekpaint
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan 28 16:46:57 2016 leroy_0
** Last update Tue Jan 26 00:07:51 2016 Henri Longle
*/

#include <lapin.h>
#include "../include/structure.h"
#include "../include/my.h"

int             my_uppery(t_struct *data, t_color oldcolor, t_color tmpcol)
{
  if (data->pos[0].y + 1 < SIZE_Y)
    {
      data->pos[0].y++;
      tmpcol = getpixel(data->pix, data->pos);
      if (tmpcol.full == oldcolor.full)
        {
          if(!push(data))
            return (1);
        }
      else
        data->pos[0].y--;
    }
  return (0);
}

int             my_lowery(t_struct *data, t_color oldcolor, t_color tmpcol)
{
  if (data->pos[0].y - 1 >= 0)
    {
      data->pos[0].y--;
      tmpcol = getpixel(data->pix, data->pos);
      if (tmpcol.full == oldcolor.full)
        {
          if(!push(data))
            return (1);
        }
      else
        data->pos[0].y++;
    }
  return (0);
}

int             my_flood_fill(t_struct *data, t_color newcolor, t_color oldcolor)
{
  t_color               tmpcol;

  if (newcolor.full == oldcolor.full)
    return (0);
  my_stack(data);
  tmpcol = getpixel(data->pix, data->pos);
  if(!push(data))
    return (0);
  while (pop(data))
    {
      tekpixel(data->pix, data->pos, &data->color);
      if (my_upperx(data, oldcolor, tmpcol) == 1)
        return (0);
      if (my_lowerx(data, oldcolor, tmpcol) == 1)
        return (0);
      if (my_uppery(data, oldcolor, tmpcol) == 1)
        return (0);
      if (my_lowery(data, oldcolor, tmpcol) == 1)
        return (0);
    }
  return (0);
}
