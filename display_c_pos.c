/*
** display_c_pos.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 06:44:17 2016 Dimitri Wyzlic
** Last update Sun Jun  5 22:15:20 2016 Dimitri Wyzlic
*/

#include "header.h"

void	disp_cur_pos(t_ray *ray)
{
  int	cposX;
  int	cposY;
  int	i;
  int	j;

  i = 0;
  cposX = (int)ray->st_pos.posX;
  cposY = (int)ray->st_pos.posY;
  while (i < ray->minmap_jx)
    {
      j = 0;
      while (j < ray->minmap_jy)
	{
	  my_tekpixel((i + (ray->minmap_jx * cposX)) % 200, (j
		      + (ray->minmap_jy* cposY)) % 200, ray->pix, TEAL);
	  j = j + 1;
	}
      i = i + 1;
    }
}
