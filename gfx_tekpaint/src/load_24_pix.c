/*
** load_24_pix.c for load_ in /home/longle_h/rendu/gfx_tekpaint/src
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Thu Jan 14 20:49:08 2016 Henri Longle
** Last update Tue Jan 26 23:22:44 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		"../include/bmp.h"
#include		"../include/my.h"
#include		"../include/structure.h"

void			load_24_pix(t_bmp *header, int fd, t_struct *data,
				    t_bunny_position *pos_bmp)
{
  int			nb_read;
  t_bunny_position	pos;
  t_pix			*pix;
  t_color		color;

  pos.y = (int)header->height + pos_bmp->y;
  nb_read = header->pos_pix - HEADER_SIZE;
  while (pos.y > pos_bmp->y)
    {
      pos.x = pos_bmp->x;
      while (pos.x < ((int)header->width + pos_bmp->x))
	{
	  pix = read_24_pix(fd, nb_read);
	  color.argb[0] = pix->B;
	  color.argb[1] = pix->G;
	  color.argb[2] = pix->R;
	  tekpixel(data->pix, &pos, &color);
	  pos.x++;
	  if (pix != NULL)
	    bunny_free(pix);
	}
      pos.y--;
    }
}
