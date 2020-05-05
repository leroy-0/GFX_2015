/*
** my.h for my.h in /home/klein_h/Bureau/gfx_tekadventure/include
**
** Made by
** Login   <klein_h@epitech.net>
**
** Started on  Sat Apr 16 17:25:05 2016
** Last update Tue Apr 19 18:39:16 2016 Henri Longle
*/

#ifndef                 MY_H_
# define                MY_H_

# define                SIZE_X          1400
# define                SIZE_Y          900
#include                <lapin.h>

typedef struct          s_pic
  {
    t_bunny_pixelarray	*pix;
    t_bunny_pixelarray	*skip_intro;
    t_bunny_pixelarray	*resize;
    t_bunny_pixelarray	*start;
    t_bunny_pixelarray	*inventory;
    t_bunny_pixelarray  *pix_dead;
    int 		menu_key;
    t_bunny_position	save_cur;
    t_bunny_position	savepos;
    t_bunny_position	intro_pos;
    int			whereis;
    int			rediplayer;
    t_bunny_pixelarray	*perso;
    t_bunny_pixelarray	*start_save;
    t_bunny_music 	*haunted;
    t_bunny_window	*win;
    t_bunny_position	dep_r;
    t_bunny_position	dep_u;
    t_bunny_pixelarray	*tmp;
    t_bunny_pixelarray  *intro;
    int 		search;
    t_bunny_position    fen;
    t_bunny_position    pos_gamer;
    t_bunny_position    save[4];
    const t_bunny_position *mouse;
    t_color             color;
    int                 key;
    int                 save_format;
  }                     t_pic;

typedef struct          s_blit
  {
    int			saveyo;
    int			saveyd;
    int			cpt;
    int			i;
  }                     t_blit;

typedef struct          s_plus
  {
    int			cpt_row;
    int			cpt_col;
    int			saveyo;
    int			cpt;
    int			i;
  }                     t_plus;

typedef struct		s_text
  {
    int                 savez;
    int                 savey;
    int                 savepos;
    int                 car;
    int                 cpt;
    int                 x;
    int                 i;
    int                 z;
  }			t_text;

typedef struct          s_coldel
  {
    t_bunny_position    pos;
    t_bunny_position    save;
    t_color             color;
    t_color             rcolor;
    t_color             tmpcol;
  }                     t_coldel;

char			*fill_msg_intro();
void                    launch_game(t_pic *all);
void			*load_bitmap(const char *file, t_pic *data,
				     t_bunny_position *pos_bmp);

void			increase_size_text(t_pic *all, char *msg,
					   int nbline, int scale);
void			tektext(t_bunny_pixelarray *out,
				const char *str,
				t_bunny_pixelarray *font_png,
				const t_bunny_position *pos);
void			tekresize(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *resized, int resize);
int			my_strncmp(char *s1, char *s2, int nb);
t_color			getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void 			check_pos(t_pic *all);
void			tekcut(t_bunny_pixelarray *out,
			       t_bunny_pixelarray *font_png,
			       t_bunny_position pos, t_pic *all);
t_bunny_response	key_reponse(t_bunny_event_state state,
					    t_bunny_keysym key, t_pic *all);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton key, t_pic *all);
void			tekfill(t_bunny_pixelarray *pix, unsigned int color);
void			       tekplus(t_bunny_pixelarray *destination,
					const t_bunny_pixelarray *origin,
					const t_bunny_position *pos);
int			my_strlen(char *str);
void			tekcoldel(t_bunny_pixelarray    *dest,
				  t_color               *color,
				  t_color               *rcolor);
void			delcol(t_bunny_pixelarray *destination,
			       t_bunny_pixelarray *origin,
			       t_bunny_position *position);
int			text_intro(t_pic *all);
void		        tekblit(t_bunny_pixelarray *destination,
				const t_bunny_pixelarray *origin,
				const t_bunny_position *pos);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton key, t_pic *all);

void			start_game(t_pic *all, int *i);
t_bunny_response	init_my_wallpaper(bool what, t_pic *pic);
void			tekfill(t_bunny_pixelarray *pix, unsigned int color);
void			move_x_minus(t_pic *all);
void			move_x_plus(t_pic *all);
void			move_stair(t_pic *all);
void			move_unstair(t_pic *all);

#endif                  /*!MY_H_!*/
