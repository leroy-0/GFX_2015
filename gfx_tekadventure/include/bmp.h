/*
** bmp.h for bmp.h in /home/tekm/tek1/gfx_tekadventure
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Apr 17 23:38:59 2016 Tekm
** Last update Sun Apr 17 23:39:04 2016 Tekm
*/

#ifndef		BMP_H_
# define	BMP_H_

#include	<lapin.h>
#include "my.h"

# define	HEADER_SIZE	54
typedef struct	s_pix
{
  unsigned char		R;
  unsigned char		G;
  unsigned char		B;
  unsigned char		L;
} __attribute__ ((packed)) t_pix;

typedef	struct	s_bmp_header
{
  unsigned short int	id_field;
  unsigned int		size_file;
  unsigned int		do_not_use;
  unsigned int		pos_pix;
  unsigned int		header;
  unsigned int		width;
  unsigned int		height;
  unsigned short int	plan_bit;
  unsigned short int	bit_per_pixel;
  unsigned int		compression;
  unsigned int		size_pict;
  unsigned int		pixel_per_meter_width;
  unsigned int		pixel_per_meter_height;
  unsigned int		nb_color;
  unsigned int		nb_imp_color;
} __attribute__ ((packed)) t_bmp;

t_pix		*read_24_pix(int, int);
t_pix		*read_32_pix(int, int);
void		load_24_pix(t_bmp *, int, t_pic *, t_bunny_position *);
void		load_32_pix(t_bmp *, int, t_pic *, t_bunny_position *);
void		*load_bitmap(const char *, t_pic *, t_bunny_position *);
int		write_pix(int, t_pic *);
char      *loop_parse(char *str, int i);
int             create_file(t_pic *data);
char      *parse_file(char *str);
void      tekpixel(t_bunny_pixelarray *pix,
         t_bunny_position *pos,
         t_color *color);

#endif		/* !BMP_H_ */

