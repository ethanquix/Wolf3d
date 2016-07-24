/*
** change_map.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri May 27 18:30:01 2016 Dimitri Wyzlic
** Last update Sat Jun  4 07:51:47 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	get_start_pos(t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  while (i < ray->map_height)
    {
      j = 0;
      while (j < ray->map_width)
	{
	  if (ray->map_data[i][j] == 42)
	    {
	      ray->st_pos.posX = i;
	      ray->st_pos.posY = j;
	      ray->map_data[i][j] = 0;
	      return (0);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

char	**build_list_map()
{
  char	**out;

  out = bunny_malloc(sizeof(char *) * 5);
  if (out == NULL)
    return (NULL);
  out[0] = "level1.ini\0";
  out[1] = "level2.ini\0";
  out[2] = "level3.ini\0";
  out[3] = "level4.ini\0";
  out[4] = "level5.ini\0";
  return (out);
}

int	change_map(t_ray *ray)
{
  ray->map_id = ray->map_id + 1;
  if (ray->map_id > 4)
    ray->map_id = 0;
  reset_minmap(ray);
  if (main_parse_ini(ray, ray->map_id_name[ray->map_id], "level") == 1)
    return (1);
  return (0);
}
