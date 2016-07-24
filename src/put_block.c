/*
** put_block.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:40:20 2016 Dimitri Wyzlic
** Last update Sat Jun  4 20:23:50 2016 Dimitri Wyzlic
*/

#include "header.h"

void	get_pos_front(t_ray *ray, t_pos *pos)
{
  if (ray->map_data[ABS((((int)(pos->posX
			    + pos->dirX * pos->moveSpeed))
			 + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    ray->posxfr = (int) (pos->dirX + pos->posX);
  if (ray->map_data[ABS((((int)pos->posX)
			 + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY + pos->dirY * pos->moveSpeed)) + ray->map_width)
	   % ray->map_width)] == 0)
    ray->posyfr = (int) (pos->dirY + pos->posY);
}

int		put_block(t_ray *ray)
{
  double	bcposx;
  double	bcposy;

  bcposx = ray->st_pos.posX;
  bcposy = ray->st_pos.posY;
  get_pos_front(ray, &ray->st_pos);
  if (((int)ray->st_pos.posX == ray->posxfr) &&
      ((int)ray->st_pos.posY == ray->posyfr))
    return (1);
  ray->map_data[ABS(ray->posxfr % ray->map_height)]
      [ABS(ray->posyfr % ray->map_width)] = 1;
  ray->st_pos.posX = bcposx;
  ray->st_pos.posY = bcposy;
  data_to_map(ray);
  return (0);
}
