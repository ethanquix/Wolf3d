/*
** strafe.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 13:31:06 2016 Dimitri Wyzlic
** Last update Sat Jun  4 18:31:35 2016 Dimitri Wyzlic
*/

#include "header.h"

void	strafe_left(t_pos *pos, t_cam *cam, t_ray *ray)
{
  if (ray->map_data[(((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) %
		   ray->map_height][(((int)(pos->posY))
				     + ray->map_width) % ray->map_width] == 0)
    cam->planeX += cam->planeX * pos->moveSpeed;
  if (ray->map_data[(((int)pos->posX) + ray->map_height)
		   % ray->map_height][(((int)(pos->posY
					      + pos->dirY * pos->moveSpeed))
				       + ray->map_width) % ray->map_width] == 0)
    cam->planeY += cam->planeY * pos->moveSpeed;
}

void	strafe_right(t_pos *pos, t_cam *cam, t_ray *ray)
{
  if (ray->map_data[(((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) %
		   ray->map_height][(((int)(pos->posY)) + ray->map_width) %
				    ray->map_width] == 0)
    {
      cam->planeX -= cam->planeX * pos->moveSpeed;
    }
  if (ray->map_data[(((int)pos->posX) + ray->map_height) %
		   ray->map_height][(((int)(pos->posY
					    + pos->dirY* pos->moveSpeed))
				     + ray->map_width) % ray->map_width] == 0)
    {
      cam->planeY -= cam->planeY * pos->moveSpeed;
    }
}
