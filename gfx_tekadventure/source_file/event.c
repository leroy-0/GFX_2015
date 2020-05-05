/*
** event.c for event in /home/klein_h/Bureau/gfx_tekadventure/source_file
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sun Apr 17 21:34:49 2016
** Last update Tue Apr 19 17:53:25 2016 Henri Longle
*/

#include                <lapin.h>
#include                "my.h"

void 			start_game(t_pic *all, int *i)
{
  text_intro(all);
  tekfill(all->pix, 0x000000);
  all->key = 3;
  *i = 1;
}

void			launch_game(t_pic *all)
{
  bunny_delete_clipable(&all->pix->clipable);
  bunny_delete_clipable(&all->start->clipable);
  bunny_delete_clipable(&all->tmp->clipable);
  bunny_delete_clipable(&all->start_save->clipable);
  bunny_clear(&all->win->buffer, 0x000000);
  all->pix = bunny_load_pixelarray("wallpaper_source/play_game.jpg");
  all->resize = bunny_load_pixelarray("wallpaper_source/indianajones.png");
  bunny_sound_play(&all->haunted->sound);
  all->perso = bunny_new_pixelarray(60, 98);
  tekcut(all->perso, all->resize, all->dep_r, all);
  bunny_blit(&all->win->buffer, &all->pix->clipable, &all->fen);
  bunny_blit(&all->win->buffer, &all->perso->clipable, &all->pos_gamer);
  all->key = 1;
}

void 			menu_vide_show(t_pic *all, bool *on)
{
  all->inventory = bunny_load_pixelarray("source_menu/menu_vide.png");
  all->menu_key = 1;
  *on = true;
}

void 			menu_pelle_show(t_pic *all, bool *on)
{
  *on = true;
  all->menu_key = 2;
  all->inventory = bunny_load_pixelarray("source_menu/menu_pelle.png");
}

t_bunny_response		key_reponse(t_bunny_event_state state,
					    t_bunny_keysym key, t_pic *all)
{
  static bool 	on = false;

  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_I && state == GO_DOWN)
    {
      if (on == false && all->menu_key == 0)
	menu_vide_show(all, &on);
      else if (on == false && (all->menu_key == 2 || all->menu_key == 3))
	menu_pelle_show(all, &on);
      else if (on == true && all->menu_key == 1)
	{
	  bunny_delete_clipable(&all->inventory->clipable);
	  all->menu_key = 0;
	  on = false;
	}
      else if (on == true && all->menu_key == 2)
	{
	  bunny_delete_clipable(&all->inventory->clipable);
	  on = false;
	  all->menu_key = 3;
	}
    }
  return (GO_ON);
}
