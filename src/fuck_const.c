/*
** fuck_const.c for dimitri in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May 24 15:54:44 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:54 2016 Dimitri Wyzlic
*/

#include "header.h"

int	my_strlen_const(char const *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (-1);
  while (src[i] != '\0')
    i = i + 1;
  return (i);
}

char	*fuck_const(char const *src)
{
  char	*out;
  int	i;
  int	j;

  i = my_strlen_const(src);
  out = bunny_malloc(sizeof(char *) * i);
  if (out == NULL)
    return (NULL);
  j = 0;
  while (i >= 0)
    {
      out[j] = src[j];
      i = i - 1;
      j = j + 1;
    }
  return (out);
}
