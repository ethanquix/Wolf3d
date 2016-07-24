/*
** do_raycast.c for wolf3d in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 17:46:36 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:27 2016 Dimitri Wyzlic
*/

#include "header.h"

void	set_color(t_color *color, t_ray *ray)
{
  ray->mapX = ABS((ray->mapX + ray->map_height) % ray->map_height);
  ray->mapY = ABS((ray->mapY + ray->map_width) % ray->map_width);
  if (ray->map_data[ray->mapX][ray->mapY] == 1)
    color->full = RED;
  if (ray->map_data[ray->mapX][ray->mapY] == 8)
    color->full = GREEN;
  if (ray->map_data[ray->mapX][ray->mapY] == 3)
    color->full = BLUE;
  if (ray->map_data[ray->mapX][ray->mapY] == 4)
    color->full = WHITE;
  if (ray->side == 1)
    color->full = color->full / 2;
}

void	calcul_step(t_ray *ray)
{
  ray->hit = 0;
  if (ray->rayDirX < 0)
    {
      ray->stepX = -1;
      ray->sideDistX = (ray->rayPosX - ray->mapX) * ray->deltaDistX;
    }
  else
    {
      ray->stepX = 1;
      ray->sideDistX = (ray->mapX + 1.0 - ray->rayPosX) * ray->deltaDistX;
    }
  if (ray->rayDirY < 0)
    {
      ray->stepY = -1;
      ray->sideDistY = (ray->rayPosY - ray->mapY) * ray->deltaDistY;
    }
  else
    {
      ray->stepY = 1;
      ray->sideDistY = (ray->mapY + 1.0 - ray->rayPosY) * ray->deltaDistY;
    }
}

void	do_dda_next(t_ray *ray)
{
  if (ray->side == 0)
    ray->perpWallDist = (ray->mapX - ray->rayPosX + (1 - ray->stepX)
			 / 2) / ray->rayDirX;
  else
    ray->perpWallDist = (ray->mapY - ray->rayPosY + (1 - ray->stepY)
			 / 2) / ray->rayDirY;
  ray->lineHeight = (int)(S_HEIGHT / ray->perpWallDist);
  ray->drawStart = -(ray->lineHeight) / 2 + S_HEIGHT / 2;
  if (ray->drawStart < 0)
    ray->drawStart = 0;
  ray->drawEnd = ray->lineHeight / 2 + S_HEIGHT / 2;
  if (ray->drawEnd >= S_HEIGHT)
    ray->drawEnd = S_HEIGHT - 1;
  set_color(ray->color, ray);
}

void	do_dda(t_ray *ray)
{
  int	i;

  i = 0;
  while (ray->hit == 0 && i < ray->map_height * ray->map_width)
    {
      if (ray->sideDistX < ray->sideDistY)
        {
          ray->sideDistX += ray->deltaDistX;
          ray->mapX += ray->stepX;
          ray->side = 0;
        }
      else
        {
          ray->sideDistY += ray->deltaDistY;
          ray->mapY += ray->stepY;
          ray->side = 1;
        }
      if (ray->map_data[ABS((ray->mapX + ray->map_height)
			    % ray->map_height)][ABS((ray->mapY + ray->map_width)
						    % ray->map_width)] > 0)
	ray->hit = 1;
      i = i + 1;
    }
  do_dda_next(ray);
}
