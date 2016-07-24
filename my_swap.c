/*
** my_swap.c for day04 in /home/wyzlic_a/rendu/j04
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Mar  3 10:22:39 2016 Dimitri Wyzlic
** Last update Sat Jun  4 08:56:14 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

void			swap_pos(t_bunny_position *a, t_bunny_position *b)
{
  t_bunny_position	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
