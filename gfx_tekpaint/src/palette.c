/*
** palette.c for palette in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan 14 12:52:14 2016 Arthur Klein
** Last update Tue Jan 26 23:24:03 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"

void			tekpixel_char(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      t_color color, int j)
{
  if (j == 0)
    {
      color.argb[1] = 0;
      color.argb[2] = 0;
      ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
	= color;
    }
  else if (j == 1)
    {
      color.argb[0] = 0;
      color.argb[2] = 0;
      ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
	= color;
    }
  else if (j == 2)
    {
      color.argb[0] = 0;
      color.argb[1] = 0;
      ((t_color *)(pix->pixels))[pos->y * pix->clipable.clip_width + pos->x]
	= color;
    }
}

void			color_full(t_struct *data)
{
  data->pos[0].x = 644;
  data->pos[0].y = 700;
  data->pos[1].x = 770;
  data->pos[1].y = 755;
  aff_lim(data);
  while (((data->pos[1].y + 1) != data->pos[0].y))
    {
      tekpixel(data->pix, data->pos, &data->color);
      data->pos[0].x++;
      if (data->pos[0].x == data->pos[1].x)
	{
	  data->pos[0].x = 644;
	  data->pos[0].y += 1;
	}
    }
}

void			color_palette_red(t_struct *data)
{
  int			j;

  j = 0;
  data->color.argb[0] = data->color.argb[0];
  data->pos[0].x = 128;
  data->pos[0].y = 700;
  data->pos[1].x = 278;
  data->pos[1].y = 755;
  aff_lim(data);
  while (((data->pos[1].y + 1) != data->pos[0].y))
    {
      tekpixel_char(data->pix, data->pos, data->color, j);
      data->pos[0].x++;
      if (data->pos[0].x == data->pos[1].x)
	{
	  data->pos[0].x = 128;
	  data->pos[0].y += 1;
	}
    }
}

void			color_palette_green(t_struct *data)
{
  int			j;

  j = 1;
  data->color.argb[1] = data->color.argb[1];
  data->pos[0].x = 300;
  data->pos[0].y = 700;
  data->pos[1].x = 450;
  data->pos[1].y = 755;
  aff_lim(data);
  while (((data->pos[1].y + 1) != data->pos[0].y))
    {
      tekpixel_char(data->pix, data->pos, data->color, j);
      data->pos[0].x++;
      if (data->pos[0].x == data->pos[1].x)
	{
	  data->pos[0].x = 300;
	  data->pos[0].y += 1;
	}
    }
}

void			color_palette_blue(t_struct *data)
{
  int			j;

  j = 2;
  data->color.argb[2] = data->color.argb[2];
  data->pos[0].x = 472;
  data->pos[0].y = 700;
  data->pos[1].x = 622;
  data->pos[1].y = 755;
  aff_lim(data);
  while (((data->pos[1].y + 1) != data->pos[0].y))
    {
      tekpixel_char(data->pix, data->pos, data->color, j);
      data->pos[0].x++;
      if (data->pos[0].x == data->pos[1].x)
	{
	  data->pos[0].x = 472;
	  data->pos[0].y += 1;
	}
    }
}
