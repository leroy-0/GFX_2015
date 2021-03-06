/*
** structure.h for structure in /home/leroy_0/rendu/lightning_2015
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Nov 10 10:46:05 2015 leroy_0
** Last update Thu Feb 25 13:39:42 2016 Tekm
*/

#ifndef			STRUCTURE_H_
# define		STRUCTURE_H_

# define		SIZE_X		1025
# define		SIZE_Y		769
#include		<lapin.h>

typedef struct		s_struct
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_pixelarray	*out;
  t_bunny_position	fen;
  t_bunny_position	pos[3];
  t_bunny_position	save[4];
  const	t_bunny_position	*mouse;
  t_color		color;
  int			square_size;
  int			opt;
  bool			yes;
  int			save_format;
}			t_struct;

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color);
void		*tekfunction(const char *funcname);
void		tektext(t_bunny_pixelarray *out,
			const char *str,
			t_bunny_pixelarray *font_png);
#endif			/*!STRUCTURE_H_!*/
