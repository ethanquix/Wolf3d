/*
** my_line.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 12:36:34 2016 Dimitri Wyzlic
** Last update Sun Jun  5 22:07:18 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void		my_tekpixel(int x, int y, t_bunny_pixelarray *pix,
			    unsigned int color)
{
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  pixels[ABS((y + (x * S_WIDTH))) % (S_HEIGHT * S_WIDTH)] = color;
}

void	my_verline(int x, int a, int b, t_color *color,
		   t_bunny_pixelarray *pix)
{
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  if (a > b)
    my_swap(&a, &b);
  if (a < 0 || b > S_HEIGHT)
    {
      a = 0;
      b = S_HEIGHT;
    }
  while (a < b)
    {
      pixels[ABS((x + (a * S_WIDTH)))] = color->full;
      a = a + 1;
    }
}

void	my_horline(int y, int a, int b, t_color *color,
		   t_bunny_pixelarray *pix)
{
  if (a > b)
    my_swap(&a, &b);
  while (a < b)
    {
      tekpixel_coord(pix, a, y, color);
      a = a + 1;
    }
}
