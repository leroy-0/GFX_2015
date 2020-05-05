/*
** bmp.h for BMP in /home/longle_h/rendu/gfx_tekpaint
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Fri Jan  8 17:15:06 2016 Henri Longle
** Last update Tue Jan 26 23:48:41 2016 Sebastien BRUERE
*/

#ifndef		BMP_H_
# define	BMP_H_

#include	<lapin.h>
#include	"structure.h"

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
void		load_24_pix(t_bmp *, int, t_struct *, t_bunny_position *);
void		load_32_pix(t_bmp *, int, t_struct *, t_bunny_position *);
void		*load_bitmap(const char *, t_struct *, t_bunny_position *);
int		write_pix(int, t_struct *);
int             create_file(t_struct *data);

#endif		/* !BMP_H_ */
