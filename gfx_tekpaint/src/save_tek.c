/*
** save_tek.c for save_tek in /home/longle_h/rendu/gfx_tekpaint/src
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Tue Jan 26 11:43:47 2016 Henri Longle
** Last update Thu Jan 28 22:55:03 2016 Arthur Klein
*/

#include		<unistd.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		"lapin.h"
#include		"../include/bmp.h"
#include		"../include/structure.h"
#include		"../include/my.h"

void			load_pix_tek(int fd, t_bunny_position *pos_file, \
			     t_struct *data)
{
  t_color		color;
  t_bunny_position	pos;
  t_pix			pix;

  pos.y = 685 + pos_file->y;
  while (pos.y > pos_file->y)
    {
      pos.x = pos_file->x;
      while (pos.x < (895 + pos_file->x))
	{
	  read(fd, &pix, 4);
	  color.argb[2] = pix.R;
	  color.argb[1] = pix.G;
	  color.argb[0] = pix.B;
	  color.argb[3] = pix.L;
	  tekpixel(data->pix, &pos, &color);
	  pos.x++;
	}
	pos.y--;
    }
}

int			save_tek(t_struct *data)
{
  int			fd;

  (void)data;
  if ((fd = open("save.tek",
		 O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH)) <= 0)
    return (-1);
  else
    write_pix(fd, data);
  close(fd);
  return (0);
}

int			load_tek(const char *name, t_struct *data,
				 t_bunny_position *pos)
{
  int			fd;

  if (((fd = open(name, O_RDONLY)) <= 0))
    return (-1);
  load_pix_tek(fd, pos, data);
  close(fd);
  return (0);
}
