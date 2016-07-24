/*
** gunfire.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:00:07 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:58:46 2016 Dimitri Wyzlic
*/

#include "header.h"

void		set_blank(t_bunny_pixelarray *pix, t_ray *ray)
{
  int		i;
  unsigned	*pixels;

  i = 0;
  if (ray->bullets <= 0)
    {
      bunny_sound_play(&ray->reload->sound);
      ray->bullets = 5;
      return;
    }
  while (i < (S_HEIGHT * S_WIDTH))
    {
      pixels = (unsigned *)pix->pixels;
      pixels[i] = WHITE;
      i = i + 1;
    }
  bunny_sound_play(&ray->gun_sound->sound);
  ray->bullets = ray->bullets - 1;
  bunny_blit(&ray->window->buffer, &ray->pix->clipable, NULL);
  bunny_display(ray->window);
}
