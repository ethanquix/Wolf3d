/*
** main_key.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 06:23:51 2016 Dimitri Wyzlic
** Last update Sat Jun  4 06:33:34 2016 Dimitri Wyzlic
*/

#include "header.h"

void	move_player(int key, t_ray *ray)
{
  if (key == 1)
    move_forward(&ray->st_pos, ray);
  if (key == 0)
    move_back(&ray->st_pos, ray);
}

void	rotate_player(int key, t_ray *ray)
{
  if (key == 1)
    rotate_right(&ray->st_pos, &ray->st_cam);
  if (key == 0)
    rotate_left(&ray->st_pos, &ray->st_cam);
}

void	strafe(int key, t_ray *ray)
{
  if (key == 1)
    strafe_left(&ray->st_pos, &ray->st_cam, ray);
  else
    strafe_right(&ray->st_pos, &ray->st_cam, ray);
}
