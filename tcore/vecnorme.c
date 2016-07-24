/*
** vecnorme.c for wolf3d in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 11:26:22 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:46:41 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include <math.h>
#include "header.h"

double		vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  double	out;

  out = sqrt(((coord1->x - coord0->x) * (coord1->x - coord0->x))
	     + ((coord1->y - coord0->y) * (coord1->y - coord0->y)));
  return (out);
}
