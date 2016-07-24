/*
** my_getnbr.c for fire in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sun May  8 17:01:40 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:16 2016 Dimitri Wyzlic
*/

#include "header.h"

static int	my_strlen(char const *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_getnbr(char const *str)
{
  int	nbr;
  int	i;
  int	pow;

  nbr = 0;
  pow = 1;
  if (str == NULL)
    {
      my_putstr("Error bad width or height\n");
      return (-1);
    }
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      nbr = nbr + pow * (str[i] - '0');
      pow = pow * 10;
      i = i - 1;
    }
  return (nbr);
}
