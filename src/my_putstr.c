/*
** my_putstr.c for day04 in /home/wyzlic_a/rendu/j04
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Mar  3 10:32:45 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:23:08 2016 Dimitri Wyzlic
*/

#include "header.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return 0;
  while (str[i] != '\0')
  {
    my_putchar(str[i]);
    i = i + 1;
  }
  return (0);
}
