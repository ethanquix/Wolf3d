/*
** minmap.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May 30 11:26:10 2016 Dimitri Wyzlic
** Last update	Sat Jun 04 13:42:39 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void	display_minmap(t_ray* ray)
{
  int		i;
  int		y;

  i = 0;
  while (i < 200)
    {
      y = 0;
      while (y < 200)
	{
	  if (ray->minmap[i][y] == 1)
	    my_tekpixel(i, y, ray->pix, WHITE);
	  if (ray->minmap[i][y] == 42)
	    my_tekpixel(i, y, ray->pix, RED);
	  if (ray->minmap[i][y] == 8)
	    my_tekpixel(i, y, ray->pix, GREEN);
	  if (ray->minmap[i][y] == 0)
	    my_tekpixel(i, y, ray->pix, BLUE);
	  y = y + 1;
	}
      i = i + 1;
    }
  return;
}

void	transfer_data_map(int nb, int x, int y, t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < ray->minmap_jx && i < 200)
    {
      j = 0;
      while (j < ray->minmap_jy && j < 200)
	{
	  ray->minmap[i + (x * ray->minmap_jx)][j + (y * ray->minmap_jy)] = nb;
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	data_to_map(t_ray *ray)
{
  int	x;
  int	y;

  if (ray->map_width > 200 || ray->map_height > 200 ||
      ray->map_width == 0 || ray->map_height == 0)
    return ;
  ray->minmap_jx = 200 / ray->map_height;
  ray->minmap_jy = 200 / ray->map_width;
  x = 0;
  while (x < ray->map_height)
    {
      y = 0;
      while (y < ray->map_width)
	{
	  if (ray->map_data[x][y] > 0 && ray->map_data[x][y] != 8)
	    transfer_data_map(1, x, y, ray);
	  if (ray->map_data[x][y] == 8)
	    transfer_data_map(8, x, y, ray);
	  if (ray->st_pos.posX == x && ray->st_pos.posY == y)
	    transfer_data_map(42, x, y, ray);
	  y = y + 1;
	}
      x = x + 1;
    }
}

char	*make_minmap_grid_line()
{
  char	*out;
  int	i;

  i = 0;
  out = bunny_malloc(sizeof(char) * 200);
  if (out == NULL)
    return (NULL);
  while (i < 200)
    {
      out[i] = 0;
      i = i + 1;
    }
  return (out);
}

int	make_minmap_grid(t_ray *ray)
{
  char	**out;
  int	i;

  out = bunny_malloc(sizeof(char *) * 200);
  if (out == NULL)
    return (1);
  i = 0;
  while (i < 200)
    {
      out[i] = make_minmap_grid_line();
      if (out[i] == NULL)
	return (1);
      i = i + 1;
    }
  ray->minmap = out;
  ray->minmap[0][0] = 3;
  return (0);
}
