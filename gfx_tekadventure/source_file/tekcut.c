/*
** tekcut.c for tekcut in /home/klein_h/Bureau/gfx_tekadventure/source_file
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sun Apr 17 21:33:48 2016
** Last update Wed Apr 20 15:12:32 2016 
*/

#include                <lapin.h>
#include                "my.h"

void		print_(t_bunny_pixelarray *out,
		       t_bunny_pixelarray *font_png, t_bunny_position pos)
{
  int 		i;
  int 		x_out;
  int 		v_ascii;
  int 		x;

  i = 0;
  x_out = 0;
  v_ascii = font_png->clipable.clip_width * (pos.y * 98) + (pos.x * 65);
  while (i < 98)
    {
      x = v_ascii;
      while (x < v_ascii + 65)
	{
	  ((t_color *)(out->pixels))[x_out]
	    = ((t_color *)(font_png->pixels))[x];
	  x_out++;
	  x++;
	}
      i++;
      x_out += out->clipable.clip_width - 65;
      v_ascii += font_png->clipable.clip_width;
    }
}

void		init_cut(t_bunny_pixelarray *out,
			t_bunny_position *pos,
			t_pic *all)
{
  pos->x = 0;
  pos->y = 0;
  all->tmp = bunny_new_pixelarray(out->clipable.clip_width / 2,
				  out->clipable.clip_height / 2);
  out->clipable.scale.x = 2;
  out->clipable.scale.y = 2;
  tekblit(all->tmp, out, pos);
  all->tmp->clipable.scale.x = 1;
  all->tmp->clipable.scale.y = 1;
  pos->x = 0;
  pos->y = 0;
  tekfill(out, 0x000000);
  delcol(out, all->pix, &all->pos_gamer);
  tekblit(out, all->tmp, pos);
  pos->x = 165;
  pos->y = 100;
}

void		tekcut(t_bunny_pixelarray *out,
		       t_bunny_pixelarray *font_png,
		       t_bunny_position pos, t_pic *all)
{
  print_(out, font_png, pos);
  if (all->savepos.y - 25 > all->pos_gamer.y || all->rediplayer == 1)
    {
      init_cut(out, &pos, all);
      if (all->rediplayer != 1)
	{
	  all->savepos.x = all->pos_gamer.x;
	  all->savepos.y = all->pos_gamer.y;
	}
      all->rediplayer = 1;
    }
  if (all->savepos.y + 25 <= all->pos_gamer.y)
    all->rediplayer = 2;
  delcol(out, all->pix, &all->pos_gamer);
}
