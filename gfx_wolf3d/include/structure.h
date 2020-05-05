/*
** structure.h for structure in /home/leroy_0/rendu/lightning_2015
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Nov 10 10:46:05 2015 leroy_0
** Last update Sun Jan  3 23:13:36 2016 leroy_0
*/

#ifndef STRUCTURE_H_
# define STRUCTURE_H_

# define        degree          M_PI/180
# define        fov             65
# define        camspeed        2

typedef struct s_struct_data
{
  t_bunny_pixelarray    *pix;
  t_bunny_window        *win;
  t_bunny_position	fen;
  t_bunny_position	pos[2];
  t_bunny_position	save[4];
  unsigned int		color[3];
  char			*nameofmap;
  int			tmp;
  char			*strtmp;
  int			**map;
  int			tile_size;
  int			width;
  int			height;
  int			startx;
  int			starty;
  int			startangle;
  int			x;
  int			y;
  int			angle;
  int			**wall;
  int			dist;
  int			colh;
}		t_struct_data;

#endif /*!STRUCTURE_H_!*/
