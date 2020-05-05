/*
** tekresize.c for tekresize in /home/klein_h/Bureau/gfx_tekadventure/source_file
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sun Apr 17 12:56:20 2016
** Last update Mon Apr 18 22:46:00 2016 
*/

#include <lapin.h>
#include "my.h"

void				tekresize(t_bunny_pixelarray *pix,
					  t_bunny_pixelarray *resized,
					  int resize)
{
  int				savey;
  int				cpt;
  int				i;

  i = 0;
  cpt = 0;
  savey = 0;
  while (cpt < pix->clipable.clip_width * pix->clipable.clip_height
	 && i < resized->clipable.clip_width * resized->clipable.clip_height)
    {
      ((t_color *)(resized->pixels))[i] = ((t_color *)(pix->pixels))[cpt];
      if (cpt - (savey * pix->clipable.clip_width)
	  > pix->clipable.clip_width)
	{
	  cpt += (pix->clipable.clip_width * (resize - 1)) + resize;
	  savey += resize;
	}
      else
	cpt += resize;
      i++;
    }
}
