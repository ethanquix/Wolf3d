/*
** load_sound.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:16:55 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:53:55 2016 Dimitri Wyzlic
*/

#include "header.h"

int	load_sound(t_ray *ray)
{
  ray->disco = bunny_load_music("disco.ogg");
  if (ray->disco == NULL)
    return (1);
  ray->gun_sound = bunny_load_music("gun.ogg");
  if (ray->gun_sound == NULL)
    return (1);
  ray->reload = bunny_load_music("reload.ogg");
  if (ray->reload == NULL)
    return (1);
  bunny_sound_volume(&ray->gun_sound->sound, 30);
  bunny_sound_volume(&ray->reload->sound, 30);
  return (0);
}
