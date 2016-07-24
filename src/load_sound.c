/*
** load_sound.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:16:55 2016 Dimitri Wyzlic
** Last update Sun Jul 24 16:08:56 2016 Dimitri Wyzlic
*/

#include "header.h"

int	load_sound(t_ray *ray)
{
  ray->disco = bunny_load_music("sounds/disco.ogg");
  if (ray->disco == NULL)
    return (1);
  ray->gun_sound = bunny_load_music("sounds/gun.ogg");
  if (ray->gun_sound == NULL)
    return (1);
  ray->reload = bunny_load_music("sounds/reload.ogg");
  if (ray->reload == NULL)
    return (1);
  bunny_sound_volume(&ray->gun_sound->sound, 30);
  bunny_sound_volume(&ray->reload->sound, 30);
  return (0);
}
