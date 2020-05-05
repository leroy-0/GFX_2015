/*
** save_img_bmp.c for save_bmp in /home/longle_h/rendu/gfx_tekpaint
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Mon Jan 25 11:48:43 2016 Henri Longle
** Last update Tue Jan 26 23:24:29 2016 Sebastien BRUERE
*/

#include		<unistd.h>
#include		<sys/stat.h>
#include		<sys/types.h>
#include		<fcntl.h>
#include		"../include/my.h"
#include		"../include/bmp.h"
#include		"../include/structure.h"

int			write_pix(int fd, t_struct *data)
{
  t_bunny_position	pos;
  t_color		color;
  unsigned char		alpha;

  pos.y = 685;
  alpha = 0;
  while (pos.y > 0)
    {
      pos.x = 129;
      while (pos.x < 1024)
	{
	  color = getpixel(data->pix, &pos);
	  write(fd, &(color.argb[2]), 1);
	  write(fd, &(color.argb[1]), 1);
	  write(fd, &(color.argb[0]), 1);
	  write(fd, &alpha, 1);
	  pos.x++;
	}
      pos.y--;
    }
  return (0);
}

static int		start_header(int fd, t_struct *data)
  {
    t_bmp			bmp;

    bmp.id_field = 0x4D42;
    bmp.size_file = (((895 * 695) * 32) / 8) + 56;
    bmp.do_not_use = 0;
    bmp.pos_pix = 54;
    bmp.header = 40;
    bmp.width = 895;
    bmp.height = 685;
    bmp.plan_bit = 0;
    bmp.bit_per_pixel = 32;
    bmp.compression = 0;
    bmp.size_pict = 0;
    bmp.pixel_per_meter_width = 0;
    bmp.pixel_per_meter_height = 0;
    bmp.nb_color = 0;
    bmp.nb_imp_color = 0;
    write(fd, &bmp, 54);
    write_pix(fd, data);
    return (0);
  }

int			create_file(t_struct *data)
{
  int			fd;

  if (data->save_format == 0)
    fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
  else if (data->save_format == 1)
    fd = open("save.tek", O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
  if (fd < 0)
    return (-1);
  else
    {
      if (data->save_format == 0)
	start_header(fd, data);
      else if (data->save_format == 1)
	write_pix(fd, data);
    }
  return (0);
}
