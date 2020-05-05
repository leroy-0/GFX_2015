/*
** main.c for main in /home/klein_h/Bureau/gfx_tekadventure
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sat Apr 16 17:16:46 2016
** Last update Wed Apr 20 15:14:26 2016 
*/

#include                <lapin.h>
#include                <stdio.h>
#include                <unistd.h>
#include                <math.h>
#include                "my.h"

void			main_delete(t_pic *all, t_bunny_position pos, int *i)
{
  pos.x = 0;
  pos.y = 0;
  if ((*i) == 0)
    {
      bunny_clear(&all->win->buffer, 0x000000);
      bunny_stop(all->win);
      all->win = bunny_start(SIZE_X, SIZE_Y, false, "TekAdventure");
      bunny_delete_clipable(&all->pix->clipable);
      all->pix = bunny_load_pixelarray("wallpaper_source/in_house.jpg");
      (*i) = 1;
    }
  bunny_blit(&all->win->buffer, &all->pix->clipable, &pos);
}

void			main_intro(t_pic *all, t_bunny_position pos)
{
  bunny_blit(&all->win->buffer, &all->pix->clipable, &all->fen);
  if (all->key == 0)
    bunny_blit(&all->win->buffer, &all->start_save->clipable, &pos);
  if (all->key == 1)
    bunny_blit(&all->win->buffer, &all->perso->clipable, &all->pos_gamer);
  if (all->key == 3 && all->intro_pos.y >= (-1 * (45 * 6)))
    {
      pos.x = 1200;
      pos.y = 800;
      bunny_blit(&all->win->buffer, &all->intro->clipable, &all->intro_pos);
      bunny_blit(&all->win->buffer, &all->skip_intro->clipable, &pos);
      all->intro_pos.y -= 1;
    }
  else if (all->intro_pos.y <= (-1 * (45 * 6)))
    {
      all->intro_pos.y = 1;
      launch_game(all);
    }
  if (all->menu_key == 1 || all->menu_key == 2)
    bunny_blit(&all->win->buffer, &all->inventory->clipable, &all->fen);
}

t_bunny_response  	mainloop(t_pic *all)
{
  static 		int i = 0;
  t_bunny_position 	pos;

  pos.x = 165;
  pos.y = 100;
  all->mouse = bunny_get_mouse_position();
  check_pos(all);
  bunny_set_key_response((t_bunny_key)&key_reponse);
  bunny_set_click_response((t_bunny_click)&click);
  if (all->whereis == 0 || all->whereis == 3 || all->whereis == 2)
    main_intro(all, pos);
  if (all->whereis == 10)
    main_delete(all, pos, &i);
  bunny_display(all->win);
  return (GO_ON);
}

void 		init_my_struct(t_pic *all)
{
  all->rediplayer = 0;
  all->intro_pos.x = 0;
  all->intro_pos.y = SIZE_Y - 6;
  all->fen.x = 0;
  all->fen.y = 0;
  all->key = 0;
  all->dep_r.x = 3;
  all->dep_u.x = 0;
  all->dep_u.y = 0;
  all->menu_key = 0;
  all->whereis = 0;
  all->dep_r.y = 0;
  all->pos_gamer.x = 400;
  all->pos_gamer.y = 810;
  all->savepos.x = 400;
  all->savepos.y = 810;
  all->save_cur.x = 400;
  all->save_cur.y = 840;
  all->save_format = 0;
  all->intro = NULL;
  all->skip_intro = NULL;
  all->win = bunny_start(SIZE_X, SIZE_Y, false, "TekAdventure");
  all->haunted = bunny_load_music("source_music/haunted.ogg");
  bunny_sound_volume(&all->haunted->sound, 15.00);
}

int                     main()
{
  static bool	 	what = false;
  t_pic			all;

  if (what == false)
    {
      init_my_struct(&all);
      init_my_wallpaper(what, &all);
    }
  what = true;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(all.win, 20, &all);
  bunny_clear(&all.win->buffer, 0x000000);
  bunny_delete_clipable(&all.pix->clipable);
  bunny_stop(all.win);
  bunny_sound_stop(&all.haunted->sound);
  bunny_delete_sound(&all.haunted->sound);
  return (0);
}
