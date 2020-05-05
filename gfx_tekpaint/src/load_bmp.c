/*
** load_bmp.c for load_bmp.c in /home/longle_h/rendu/gfx_tekpaint
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Fri Jan  8 16:24:55 2016 Henri Longle
** Last update Tue Jan 26 23:23:03 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<math.h>
#include		"../include/bmp.h"
#include		"../include/my.h"
#include		"../include/structure.h"

t_pix			*read_24_pix(int fd, int nb_read)
{
  char			*load_pix;
  t_pix			*pix_24;

  if (nb_read != 0)
    {
      if ((load_pix = bunny_malloc(sizeof(char) * nb_read)) == NULL)
	return (NULL);
      if ((read(fd, load_pix, nb_read)) < 0)
	return (NULL);
      if (load_pix != NULL)
	bunny_free(load_pix);
    }
  if ((pix_24 = bunny_malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  if ((read(fd, pix_24, 3)) < 0)
    return (NULL);
  return (pix_24);
}

t_pix			*read_32_pix(int fd, int nb_read)
{
  char			*load_pix;
  t_pix			*pix_32;

  if (nb_read != 0)
    {
      if ((load_pix = bunny_malloc(sizeof(char) * nb_read)) == NULL)
	return (NULL);
      if ((read(fd, load_pix, nb_read)) < 0)
	return (NULL);
      if (load_pix != NULL)
	bunny_free(load_pix);
    }
  if ((pix_32 = bunny_malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  if (read(fd, pix_32, 4) < 0)
    return (NULL);
  return (pix_32);
}

void			load_32_pix(t_bmp *header, int fd,
				    t_struct *data,
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
	  pix = read_32_pix(fd, nb_read);
	  color.argb[0] = pix->B;
	  color.argb[1] = pix->G;
	  color.argb[2] = pix->R;
	  color.argb[3] = pix->L;
	  tekpixel(data->pix, &pos, &color);
	  pos.x++;
	  if (pix != NULL)
	    bunny_free(pix);
	}
      pos.y--;
    }
}

void			*load_bitmap(const char *file,
				     t_struct *data,
				     t_bunny_position *pos_bmp)
{
  int			fd;
  t_bmp			*bmp_header;

  if ((fd = open(file, O_RDONLY)) == 0)
    return (NULL);
  if ((bmp_header = bunny_malloc(sizeof(char) * HEADER_SIZE + 1)) == NULL)
    return (NULL);
  if ((read(fd, bmp_header, HEADER_SIZE)) < 0)
    return (NULL);
  if (bmp_header->height > 768 || bmp_header->width > 1024)
    return (NULL);
  if (bmp_header->bit_per_pixel == 32)
    load_32_pix(bmp_header, fd, data, pos_bmp);
  else if (bmp_header->bit_per_pixel == 24)
    load_24_pix(bmp_header, fd, data, pos_bmp);
  else
    write(1, "Format non supporté\n", 21);
  if (bmp_header != NULL)
    bunny_free(bmp_header);
  close(fd);
  return ("ALL GOOD");
}
