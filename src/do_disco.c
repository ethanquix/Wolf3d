/*
** do_disco.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 05:23:02 2016 Dimitri Wyzlic
** Last update Sat Jun  4 18:34:00 2016 Dimitri Wyzlic
*/

#include "header.h"

void	play_disco(t_ray *ray)
{
  if (ray->disco == NULL)
    return;
  bunny_sound_volume(&ray->disco->sound, 30);
  bunny_sound_play(&ray->disco->sound);
}

void	stop_disco(t_ray *ray)
{
  if (ray->disco == NULL)
    return;
  bunny_sound_stop(&ray->disco->sound);
}

void		do_disco(t_ray *ray)
{
  int		i;
  int		j;
  unsigned	*pixels;

  pixels = (unsigned *)ray->pix->pixels;
  i = 0;
  while (i < S_HEIGHT)
    {
      j = 0;
      while (j < S_WIDTH)
	{
	  my_tekpixel(i, j, ray->pix, pixels[j + (i * S_WIDTH)]
		      + ray->color_modif);
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	do_disco_key(t_ray *ray, int todo)
{
  if (todo == 1)
    {
      if (ray->color_modif == 0)
	play_disco(ray);
      ray->color_modif = ray->color_modif + 2;
    }
  else
    {
      if (ray->color_modif > 0)
	stop_disco(ray);
      ray->color_modif = 0;
    }
}
