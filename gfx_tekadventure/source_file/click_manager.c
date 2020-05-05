/*
** click_manager.c for click_manager in /home/longle_h/rendu/gfx_tekadventure/source_file
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Tue Apr 19 17:50:30 2016 Henri Longle
** Last update Wed Apr 20 15:14:02 2016 
*/

#include                <lapin.h>
#include                "my.h"

void			click_2(t_pic *all)
{
  if ((all->mouse->x >= 0 && all->mouse->x <= 163
       && all->mouse->y >= 56 && all->mouse->y <= 98) &&
      all->menu_key == 1 && all->whereis == 2)
    all->search = 1;
  else if (all->mouse->x >= 280 && all->mouse->x <= 430
	   && all->mouse->y >= 720 && all->mouse->y <= 800 && all->key == 1)
    {
      all->save_cur.x = all->mouse->x;
      all->save_cur.y = all->mouse->y;
    }
  else if (all->mouse->x >= 700 && all->mouse->x <= 800
	   && all->mouse->y >= 640 && all->mouse->y <= 720 && all->key == 1)
    {
      all->save_cur.x = all->mouse->x;
      all->whereis = 3;
      all->save_cur.y = all->mouse->y;
    }
  else if ((all->mouse->x >= 990 && all->mouse->x <= 1265
	    && all->mouse->y >= 790 && all->mouse->y <= 875 && all->key == 3))
    launch_game(all);
}

t_bunny_response        click(t_bunny_event_state state,
			      t_bunny_mousebutton key, t_pic *all)
{
  static int          i = 2;

  if (key == BMB_LEFT && state == GO_DOWN)
    {
      if ((all->mouse->x >= 165 && all->mouse->x <= 345
	   && all->mouse->y >= 100 && all->mouse->y <= 120) && i == 2)
        start_game(all, &i);
      else if ((all->mouse->x >= 990 && all->mouse->x <= 1265
		&& all->mouse->y >= 790
		&& all->mouse->y <= 875) && all->key == 1)
	{
	  all->save_cur.x = all->mouse->x;
	  all->save_cur.y = all->mouse->y;
	  all->whereis = 2;
	}
      else if ((all->mouse->x >= 400 && all->mouse->x <= 600
		&& all->mouse->y >= 800
		&& all->mouse->y <= 900) && all->key == 1)
	{
	  all->save_cur.x = all->mouse->x;
	  all->save_cur.y = all->mouse->y;
	}
      click_2(all);
    }
  return (GO_ON);
}
