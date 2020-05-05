/*
** paint_bucket.c for paint_bucket in /home/leroy_0/rendu/gfx_tekpaint/src
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Jan 26 16:00:26 2016 leroy_0
** Last update Thu Jan 28 22:25:38 2016 leroy_0
*/

#include <lapin.h>
#include "../include/my.h"
#include "../include/structure.h"
#include "../include/bmp.h"

# define                stacksize       16777216

int                   i_stack[stacksize];
int                   i_stackpointer;

bool		pop(t_struct *data)
{

  if (i_stackpointer > 0)
    {
      int  p = i_stack[i_stackpointer];
      data->pos[0].x = p / SIZE_Y;
      data->pos[0].y = p % SIZE_Y;
      i_stackpointer--;
      return (1);
    }
  else
    return (0);
  return (0);
}

bool		push(t_struct *data)
{
  if (i_stackpointer < stacksize - 1)
    {
      i_stackpointer++;

      i_stack[i_stackpointer] = SIZE_Y * data->pos[0].x + data->pos[0].y;
      return (1);
    }
  else
    return (0);
  return (0);
}

void		my_stack(t_struct *data)
{
  while (pop(data));
}

int		my_upperx(t_struct *data, t_color oldcolor, t_color tmpcol)
{
  if (data->pos[0].x + 1 < SIZE_X)
    {
      data->pos[0].x++;
      tmpcol = getpixel(data->pix, data->pos);
      if (tmpcol.full == oldcolor.full)
	{
	  if(!push(data))
	    return (1);
	}
      else
	data->pos[0].x--;
    }
  return (0);
}

int		my_lowerx(t_struct *data, t_color oldcolor, t_color tmpcol)
{
  if (data->pos[0].x - 1 >= 0)
    {
      data->pos[0].x--;
      tmpcol = getpixel(data->pix, data->pos);
      if (tmpcol.full == oldcolor.full)
	{
	  if(!push(data))
	    return (1);
	}
      else
	data->pos[0].x++;
    }
  return (0);
}
