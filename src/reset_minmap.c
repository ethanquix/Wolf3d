/*
** reset_minmap.c for map in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 03:42:04 2016 Dimitri Wyzlic
** Last update Sat Jun  4 03:46:00 2016 Dimitri Wyzlic
*/

#include "header.h"

void	reset_minmap(t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  while (i < 200)
    {
      j = 0;
      while (j < 200)
	{
	  ray->minmap[i][j] = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
}
