/*
** tekpixel.c for tekpixel in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sun Apr 24 23:24:17 2016 Dimitri Wyzlic
** Last update Sat Jun  4 09:00:37 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
                t_color *color)
{
  unsigned	*pixels;
  int		finalpos;

  pixels = (unsigned *)pix->pixels;
  finalpos = pos->x + (pos->y * pix->clipable.clip_width);
  pixels[finalpos] = color->full;
}

void		tekpixel_coord(t_bunny_pixelarray *pix, int x, int y,
		       t_color *color)
{
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  pixels[x + (y * pix->clipable.clip_width)] = color->full;
}
