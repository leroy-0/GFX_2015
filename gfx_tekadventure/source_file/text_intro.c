/*
** text_intro.c for text_intro in /home/bruere_s/Projet/gfx_tekadventure/source_file
**
** Made by
** Login   <bruere_s@epitech.net>
**
** Started on  Mon Apr 18 12:42:23 2016
** Last update Tue Apr 19 18:43:55 2016 Henri Longle
*/

#include	"my.h"

int                     text_intro(t_pic *all)
{
  char                  *msg;
  int			nbline;
  static bool           cpt = true;

  nbline = 13;
  msg = fill_msg_intro();
  if (cpt == true)
    {
      cpt = false;
      all->tmp = bunny_new_pixelarray(my_strlen(msg) * 6, 8 * nbline);
      all->skip_intro = bunny_new_pixelarray(80, 20);
      all->skip_intro =
	bunny_load_pixelarray("wallpaper_source/skip_intro.png"),
      tekfill(all->tmp, 0x000000);
    }
  increase_size_text(all, msg, nbline, 3);
  return (0);
}

void		increase_size_text(t_pic *all, char *msg, int nbline, int scale)
{
  t_bunny_position      pos;

  pos.x = 0;
  pos.y = 0;
  tektext(all->tmp, msg, all->start, &pos);
  all->tmp->clipable.scale.x = scale;
  all->tmp->clipable.scale.y = scale;
  all->intro = bunny_new_pixelarray(my_strlen(msg)
				    * 6 * all->tmp->clipable.scale.x,
				    8 * nbline * all->tmp->clipable.scale.y);
  tekfill(all->intro, 0x000000);
  tekplus(all->intro, all->tmp, &pos);
}

char            *fill_msg_intro()
{
  char          *msg;

    msg = "  Mouloud and his daughter were happy.\n\n  A morning, Mouloud \
get out of his bed, like each morning, \n  and wake up his daughter.\n\n  \
This morning, the bed was empty... And an enveloppe\n  was on the \
nightstand,  \
with letters printed in blood ink, \n  \"Come to me\".\n\n  Inside, an adress \
was written.\n\n  With just the necessary, Mouloud taken the road\n\
  and left for this adress.";
    return (msg);
}
