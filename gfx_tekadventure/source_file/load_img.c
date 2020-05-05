/*
** load_img.c for load_img in /home/bruere_s/Projet/Infographie/gfx_tekpaint/src
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Tue Jan 26 23:31:21 2016 Sebastien BRUERE
** Last update Sun Apr 17 16:05:06 2016 Tekm
*/

#include		<unistd.h>
#include		"bmp.h"
#include		"my.h"

int			load_image(t_pic *data, char *file)
{
  t_bunny_position	pos[1];
  char			*ext;

  if (((ext = parse_file(file)) == NULL))
    return (0);
  pos[0].x = 128;
  pos[0].y = 0;
  if (my_strncmp(ext, "bmp", 3) == 0)
    {
      if (load_bitmap(file, data, pos) == NULL && file != NULL)
	{
	  write(2, "Image can't be load\n", 21);
	  return (1);
	}
    }
  return (0);
}

char			*parse_file(char *str)
{
  int			i;
  char			*ext;

  i = 0;
  ext = NULL;
  while (str[i] != '\0')
    i++;
  while (i >= 0)
    {
      if (str[i] == '.')
	{
	  i++;
	  ext = loop_parse(str, i);
	  i = 1;
	}
      i--;
    }
  if (ext != NULL)
    return (ext);
  else
    return (NULL);
}

char			*loop_parse(char *str, int i)
{
  int			save;
  char			*ext;
  int			j;

  j = 0;
  save = i;
  while (str[i] != '\0')
    i++;
  ext = malloc(sizeof(char) * (i - save + 1));
  i = save;
  while (str[i] != '\0')
    ext[j++] = str[i++];
  ext[j] = '\0';
  return (ext);
}
