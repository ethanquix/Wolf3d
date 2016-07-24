/*
** go.c for wolf3d in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 11:34:45 2016 Dimitri Wyzlic
** Last update Sun Jun  5 21:37:47 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include <math.h>
#include "header.h"

void	go(t_bunny_position *curpos, double angle, t_bunny_position *newpos,
	int move)
{
  newpos->x = curpos->x + move * (int)(cos(angle));
  newpos->y = curpos->y + move * (int)(sin(angle));
}
