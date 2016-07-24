/*
** do_slomo.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 03:50:22 2016 Dimitri Wyzlic
** Last update Sat Jun  4 04:32:50 2016 Dimitri Wyzlic
*/

#include "header.h"

void	main_slowmo(t_ray *ray)
{
  if (ray->is_slowmo == 0)
    {
      ray->st_pos.moveSpeed = 0.02;
      ray->st_pos.rotSpeed = 0.002;
      ray->is_slowmo = 1;
    }
  else
    {
      ray->st_pos.moveSpeed = 0.1;
      ray->st_pos.rotSpeed = 0.01;
      ray->is_slowmo = 0;
    }
}
