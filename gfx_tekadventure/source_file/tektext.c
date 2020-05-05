/*
** tektext.c for tektext in /home/klein_h/Documents/gfx_tekgui/tcore
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Feb 25 12:54:21 2016 Arthur Klein
** Last update Mon Apr 18 22:45:16 2016 
*/

#include <lapin.h>

#include <lapin.h>
#include "my.h"

int             do_text(t_bunny_pixelarray *out,
			const char *str,
			t_bunny_pixelarray *font_png,
			t_text          *text)
  {
    text->i = 0;
    text->savez = text->z;
    text->car = str[text->cpt]*5;
    while (text->i <= 6)
      {
        text->x = text->car;
        while (text->x <= text->car + 4)
          {
            ((unsigned int *)(out->pixels))[text->z]
	      = ((unsigned int *)(font_png->pixels))[text->x];
            text->z++;
            text->x++;
          }
        text->i++;
        text->z -= 5;
        text->z += out->clipable.clip_width;
        text->car = text->car + font_png->clipable.clip_width;
      }
    text->cpt++;
    text->z = text->savez + 6;
    return (text->cpt);
  }

void            tektext(t_bunny_pixelarray *out,
			const char *str, t_bunny_pixelarray *font_png,
			const t_bunny_position *pos)
  {
    t_text                text;

    text.savey = pos->y;
    text.z = pos->y * out->clipable.clip_width + pos->x;
    text.savepos = pos->y * out->clipable.clip_width + pos->x;
    text.cpt = 0;
    text.savez = 0;
    while (str[text.cpt])
      {
        text.savez = text.z;
        if (str[text.cpt] != '\n')
          {
            text.cpt = do_text(out, str, font_png, &text);
            text.z = text.savez + 6;
          }
        if (text.z - (text.savey * out->clipable.clip_width) >=
        out->clipable.clip_width - 5 || str[text.cpt] == '\n')
          {
            text.savepos = text.savepos + (out->clipable.clip_width * 8);
            text.savey += (out->clipable.clip_width * 8);
            text.z = text.savepos;
            text.cpt++;
          }
      }
  }
