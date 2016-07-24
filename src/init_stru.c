/*
** init_stru.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 18:33:27 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:56:20 2016 Dimitri Wyzlic
*/

#include <math.h>
#include "header.h"

int	ini_set(t_pos *pos, t_cam *cam)
{
  pos->dirX = 1;
  pos->dirY = 1;
  cam->planeX = 0;
  cam->planeY = 0.66;
  pos->time = 0;
  pos->oldTime = 0;
  pos->moveSpeed = 0.1;
  pos->rotSpeed = 0.01;
  return (0);
}

void	init_stru(t_pos *pos, t_cam *cam, t_ray *ray, int x)
{
  cam->cameraX = 2 * x / (double)S_WIDTH - 1;
  ray->rayPosX = pos->posX;
  ray->rayPosY = pos->posY;
  ray->rayDirX = pos->dirX + cam->planeX * cam->cameraX;
  ray->rayDirY = pos->dirY + cam->planeY * cam->cameraX;
  ray->mapX = (int)ray->rayPosX;
  ray->mapY = (int)ray->rayPosY;
  ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) /
			 (ray->rayDirX * ray->rayDirX));
  ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) /
			 (ray->rayDirY * ray->rayDirY));
  ray->hit = 0;
}

int	ini_ray(t_ray *ray, char **arg, t_bunny_color *color)
{
  ray->color = color;
  ray->is_slowmo = 0;
  ray->nstar = 200;
  ray->star = set_star(200);
  if (ray->star == NULL)
    return (1);
  ray->map_id = 0;
  ray->color_modif = 0;
  ray->key_tab = make_key_tab();
  ray->bullets = 5;
  if (ray->key_tab == NULL)
    return (1);
  if ((ray->map_id_name = build_list_map()) == NULL)
    return (1);
  if (make_minmap_grid(ray) == 1)
    return (1);
  if (main_parse_ini(ray, arg[1], "level") == 1)
    return (1);
  if (load_sound(ray) == 1)
    return (1);
  return (0);
}
