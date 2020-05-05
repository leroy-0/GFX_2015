/*
** move_func.c for move_func in /home/longle_h/rendu/gfx_tekadventure
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Tue Apr 19 18:35:44 2016 Henri Longle
** Last update Wed Apr 20 12:58:37 2016 
*/

#include                <lapin.h>
#include                "my.h"

void                    move_x_minus(t_pic *all)
{
  all->dep_r.x++;
  all->dep_r.y = 1;
  if (all->dep_r.x < 7)
    tekcut(all->perso, all->resize, all->dep_r, all);
  else
    all->dep_r.x = 0;
  if (all->pos_gamer.x % 2 == 0 && all->pos_gamer.x - 10 > all->save_cur.x)
    all->pos_gamer.x -= 4;
  else
    all->pos_gamer.x -= 1;
}

void                    move_x_plus(t_pic *all)
{
  all->dep_r.x++;
  all->dep_r.y = 2;
  if (all->dep_r.x < 7)
    tekcut(all->perso, all->resize, all->dep_r, all);
  else
    all->dep_r.x = 0;
  if (all->pos_gamer.x % 2 == 0 && all->pos_gamer.x + 10 < all->save_cur.x)
    all->pos_gamer.x += 4;
  else
    all->pos_gamer.x += 1;
}

void                    move_stair(t_pic *all)
{
  all->dep_u.x++;
  all->dep_u.y = 3;
  if (all->dep_u.x < 7)
    tekcut(all->perso, all->resize, all->dep_u, all);
  else
    all->dep_u.x = 0;
  if (all->pos_gamer.y % 2 == 0 && all->pos_gamer.y - 10 > all->save_cur.y)
    {
      all->pos_gamer.y -= 4;
      all->pos_gamer.x -= 4;
    }
  else
    {
      all->pos_gamer.x -= 1;
      all->pos_gamer.y -= 1;
    }
}

void                    move_unstair(t_pic *all)
{
  all->dep_u.x++;
  all->dep_u.y = 0;
  if (all->dep_u.x < 7)
    tekcut(all->perso, all->resize, all->dep_u, all);
  else
    all->dep_u.x = 0;
  if (all->pos_gamer.y % 2 == 0 && all->pos_gamer.y + 10 < all->save_cur.y)
    {
      all->pos_gamer.y += 4;
      all->pos_gamer.x += 4;
    }
  else
    {
      all->pos_gamer.x += 1;
      all->pos_gamer.y += 1;
    }
}
