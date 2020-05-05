/*
** init_main.c for init_main in /home/longle_h/rendu/gfx_tekadventure/source_file
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Tue Apr 19 18:10:24 2016 Henri Longle
** Last update Wed Apr 20 15:15:34 2016 
*/

#include                <lapin.h>
#include                <stdio.h>
#include                <unistd.h>
#include                <math.h>
#include                "my.h"

void                    tekfill(t_bunny_pixelarray *pix, unsigned int color)
{
  int           i;

  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    ((unsigned int *)(pix->pixels))[i++] = color;
}

t_bunny_response        init_my_wallpaper(bool what, t_pic *all)
{
  t_bunny_position      pos;
  t_bunny_position      positon;

  pos.x = 0;
  pos.y = 0;
  positon.x = 165;
  positon.y = 100;
  if (what == false
      && (all->pix =
	  bunny_load_pixelarray("wallpaper_source/play_game.jpg")) == NULL)
    exit(1);
  if (what == false && (all->start =
			bunny_load_pixelarray("ascii/ascii.png")) == NULL)
    exit(1);
  all->tmp = bunny_new_pixelarray(my_strlen("Start Game") * 6, 8);
  tekfill(all->tmp, 0x000000);
  tektext(all->tmp, "Start Game", all->start, &pos);
  all->start_save = bunny_new_pixelarray(all->tmp->clipable.clip_width * 3,
					 all->tmp->clipable.clip_height * 3);
  all->tmp->clipable.scale.x = 3;
  all->tmp->clipable.scale.y = 3;
  tekplus((*all).start_save, all->tmp, &all->pos_gamer);
  delcol(all->start_save, all->pix, &positon);
  return (GO_ON);
}
