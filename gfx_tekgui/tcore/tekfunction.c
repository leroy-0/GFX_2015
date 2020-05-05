/*
** tekfunction.c for tekfunction in /home/tekm/tek1/gfx_tekgui/tcore
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 22 12:40:24 2016 Tekm
** Last update Thu Feb 25 13:17:41 2016 Tekm
*/

#include <lapin.h>
#include <dlfcn.h>
#include <unistd.h>

void     my_putstr(char *str)
{
  int z;

  z = 0;
  if (str != NULL)
    {
      while (str && str[z])
	write(1, &str[z++], 1);
    }
}

void		*tekfunction(const char *funcname)
{
  void		*handle;

  handle = dlopen(funcname, RTLD_LAZY);
  if (!handle)
    {
      my_putstr("Function \"");
      my_putstr((char*)funcname);
      my_putstr("\" does not exist\n");
    }
  return (handle);
}
