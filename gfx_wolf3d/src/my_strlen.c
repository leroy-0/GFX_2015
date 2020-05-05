/*
** my_strlen.c for my_strlen in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 13:45:25 2015 maxime leroy
** Last update Tue Dec 15 11:14:08 2015 leroy_0
*/

int	my_strlen(char *str)
{
  int z;

  z = 0;
  while (str && str[z] != '\0')
    z += 1;
  return (z);
}
