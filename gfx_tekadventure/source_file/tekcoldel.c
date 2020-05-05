/*
** tekcoldel.c for tekcoldel in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Wed Mar  9 14:07:56 2016 Tekm
** Last update Sun Apr 17 23:38:29 2016 Tekm
*/

#include <lapin.h>
#include "my.h"

void                    delcol_whl(t_bunny_pixelarray *destination,
                                   t_bunny_pixelarray *origin,
                                   t_bunny_position *position,
				   t_coldel *coldel)
{
  while (coldel->pos.y < destination->clipable.clip_height)
    {
      coldel->color = getpixel(destination, &coldel->pos);
      coldel->tmpcol = getpixel(origin, &coldel->save);
      if (coldel->rcolor.full == coldel->color.full)
        tekpixel(destination, &coldel->pos, &coldel->tmpcol);
      if (coldel->pos.x > destination->clipable.clip_width)
        {
          coldel->pos.x = 0;
          coldel->save.x = position->x;
          coldel->pos.y++;
          coldel->save.y++;
        }
      else
        {
          coldel->pos.x++;
          coldel->save.x++;
        }
    }
}

void                    delcol(t_bunny_pixelarray *destination,
                               t_bunny_pixelarray *origin,
                               t_bunny_position *position)
{
  t_coldel              coldel;

  coldel.pos.x = 0;
  coldel.pos.y = 0;
  coldel.save.x = position->x;
  coldel.save.y = position->y;
  coldel.tmpcol = getpixel(origin, position);
  coldel.color = getpixel(destination, &coldel.pos);
  coldel.rcolor = getpixel(destination, &coldel.pos);
  delcol_whl(destination, origin, position, &coldel);
}
