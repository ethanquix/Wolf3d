/*
** draw_gun.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 05:03:42 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:27:26 2016 Dimitri Wyzlic
*/

#include "header.h"

void	cross_hor(t_ray *ray)
{
 int	start;
 int	end;

 start = (S_WIDTH / 2 - S_WIDTH / 15) % S_WIDTH;
 if (start < 0)
   return;
 end = (S_WIDTH / 2 + S_WIDTH / 15) % S_WIDTH;
 while (start < end)
   {
     my_tekpixel(S_HEIGHT / 2, start, ray->pix, TEAL);
     start = start + 1;
   }
}

void	cross_ver(t_ray *ray)
{
 int	start;
 int	end;

 start = (S_HEIGHT / 2 - S_HEIGHT / 12) % S_HEIGHT;
 if (start < 0)
   return;
 end = (S_HEIGHT / 2 + S_HEIGHT / 12) % S_HEIGHT;
 while (start < end)
   {
     my_tekpixel(start, S_WIDTH / 2, ray->pix, TEAL);
     start = start + 1;
   }
}

void	draw_cross(t_ray *ray)
{
  cross_hor(ray);
  cross_ver(ray);
}
