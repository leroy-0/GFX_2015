/*
** print_case.c for print_case in /media/klein_h/A2BC25B6BC2585BF/gfx_tekpaint/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Jan 14 13:10:05 2016 Arthur Klein
** Last update Tue Jan 26 23:24:11 2016 Sebastien BRUERE
*/
#include		<lapin.h>
#include		"../include/my.h"
#include		"../include/structure.h"

void			aff_lim(t_struct *data)
{
  t_bunny_position	pos[2];
  t_color		color;

  pos[0].x = data->pos[0].x;
  pos[0].y = data->pos[0].y - 1;
  pos[1].x = data->pos[1].x;
  pos[1].y = data->pos[0].y - 1;
  color.full = WHITE;
  tekline(data->pix, pos, &color);
  pos[0].y = data->pos[1].y + 1;
  pos[1].y = data->pos[1].y + 1;
  tekline(data->pix, pos, &color);
  pos[0].x = data->pos[0].x - 1;
  pos[0].y = data->pos[0].y;
  pos[1].x = data->pos[0].x - 1;
  pos[1].y = data->pos[1].y;
  tekline(data->pix, pos, &color);
  pos[0].x = data->pos[1].x;
  pos[0].y = data->pos[0].y;
  pos[1].x = data->pos[1].x;
  pos[1].y = data->pos[1].y;
  tekline(data->pix, pos, &color);
}
