/*
** tekblit.c for tekblit in /home/tekm/tek1/gfx_tekadventure
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Apr 17 19:56:46 2016 Tekm
** Last update Tue Apr 19 18:23:23 2016 Henri Longle
*/

#include <lapin.h>
#include "my.h"

void				tekplus_whl(t_bunny_pixelarray *destination,
					    const t_bunny_pixelarray *origin,
					    t_plus *plus, int i)
{
   ((t_color *)(destination->pixels))[i] =
    ((t_color *)(origin->pixels))[plus->cpt];
  if (plus->cpt - plus->saveyo == origin->clipable.clip_width)
    {
      if (plus->cpt_col != origin->clipable.scale.y)
	{
	  plus->cpt = plus->saveyo;
	  plus->cpt_col++;
	}
      else if (plus->cpt_col == origin->clipable.scale.y)
	{
	  plus->cpt_col = 1;
	  plus->saveyo = plus->cpt;
	}
    }
  if (plus->cpt_row == origin->clipable.scale.x)
    {
      plus->cpt_row = 1;
      plus->cpt++;
    }
  else
    plus->cpt_row++;
}

void                            tekplus(t_bunny_pixelarray *destination,
                                        const t_bunny_pixelarray *origin,
                                        const t_bunny_position *pos)
{
  t_plus		plus;

  (void)pos;
  plus.i = 0;
  plus.cpt = 0;
  plus.saveyo = 0;
  plus.cpt_row = 1;
  plus.cpt_col = 1;
  while (plus.cpt <= origin->clipable.clip_width * origin->clipable.clip_height
         && plus.i <= destination->clipable.clip_width
	 * destination->clipable.clip_height)
    {
      tekplus_whl(destination, origin, &plus, plus.i);
      plus.i++;
    }
}
