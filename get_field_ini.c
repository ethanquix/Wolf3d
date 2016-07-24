/*
** get_field_ini.c for dimitri in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May 24 15:36:23 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:27:29 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	count_ini(t_bunny_ini *ini, char *name_field, char *name)
{
  int	out;

  out = 0;
  while (bunny_ini_get_field(ini, name, name_field, out))
    out = out + 1;
  return (out);
}

int		get_field_int(t_bunny_ini *ini, char *cat, char *field)
{
  char const	*out;

  out = bunny_ini_get_field(ini, cat, field, 0);
  if (out == 0)
    return (0);
  return (my_getnbr(out));
}

char		*get_field_char(t_bunny_ini *ini, char *cat, char *field)
{
  char const	*out;

  out = bunny_ini_get_field(ini, cat, field, 0);
  if (out == 0)
    return (0);
  return (fuck_const(out));
}

int	*get_field_int_s(t_bunny_ini *ini, char *cat, char *field, int max)
{
  int	*out;
  int	i;

  i = 0;
  out = bunny_malloc(sizeof(int *) * max);
  if (out == NULL || max <= 0)
    return (NULL);
  while (i < max)
    {
      out[i] = my_getnbr(bunny_ini_get_field(ini, cat, field, i));
      if (out[i] == -1)
	return (NULL);
      i = i + 1;
    }
  return (out);
}
