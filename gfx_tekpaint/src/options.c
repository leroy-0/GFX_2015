/*
** options.c for options in /home/bruere_s/Projet/Infographie/gfx_tekpaint/src
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Tue Jan 26 19:26:06 2016 Sebastien BRUERE
** Last update Tue Jan 26 23:23:45 2016 Sebastien BRUERE
*/

#include		"lapin.h"
#include		"../include/structure.h"
#include		"../include/bmp.h"
#include		"../include/my.h"

void			save_format_bmp(t_struct *data)
{
  t_bunny_position	pos[1];

  pos[0].x = 10;
  pos[0].y = 495;
  if (data->save_format == 0)
    {
      load_bitmap("format_tek.bmp", data, pos);
      data->save_format = 1;
    }
  else
    {
      load_bitmap("format_bmp.bmp", data, pos);
      data->save_format = 0;
    }
}

void			new_pixel_array(t_struct *data)
{
  t_bunny_position	pos[1];

  pos[0].x = 0;
  pos[0].y = 0;
  bunny_clear(&data->win->buffer, 0x000000);
  load_bitmap("plan_tools.bmp", data, pos);
  color_palette_red(data);
  color_palette_green(data);
  color_palette_blue(data);
}

void			filter(t_struct *data)
{
  t_bunny_position	pos[1];
  static int		i = 0;

  pos[0].x = 129;
  pos[0].y = 1;
  if (i == 0)
    {
      while (pos[0].y < 694)
	{
	  while (pos[0].x < 1024)
	    {
	      loop_filter(data, pos);
	      pos[0].x++;
	    }
	  pos[0].x = 128;
	  pos[0].y++;
	}
      i = 1;
    }
  else if (i == 1)
    invers_filter(data, &i);
}

void			invers_filter(t_struct *data, int *i)
{
  t_bunny_position	pos[1];
  t_color		c;

  pos[0].x = 129;
  pos[0].y = 1;
  while (pos[0].y < 694)
    {
      while (pos[0].x < 1024)
	{
	  c = getpixel(data->pix, pos);
	  c.argb[0] = 255 - c.argb[0];
	  c.argb[1] = 255 - c.argb[1];
	  c.argb[2] = 255 - c.argb[2];
	  tekpixel(data->pix, pos, &c);
	  pos[0].x++;
	}
      pos[0].x = 128;
      pos[0].y++;
    }
  *i = 0;
}

void			pipette(t_struct *data, int *i)
{
  t_bunny_position	pos[1];
  t_color		c;

  if (*i == 2)
    {
      *i = 0;
      return;
    }
  pos[0].x = data->mouse->x;
  pos[0].y = data->mouse->y;
  if (pos[0].x > 128 && pos[0].x < 1024 &&
  pos[0].y > 0 && pos[0].y < 695)
    {
      c = getpixel(data->pix, pos);
      data->color.argb[0] = c.argb[0];
      data->color.argb[1] = c.argb[1];
      data->color.argb[2] = c.argb[2];
      color_palette_blue(data);
      color_palette_green(data);
      color_palette_red(data);
      color_full(data);
    }
}
