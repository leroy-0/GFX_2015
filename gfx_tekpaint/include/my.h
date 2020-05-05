/*
** my.h for my.h in /home/leroy_0/rendu/Piscine_C_J09/ex_02
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  8 13:42:23 2015 maxime leroy
** Last update Thu Jan 28 22:24:32 2016 leroy_0
*/

#ifndef			MY_H_
# define		MY_H_

#include		"structure.h"

int     		my_addx(t_bunny_position *pos, int addx);
void    		tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
int			draw_circle(t_struct *data, int *i);
void    		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
void			color_palette_blue(t_struct *data);
void			color_palette_red(t_struct *data);
void			color_palette_green(t_struct *data);
void			color_full(t_struct *data);
void 			aff_lim(t_struct *data);
void 			key_reponse(t_bunny_event_state state, t_bunny_keysym key, t_struct *data);
t_bunny_response        key(t_bunny_event_state state, t_bunny_keysym key, t_struct *data);
void			click_opt(t_struct *data, int *i);
t_bunny_response	click(t_bunny_event_state state, t_bunny_mousebutton key, t_struct *data);
void 			opt_line(t_struct *data, int *i);
int    			square(t_struct *data, int *i);
void			draw_mini_circle(t_struct *data);
void			print_case_square(t_struct *data);
void			print_case_circle(t_struct *data);
void                    draw_windows(t_struct *data);
void			set_max_heap_size(size_t);
int                     rectangle(t_struct *data, int *i);
int                     triangle(t_struct *data, int *i);
t_color			getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos);
void			check_state(t_struct *data, t_bunny_event_state state);
int			erase_opt(t_struct *data);
int			tek_pencil(t_struct *data, int *i);
int                     roller(t_struct *data, int *i, int square_size);
int			bombe(t_struct *data, int *i);
void			save_format_bmp(t_struct *data);
void			new_pixel_array(t_struct *data);
void			filter(t_struct *data);
void			invers_filter(t_struct *data, int *i);
void			form(t_struct *data, int *opt, int *i);
void			options(t_struct *data, int *opt, int *i);
void			click_change_value_pal(t_struct *data);
void			loop_square(t_struct *data);
void			loop_circle(t_struct *data, int x, int y);
void			loop_bombe(t_struct *data, int x, int y);
void			pipette(t_struct *data, int *i);
void			loop_filter(t_struct *data, t_bunny_position *pos);
int			load_image(t_struct *data, char *file);
int			load_tek(const char *name, t_struct *data, t_bunny_position *pos);
char			*parse_file(char *str);
int			my_strncmp(char *s1, char *s2, int n);
char			*loop_parse(char *str, int i);
bool                    push(t_struct *data);
bool                    pop(t_struct *data);
void                    my_stack(t_struct *data);
int                     my_upperx(t_struct *data, t_color oldcolor, t_color tmpcol);
int                     my_lowerx(t_struct *data, t_color oldcolor, t_color tmpcol);
int                     my_flood_fill(t_struct *data, t_color newColor, t_color oldColor);
int                     my_uppery(t_struct *data, t_color oldcolor, t_color tmpcol);
int                     my_lowery(t_struct *data, t_color oldcolor, t_color tmpcol);

#endif			/* !MY_H_ */
