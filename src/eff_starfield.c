/*
** eff_starfield.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May  3 21:21:46 2016 Dimitri Wyzlic
** Last update Sat Jun  4 08:46:27 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

t_bunny_star	*set_star(int nb)
{
  t_bunny_star	*star;
  int		i;

  i = 0;
  star = bunny_malloc(nb * (sizeof(t_bunny_star)));
  if (star == NULL)
    return (NULL);
  while (i < nb)
    {
      star[i].x = 50;
      star[i].y = 50;
      star[i].x_speed = -1 - (rand()%1000 / 100.0);
      i = i + 1;
    }
  return (star);
}

void			starfield(t_bunny_pixelarray *pix, t_bunny_star *star,
				  size_t nstar)
{
    unsigned		i;
    t_bunny_position	pos;
    t_color		*color;

    color = bunny_malloc(2 * sizeof(t_color *));
    if (color == NULL)
      return;
    color->full = WHITE;
    i = 0;
    while (i < nstar)
      {
	  star[i].y = star[i].y - star[i].x_speed;
	  if (star[i].y > S_HEIGHT / 2)
	    {
		star[i].y = 0;
		star[i].x = rand() % (S_WIDTH);
	    }
	  pos.x = star[i].x;
	  pos.y = star[i].y;
	  tekpixel(pix, &pos, color);
	  i = i + 1;
      }
    bunny_free(color);
}
