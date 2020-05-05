/*
** move_my_player.c for move_my_man in /home/klein_h/Bureau/gfx_tekadventure/source_file
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sun Apr 17 21:32:46 2016
** Last update Tue Apr 19 18:36:45 2016 Henri Longle
*/

#include                <lapin.h>
#include                "my.h"

void 			move_my_player(t_pic *all)
{
  if (all->save_cur.x > all->pos_gamer.x)
    move_x_plus(all);
  else if (all->save_cur.x < all->pos_gamer.x)
    move_x_minus(all);
  if (all->save_cur.y < all->pos_gamer.y)
    move_stair(all);
  else if (all->save_cur.y > all->pos_gamer.y)
    move_unstair(all);
}

void 			check_pos(t_pic *all)
{
  t_bunny_position 	pos;

  if ((all->save_cur.x != all->pos_gamer.x))
    move_my_player(all);
  else if (all->save_cur.x == all->pos_gamer.x
  && all->menu_key == 1 && all->search == 1)
    {
      pos.x = 600;
      pos.y = 450;
      all->start = bunny_load_pixelarray("ascii/ascii.png");
      tektext(all->pix, "You found a shovel", all->start, &pos);
      all->menu_key = 2;
      all->inventory = bunny_load_pixelarray("source_menu/menu_pelle.png");
    }
  else
    {
      if (all->whereis == 1)
	all->whereis = 2;
      all->dep_r.x = 3;
      all->dep_r.y = 0;
      if (all->key == 1)
	tekcut(all->perso, all->resize, all->dep_r, all);
      if (all->whereis == 3)
	all->whereis = 10;
    }
}
