/*
** click.c for click in /home/bruere_s/Projet/Infographie/gfx_tekpaint/src
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Tue Jan 26 20:05:24 2016 Sebastien BRUERE
** Last update Tue Jan 26 23:21:28 2016 Sebastien BRUERE
*/

#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"
#include		"../include/bmp.h"

void                    click_opt(t_struct *data, int *i)
{
  if ((data->mouse->x >= 12 && data->mouse->x <= 62
       && data->mouse->y >= 432 && data->mouse->y <= 480) || data->opt == 11)
    {
      if (data->opt != 11)
	*i = 2;
      data->opt = 11;
      pipette(data, i);
    }
  if ((data->mouse->x >= 63 && data->mouse->x <= 108
       && data->mouse->y >= 432 && data->mouse->y <= 480))
    filter(data);
  if ((data->mouse->x >= 12 && data->mouse->x <= 108
       && data->mouse->y >= 14 && data->mouse->y <= 62))
    new_pixel_array(data);
  if ((data->mouse->x >= 12 && data->mouse->x <= 102
       && data->mouse->y >= 500 && data->mouse->y <= 548))
    save_format_bmp(data);
  if ((data->mouse->x >= 12 && data->mouse->x <= 102
       && data->mouse->y >= 112 && data->mouse->y <= 160))
    create_file(data);
  options(data, &data->opt, i);
}

void			options(t_struct *data, int *opt, int *i)
{
  if ((data->mouse->x >= 12 && data->mouse->x <= 58
       && data->mouse->y >= 335 && data->mouse->y <= 380) || *opt == 6)
    {
      if (*opt != 6)
	*i = 2;
      *opt = 6;
      tek_pencil(data, i);
    }
  if ((data->mouse->x >= 12 && data->mouse->x <= 58
       && data->mouse->y >= 385 && data->mouse->y <= 430) || *opt == 7)
    {
      if (*opt != 7)
	*i = 2;
      *opt = 7;
      roller(data, i, 10);
    }
  if ((data->mouse->x >= 68 && data->mouse->x <= 102  && data->mouse->y >= 385
       && data->mouse->y <= 430) || *opt == 8)
    {
      if (*opt != 8)
	*i = 2;
      *opt = 8;
      bombe(data, i);
    }
  form(data, &data->opt, i);
}

void			form(t_struct *data, int *opt, int *i)
{
  if ((data->mouse->x >= 68 && data->mouse->x <= 102
       && data->mouse->y >= 270 && data->mouse->y <= 320) || *opt == 3)
    {
      if (*opt != 3)
	*i = 2;
      *opt = 3;
      draw_circle(data, i);
    }
  if ((data->mouse->x >= 12 && data->mouse->x <= 58
       && data->mouse->y >= 225 && data->mouse->y <= 270) || *opt == 4)
    {
      if (*opt != 4)
	*i = 2;
      *opt = 4;
      rectangle(data, i);
    }
  if ((data->mouse->x >= 12 && data->mouse->x <= 58
       && data->mouse->y >= 270 && data->mouse->y <= 320) || *opt == 5)
    {
      if (*opt != 5)
	*i = 2;
      *opt = 5;
      triangle(data, i);
    }
  click_change_value_pal(data);
}

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton key, t_struct *data)
{
  static int		i = 2;

  if (key == BMB_LEFT && state == GO_DOWN)
    {
      if ((data->mouse->x >= 62 && data->mouse->x <= 108
	   && data->mouse->y >= 175 && data->mouse->y <= 220) || data->opt == 1)
	{
	  if (data->opt != 1)
	    i = 2;
	  data->opt = 1;
	  opt_line(data, &i);
	}
      if ((data->mouse->x >= 12 && data->mouse->x <= 58
	   && data->mouse->y >= 175 && data->mouse->y <= 220) || data->opt == 2)
	{
	  if (data->opt != 2)
	    i = 2;
	  data->opt = 2;
	  square(data, &i);
	}
      click_opt(data, &i);
    }
  check_state(data, state);
  return (GO_ON);
}

void                    click_change_value_pal(t_struct *data)
{
  t_bunny_position      pos[1];

  if ((data->mouse->x >= 12 && data->mouse->x <= 62
       && data->mouse->y >= 618 && data->mouse->y <= 665))
    data->square_size += 1;
  if ((data->mouse->x >= 68 && data->mouse->x <= 102
       && data->mouse->y >= 618 && data->mouse->y <= 665))
    data->square_size -= 1;
  if ((data->mouse->x >= 792 && data->mouse->x <= 1023
       && data->mouse->y >= 700 && data->mouse->y <= 765))
    {
      pos[0].x = data->mouse->x;
      pos[0].y = data->mouse->y;
      data->color = getpixel(data->pix, pos);
      color_palette_red(data);
      color_palette_green(data);
      color_palette_blue(data);
    }
  if ((data->mouse->x >= 68 && data->mouse->x <= 102
       && data->mouse->y >= 338 && data->mouse->y <= 380))
    {
      data->opt = 2;
      erase_opt(data);
    }
}
