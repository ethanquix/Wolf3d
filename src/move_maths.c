/*
** move_maths.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 13:46:22 2016 Dimitri Wyzlic
** Last update Sat Jun  4 20:17:24 2016 Dimitri Wyzlic
*/

#include <math.h>
#include "header.h"

void	move_forward(t_pos *pos, t_ray *ray)
{
  if (ray->map_data[ABS((((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    pos->posX += pos->dirX * pos->moveSpeed;
  if (ray->map_data[ABS((((int)pos->posX) + ray->map_height) %
			ray->map_height)]
      [ABS((((int)(pos->posY + pos->dirY * pos->moveSpeed))
	    + ray->map_width) % ray->map_width)] == 0)
    pos->posY += pos->dirY * pos->moveSpeed;
}

void	move_back(t_pos *pos, t_ray *ray)
{
  if (ray->map_data[ABS((((int)(pos->posX - pos->dirX * pos->moveSpeed))
		    + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    pos->posX -= pos->dirX * pos->moveSpeed;
  if (ray->map_data[ABS((((int)(pos->posX)) + ray->map_height)
			% ray->map_height)][ABS(
	    (((int)(pos->posY- pos->dirY* pos->moveSpeed)) + ray->map_width)
	    % ray->map_width)] == 0)
    pos->posY -= pos->dirY * pos->moveSpeed;
}

void		rotate_right(t_pos *pos, t_cam *cam)
{
  double	oldDirX;
  double	oldPlaneX;

  oldDirX = pos->dirX;
  oldPlaneX = cam->planeX;
  pos->dirX = pos->dirX * cos(-pos->rotSpeed) - pos->dirY * sin(-pos->rotSpeed);
  pos->dirY = oldDirX * sin(-pos->rotSpeed) + pos->dirY * cos(-pos->rotSpeed);
  cam->planeX = cam->planeX * cos(-pos->rotSpeed)
      - cam->planeY * sin(-pos->rotSpeed);
  cam->planeY = oldPlaneX * sin(-pos->rotSpeed)
      + cam->planeY * cos(-pos->rotSpeed);
}

void	rotate_left(t_pos *pos, t_cam *cam)
{
  double oldDirX;
  double oldPlaneX;

  oldDirX = pos->dirX;
  oldPlaneX = cam->planeX;
  pos->dirX = pos->dirX * cos(pos->rotSpeed) - pos->dirY * sin(pos->rotSpeed);
  pos->dirY = oldDirX * sin(pos->rotSpeed) + pos->dirY * cos(pos->rotSpeed);
  cam->planeX = cam->planeX * cos(pos->rotSpeed)
      - cam->planeY * sin(pos->rotSpeed);
  cam->planeY = oldPlaneX * sin(pos->rotSpeed)
      + cam->planeY * cos(pos->rotSpeed);
}
